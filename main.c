#include <stdio.h>
#include <stdlib.h>

// Fonction de calcul de la somme des pizzas
int calcul_prix(int somme, int prix_unitaire)
{
    return somme + prix_unitaire;
}

int main()
{
    //BDD de pizza
    //Varietes de pizzas
    char pizza1[50] = {"4 fromages"};
    char pizza2[50] = {"napolitaines"};
    char pizza3[50] = {"Margherita"};
    char pizza4[50] = {"Saumona"};
    char pizza5[50] = {"vegetarienne"};

    //Table des prix
    int prix_pizza[] = {10,12,11,15,16};

    //Menu visuelle
    printf("Bienvenue chez pizza'trobon\n\n");
    printf("Voici notre menu :\n\n");

    printf(" 1. Pizza %s, %d euros \n", pizza1, prix_pizza[0]);
    printf(" 2. Pizza %s, %d euros \n", pizza2, prix_pizza[1]);
    printf(" 3. Pizza %s, %d euros \n", pizza3, prix_pizza[2]);
    printf(" 4. Pizza %s, %d euros \n", pizza4, prix_pizza[3]);
    printf(" 5. Pizza %s, %d euros \n\n", pizza5, prix_pizza[4]);


    int choix_pizza = 0;
    char plus_de_pizza;
    int somme = 0;
    int numChoix[500];
    int i = 0;
    int y = 0;
    do{
        printf("Quel est votre choix ? :\n");
        scanf("%d", &choix_pizza);

        // gérer le cas : si le choix n'est pas compris entre 1 et 5, demander de resaisir
        while (choix_pizza>5 || choix_pizza<1)
        {
            printf("Je ne comprends pas votre choix, veuillez resaisir \n:");
            scanf("%d", &choix_pizza);
        }


        switch (choix_pizza){
            case 1:
                printf("Pizza %s, %d euros \n", pizza1, prix_pizza[choix_pizza-1]);
                somme = calcul_prix(somme, prix_pizza[choix_pizza-1]); //appel de la fonction pour calculer le total de la commande
                numChoix[y] = choix_pizza;
                y++;
                break;
            case 2:
                printf("Pizza %s, %d euros \n", pizza2, prix_pizza[choix_pizza-1]);
                somme = calcul_prix(somme, prix_pizza[choix_pizza-1]);
                numChoix [y] = choix_pizza;
                y++;
                break;
            case 3:
                printf("Pizza %s, %d euros \n", pizza3, prix_pizza[choix_pizza-1]);
                somme = calcul_prix(somme, prix_pizza[choix_pizza-1]);
                numChoix [y] = choix_pizza;
                y++;
                break;
            case 4:
                printf("Pizza %s, %d euros \n", pizza4, prix_pizza[choix_pizza-1]);
                somme = calcul_prix(somme, prix_pizza[choix_pizza-1]);
                numChoix [y] = choix_pizza;
                y++;
                break;
            case 5:
                printf("Pizza %s, %d euros \n", pizza5, prix_pizza[choix_pizza-1]);
                somme = calcul_prix(somme, prix_pizza[choix_pizza-1]);
                numChoix [y] = choix_pizza;
                y++;
                break;
        }

        numChoix[y]=0;
        printf("Souhaitez-vous commander une autre pizza ? (o/n) \n");
        scanf("%s", &plus_de_pizza);
    }while(plus_de_pizza == 'o');

    printf("le prix total est de : %d euros\n\n", somme);

    //Création d'une facture dans un fichier externe

    y=0;
    FILE* fichier = NULL;

    fichier = fopen("facture.txt", "w");

    if (fichier != NULL)
    {
        fputs("=== Facture ===\n\n", fichier);

        while(numChoix[y]!=0)
        {

            if (numChoix[y]==1)
            {
                fprintf(fichier, "Pizza %s, %d euros \n", pizza1, prix_pizza[0]);
                y++;
            }else if (numChoix[y]==2)
            {
                fprintf(fichier, "Pizza %s, %d euros \n", pizza2, prix_pizza[1]);
                y++;
            }else if (numChoix[y]==3)
            {
                fprintf(fichier, "Pizza %s, %d euros \n", pizza3, prix_pizza[2]);
                y++;
            }else if (numChoix[y]==4) {
                fprintf(fichier, "Pizza %s, %d euros \n", pizza4, prix_pizza[3]);
                y++;
            }else if (numChoix[y]==5){
                fprintf(fichier, "Pizza %s, %d euros \n", pizza5, prix_pizza[4]);
                y++;
            }
        }

    }
        fprintf(fichier, "\nTotal : %d euros \n\nMerci pour votre commande", somme);
        fclose(fichier);

return 0;
}
