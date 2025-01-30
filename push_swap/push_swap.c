/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:16 by plerick           #+#    #+#             */
/*   Updated: 2025/01/13 18:47:16 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ce qu'on me demande de faire :
- Avec des variables données dans un ordre aléatoire,
	je dois être capable au travers de mon programme de les trier par ordre de croissant

Limitation :
- Je n'ai le droit que à deux piles de stack A et B
- On me fournit un checker pour test le code

Ce que je dois faire pour le projet :

- Inclure GNL de Lucas dans ma Libft
	+ changer la dest du makefile après (voir pour faire appel à la libft directement dans le github (si je fais ça je dois aussi changer la dest dans le makefile de printf))

- Voir comment utiliser le checker
- Me renseigner sur les listes chainées (voir si c'et completement necessaire pour le tri)
	- Pour une liste chainée il faut d'abord savoir ce qu'est une structure
- Créer le makefile
- Créer le fichier .h
- Faire le code
	- Créer les stack A et B
	- Récupérer les variables et créer une liste chainée (voir comment faire et le principe de fonctionnement)
	- Mettre l'ensemble des variables dans le stack A pour commencer (possible de d'or et déjà les prétrier? (à voir comment le checker fonctionne))
	- Créer une fonction pour gérer les erreurs et free aux cas ou
	- Une fonction pour faire les différentes oppérations (ap etc)
	- Une fonction pour trouver le chiffre le plus petit et le plus grand
- Choisir avec quel type d'alghorytme de tri je vais utiliser
- Faire passer les variables dans l'algo
- Done

*/

#include "push_swap.h"

// void	fill_stack_a(t_stack *stack, int array)
// {
// 	// ft_printf("%d", value[5]);
// 	static int a;
// 	a = 0;
// 	t_list *new_node = malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 		return (free(new_node));
// 	new_node->value = value[0];
// 	new_node->index = a++;
// 	if (stack->top == NULL)
// 	{
// 		new_node->next = stack->top;
// 		stack->top = new_node;
// 		return;
// 	}
// }

int check_array_ok(char *argv)
{
    int	i;
	
	i = 0;
	while (argv[i] == ' ' || ft_isdigit(argv[i]) == 1 || argv[i] == '\0')
	{
        if (argv[i] == '\0')
            return (1);
        i++;
    }
	return(0);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
}

int	main(int argc, char *argv[])
{
	int	array_size;
	int	check_array;
	if (argc != 2)
		return (0);
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	check_array = check_array_ok(argv[1]);
	if (check_array == 0)
		return (write(1, "error\n", 6));
	array_size = calc_array_size(argv[1]);
	/*
	int	array[array_size];

	// Avec la taille de l'array et l'array init, possible de le remplir avec split, rencontre un nombre, le atoi, le place à en dernier dans l'array et remonte pour les avoir dans le sens inverse > quand on va file le stack alors seulement on va suiivre l'array

	fill_stack_a(&stack_a, array);

	print_stack(&stack_a);
//	ft_printf("%d\n", a[1]);
*/
	printf("%d\n", array_size);
	return (0);
}