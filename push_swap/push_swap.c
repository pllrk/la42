
/*
Ce qu'on me demande de faire :
- Avec des variables données dans un ordre aléatoire, je dois être capable au travers de mon programme de les trier par ordre de croissant

Limitation :
- Je n'ai le droit que à deux piles de stack A et B
- On me fournit un checker pour test le code 

Ce que je dois faire pour le projet :

- Inclure GNL de Lucas dans ma Libft + changer la dest du makefile après (voir pour faire appel à la libft directement dans le github (si je fais ça je dois aussi changer la dest dans le makefile de printf))

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

int main(void)
{
	int a[] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 1};

    printf("%d\n", a[1]);
    return (0);
}