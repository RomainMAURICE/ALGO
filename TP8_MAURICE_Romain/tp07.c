#include "tree.h"
#include "visualtree.h"
#include <stdio.h>


int main() {


  /*node *t = scan_tree();
  insert_bst(t, 9);

  write_tree(t);

  printf("%d\n", count_nodes(t));
  printf("%d\n", count_leaves(t));
  printf("%d\n", count_only_children(t));
  printf("%d\n", height(t));

  int i;
  for (i = 0; i < 100; i++)
    if (find_bst(t, i))
        printf("%d ", i);
  printf("\n");


  free_tree(t);*/

  int quit = 0;
  node* t = NULL;

  while(quit==0){
    printf("\n");
    printf("Appuyer sur 1 pour afficher les différents choix possibles\n");
    printf("Menu : ");

    char ch;
    scanf(" %c", &ch);

    switch(ch){

      case '1':
        printf("1 : afficher les choix possibles\n");
        printf("2 : construire un nouvel arbre à partir d'une suite d'entiers (par exemple en tapant `s 7 5 0 0 12 10 0 0 0')\n");
        printf("3 : construire un arbre avec un nombre d'entiers aléatoires (par exemple en tapant `a 500')\n");
        printf("4 : insérer un élément dans l'arbre (par exemple en tapant `i 18')\n");
        printf("5 : faire une recherche dans l'arbre (par exemple en tapant `f 42')\n");
        printf("6 : afficher les entiers de l'arbre triés en ordre croissant (parcours en ordre infixe de l'arbre)\n");
        printf("7 : terminer le programme\n");
        printf("8 : supprimer un élément de l'arbre\n");
        break;

      case '2':
        printf("entrez une suite de nombre pour créer un arbres : ");
        t = scan_tree();
        printf("arbre crée\n");
        write_tree(t);
        break;

      case '3':

        int z;
        printf("entrez un nombre pour générer un arbre aléatoire : ");
        scanf("%d", &z);
        t = random_tree(z);
        write_tree(t);

        break;

      case '4':
        int x;
        printf("veuillez insérer une valeur dans l'arbre : ");
        scanf("%d", &x);

        if(t)
          insert_bst(t, x);
        else  
          printf("aucun arbre n'a été crée\n");
        write_tree(t);
        break;

      case '5':
      int y;
      printf("entrez une valeur à chercher dans l'arbre : ");
      scanf("%d", &y);

      if(find_bst(t, y))
        printf("Cette valeur existe dans l'arbre\n");
      else
        printf("Cette valeur n'existe pas dans l'arbre\n");
      break;

      case '6':
        if(t)
          display_infix(t);
        else
          printf("aucun arbre n'a été crée\n");
        break;

      case '7':
        if(t)
          free_tree(t);
        printf("fin\n");
        quit=1;
        break;

      case '8':
        int w;
        printf("entrez un entier à supprimer de l'arbre : ");
        scanf("%d", &w);
        
        write_tree(t);
        break;

      default:
        printf("valeur non valide\n");
    }
  }

  /*node* t2 = random_tree(7500000);
  node* t3 = random_tree_ordered(60000);*/

  return 0;
}