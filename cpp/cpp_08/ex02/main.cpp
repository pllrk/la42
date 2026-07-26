
#include <iostream>
#include <list>

#include "MutantStack.hpp"

//first

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Top of std::stack copied from MutantStack: "
	          << s.top() << std::endl;
	return 0;
}

//second

/*
int main()
{
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    
    while (it != ite)
	{
        std::cout << *it << std::endl;
        ++it;
    }
    return 0;
}
*/

/*
static void print_section(const char *title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    MutantStack<int> stack;

    print_section("Stack basics");
    stack.push(5);
    stack.push(17);
    std::cout << "Top element after two pushes: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Size after removing the top: " << stack.size() << std::endl;

    print_section("Iterator walk");
    stack.push(3);
    stack.push(5);
    stack.push(737);
    stack.push(0);

    MutantStack<int>::iterator first = stack.begin();
    MutantStack<int>::iterator last = stack.end();
    ++first;
    --first;
    while (first != last)
    {
        std::cout << *first << std::endl;
        ++first;
    }

    print_section("Copy constructor");
    MutantStack<int> copied(stack);
    copied.push(42);
    std::cout << "Original size: " << stack.size()
              << " | Copied size: " << copied.size() << std::endl;

    print_section("Assignment operator");
    MutantStack<int> assigned;
    assigned = stack;
    assigned.push(99);
    std::cout << "Original size: " << stack.size()
              << " | Assigned size: " << assigned.size() << std::endl;

    print_section("Const iteration");
    const MutantStack<int> &const_stack = stack;
    for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
        std::cout << *it << std::endl;

    print_section("List comparison");
    std::list<int> list;
    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
*/