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

void	add_last(t_list **stack, t_list *new_node)
{
	t_list *tmp;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_node;
		new_node->previous = tmp;
	}
}

void	fill_stack_a(t_list **stack, int argv, int i)
{
	t_list *new_node;
	t_list *last_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (free(new_node));
	new_node->value = argv;
	new_node->index = i;
	add_last(stack, new_node);
	//should probably free new_node here ?
	
	/*https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s*/
}

void	init_a(char **argv, int argc, t_list **a)
{
	int		*chiffres;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while (argv[i + 1] != NULL)
	{
		// t_list *a;
		{
			chiffres[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		free_all(argv, argc);
		while (i > 0)
		{
			fill_stack_a(a, chiffres[i], i);
			i--;
		}
	}
}

// void	init_list(t_list *stack)
// {
// 	stack->top = NULL;
// }

int	main(int argc, char *argv[])
{

	t_list *a;
	// t_list *b;

	int		i;
	a = NULL;
	// b = NULL;
	i = 0;
	if (i != (verif_and_all(argc, argv)))
		exit(0);
	// init_list(a);
	// init_list(b);
	init_a(argv, argc, &a);
	



	/* ici il faut que je split si c'est dans "", pour après :
		- faire atoi sur les chiffre 1 par 1 pour les placer dans a, je veux les placer par ordre inverse, comme ça ils sont 
		deja dans le bon ordre.
		Ou, je peux les mettre comme ça et utilise après une commande donnée (sa) pour inverser l'ordre*/


	// j = 0;
	// while (j < i)
	// {
	// 	printf("The array : %d\n", array_int[j]);
	// 	j++;
	// }
	
	// free(array_int);
/*
	// Avec la taille de l'array et l'array init, possible de le remplir avec split, rencontre un nombre, le atoi, le place à en dernier dans l'array et remonte pour les avoir dans le sens inverse > quand on va file le stack alors seulement on va suiivre l'array

	fill_stack_a(&stack_a, array);

	print_list(&stack_a);
//	ft_printf("%d\n", a[1]);
*/
	// printf("Array size = %d\n", array_size);
	return (0);
}