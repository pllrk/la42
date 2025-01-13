#include "libft.h"

int    main(void)
{
    int    d = 5;
    int    c = 'g';
    char s[] = "Haha";
    int    iii = 455;

    int    count1 = 0;
    int    count2 = 0;
    unsigned int    base1 = 255;
    unsigned int    base2 = 4095;

    int    nbptr = 1;
    int    *ptr = &nbptr;

    unsigned int    l = 4;

    count1 = ft_printf("c : %c\ns : %s\nd : %d\npourcent: %%\ni : %i\nx : %x\nX : %X\n p : %p\nu : %u\n", c, s, d, iii, base1, base2, ptr, l);
    ft_printf("Mon printf : %i\n\n", count1);
    count2 = printf("c : %c\ns : %s\nd : %d\npourcent : %%\ni : %i\nx : %x\nX : %X\np : %p\nu : %u\n", c, s, d, iii, base1, base2, ptr, l);
    printf("Vrai printf : %i\n", count2);
//    count = ft_printf("%x\n%X\n", base1, base2);
//    count = printf("\n%x\n%X\n", base1, base2);
    return (count1);
}
