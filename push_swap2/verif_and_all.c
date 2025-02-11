
#include "push_swap.h"

int verif_and_all(int argc, char *argv[])
{
    // t_stack a;

    if (argc < 2)
        exit(0);
	// if (argc == 2)
	//     a = with_split(argc, argv);
	else 
        if (nosplit(argv))
            // a = push_into_a(argv);
            printf("ok\n");
    return(1);
}