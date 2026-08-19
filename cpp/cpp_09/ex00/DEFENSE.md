# ex00 — defense notes

## Prerequisites checklist

| Item | Status |
|---|---|
| Compiles with `c++ -Wall -Wextra -Werror` | yes, zero warnings |
| Compiles with `-std=c++98` | yes, the flag is in the Makefile |
| No function implemented in a header (templates excepted) | `BitcoinExchange.hpp` contains only declarations |
| Makefile rules `$(NAME) all clean fclean re` | present |
| Makefile does not relink | `make` twice → "Nothing to be done" |
| No C functions (`*alloc`, `*printf`, `free`) | none used |
| No external library / no post-98 features | only `<map> <string> <exception> <fstream> <sstream> <iostream> <cctype> <cstdlib>` |
| At least one container | `std::map<std::string, float>` |

`std::atoi` is from `<cstdlib>`, which is standard C++98 — it is not on the forbidden
list (that list is `*alloc`, `*printf`, `free`). If an evaluator objects anyway, it is
replaceable by a `std::stringstream` in thirty seconds.

---

## "Why this container and not another?"

This is the question that stops the evaluation. The answer has three layers — give
the first, and the other two if pushed.

**1. The operation the exercise actually needs.**
The core requirement is not "look up a date". It is: *given a date that may not be in
the database, find the closest date below it.* That is a nearest-neighbour query on an
ordered set. So I need a container that keeps its keys **sorted**, and that can answer
"first key not less than X" without a linear scan.

**2. Why `std::map` specifically.**
- `std::map` is a balanced binary search tree, so keys are always in sorted order and
  `lower_bound` runs in **O(log n)**. The database has ~3500 rows; a linear search
  would work but would be the wrong tool.
- The data is naturally a **key → value** association (date → rate), which is exactly
  what a map models. A `std::set` would force me to store a pair and write a custom
  comparator for no gain.
- **The decisive detail:** ISO 8601 dates (`YYYY-MM-DD`) are fixed-width and
  zero-padded, so their **lexicographic order is identical to their chronological
  order**. `"2011-01-09" < "2011-01-11"` is true both as strings and as dates.
  That means the map's default `std::less<std::string>` already sorts chronologically —
  no custom comparator, no date-to-integer conversion. This is the single best point to
  make.

**3. Why not the alternatives.**
- `std::vector` — no ordering guarantee of its own. I would have to keep it sorted
  manually and call `std::lower_bound` from `<algorithm>` on it. That works (and is
  arguably faster in practice, better cache locality), but it puts the sorting
  invariant on me instead of the container.
- `std::unordered_map` — **C++11, forbidden here.** And even if allowed it would be
  wrong: hashing destroys order, so nearest-lower-date becomes impossible without a
  full scan. Good answer to volunteer, it shows you understand the trade-off.
- `std::list` — no random access, so no binary search. Lookup degrades to O(n).
- `std::set` — ordered, but models a set of keys, not key→value pairs.

**Module cost:** `std::map` is now burned for the rest of Module 09. ex01 (RPN) and
ex02 (PmergeMe) must use different containers — `std::stack` for ex01, and two of
`vector`/`deque`/`list` for ex02.

---

## "Explain `getRate`"

```
lower_bound(date)  →  iterator to the first key that is NOT less than date  (first key >= date)
```

Four cases, and the **order of the tests matters**:

1. `it != end() && it->first == date` → exact match, use it.
2. `it == begin()` and no exact match → every key in the DB is *later* than the
   requested date. No lower date exists → return the `-1` sentinel, `main` reports it.
3. `it == end()` → every key is *earlier*. `--it` lands on the last (most recent) entry.
   Correct: that is the nearest lower date.
4. Otherwise → `lower_bound` overshot by one. `--it` gives the greatest key strictly
   below `date`.

Cases 3 and 4 are the same line of code (`--it`), which is why the function looks
shorter than this explanation.

**The classic bug:** testing `it == begin()` *before* the exact-match test, then
returning `it->second`. That returns the **upper** date — precisely what the subject
warns against. Worth mentioning that you avoided it deliberately.

---

## "Explain `parseValue`"

Two jobs deliberately kept apart:

- `parseValue` answers **"is this string a number?"** and hands back the value. No range
  check inside it.
- The **0–1000 range check lives in `main`**, on the parsed value.

Why the split: `loadDatabase` calls the same `parseValue` on `data.csv`, where real
Bitcoin rates run to ~60000. A 0–1000 clamp inside the parser would silently drop
almost every row of the database and the program would output nonsense. The 0–1000 rule
in the subject applies to the **input file only**.

Mechanics:
- `ss >> f` stops at the first character it cannot use, so `"1.2abc"` reads `1.2` and
  reports **success**. The `ss >> std::ws; if (!ss.eof())` pair is what rejects it — it
  checks nothing was left over, after allowing trailing blanks.
- The character pre-scan (digits, `.`, `+`, `-` only) rejects `inf` and `nan`, which
  some libstdc++ versions will happily read into a float.

---

## "Explain the leap year rule"

`(y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)`

Divisible by 4 is a leap year, **except** centuries, which must also be divisible by
400. So 1900 is not a leap year, 2000 is. Demonstrable live: `2011-02-29` is rejected,
`2012-02-29` is accepted.

---

## Error-handling demo (run these in front of the evaluator)

| Command | Expected |
|---|---|
| `./btc` | `Error: could not open file.` |
| `./btc nosuchfile` | `Error: could not open file.` |
| `./btc empty.txt` | `Error: empty file.` |
| `./btc .` (a directory) | `Error: empty file.` |
| `./btc errors.txt` | every line reported, **execution reaches the end of the file** |

The key point the sheet tests: **the program never stops early.** Every malformed line
prints its own message to `stderr` and the loop continues. Errors go to `stderr`,
results to `stdout`, so `./btc input.txt 2>/dev/null` shows only results — a clean way
to prove the separation.

Cases covered in `errors.txt`: missing value, missing date, no separator, scientific
notation, invalid month, `inf`, `nan`, boundary `1000` (accepted) vs `1000.1`
(rejected), `-0`, and CRLF line endings (the trim strips `\r`, so a file saved on
Windows still works — worth demonstrating, it catches a lot of people).

---

## Before the evaluation

- Directory must be named `ex00/`.
- **`data.csv` must sit next to the binary** — the default constructor uses the relative
  path `"data.csv"`, so it is resolved from the current working directory. Running from
  elsewhere gives `Error: could not open file.`
- The evaluator uses their own `input.csv`. Test with a copy that has CRLF endings and
  stray spaces around the `|` before the defense.
- Run `make re` once and check nothing warns.
