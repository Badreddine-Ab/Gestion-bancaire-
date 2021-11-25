#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct Client
{
    char CIN[50];
    char Nom[50];
    char Prenom[50];
    float Montant;
};
typedef struct Client CLT;
CLT table[100];
int n;
void *Retrait(CLT comptes[], int n, float retrait, char *cin);
void AffiDesParChiffre(CLT comptes[], int n, float chifre);
void Fidelisation(CLT comptes[], int n);
void TrieDescendant(CLT comptes[], int n);
void *Depot(CLT comptes[], int n, float Depot, char *cin);
void Affichage(CLT comptes[], int n);
void TrieAscendant(CLT comptes[], int n);
void createanaccount(CLT comptes[], int n);
char *search(CLT comptes[], int n, char *cin);
int main()
{
    int choix;
back:
    do
    {

        printf("****************************MENU****************************\n");
        printf("***********veuillez choisir entre 1 et 6 :  **************\n");
        printf("1-Introduire un compte bancaire.\n2-Introduire plusieurs comptes bancaires\n3-Operations\n4-Affichage\n5-Fidelisation\n6-Quitter lapplication\n");
        scanf("%d", &choix);
        switch (choix)
        {
            
        case 1:
        {
            printf("****************************INTRODUIRE UN COMPTE BANCAIRE****************************\n");
            int l;
            n = 1;
            createanaccount(table, n);
            system("cls");
            printf("***********votre compte a ete cree avec succes***********\n");
            Affichage(table, n);
            printf("***********appuyez sur 0 pour revenir au menu principal*********** \n");
            scanf("%d", &l);
            if (l == 0)
            {
                system("cls");
                goto back;
            }
            break;
        }
         
        case 2:
        {
            int rtrn;
            printf("****************************INTRODUIRE PLUSIEURS COMPTES BANCAIRES****************************\n");
            printf("entrer le nombre de comptes : \n");
            scanf("%d", &n);
            createanaccount(table, n);
            system("cls");
            printf(" creation terminee \n");
            Affichage(table, n);
             printf("***********appuyez sur 0 pour revenir au menu principal*********** \n");
            scanf("%d", &rtrn);
            if (rtrn == 0)
            {
                system("cls");
                goto back;
            }
            break;
        }
        case 3:
    
            {
                int choise;
            operation:
                system("cls");
                printf("****************************OPERATIONS**************************** \n\n");
                printf(" 1-Retrait \n2  -   Depot \n3  -   Menu Principale  \n -Entrer Votre Choix \n");
                scanf("%d", &choise);
                switch (choise)
                {
                case 1:
                {
                    system("cls");
                    printf("***********Retrait*********** \n\n");
                    char cin[50];
                    float retrait;
                    int v;
                    printf("Entrer CIN  \n ");
                    scanf("%s", cin);
                    printf("combien voulez-vous retirer \n");
                    scanf("%f", &retrait);
                    Retrait(table, 100, retrait, cin);
                    printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                    scanf("%d", &v);
                    if (v == 0)
                    {
                        system("cls");
                        goto back;
                    }

                    break;
                }
                   
                case 2:
                {
                    system("cls");
                    printf("***********Depot***********  \n\n");
                    char cin[50];
                    float depot;
                    int v;
                    printf("Entrer CIN  \n ");
                    scanf("%s", cin);
                    printf("combien voulez-vous déposer \n");
                    scanf("%f", &depot);
                    Depot(table, 100, depot, cin);
                    printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                    scanf("%d", &v);
                    if (v == 0)
                    {
                        system("cls");
                        goto back;
                    }

                    break;
                }
                case 3:
                {
                    system("cls");
                    goto back;
                    break;
                }
                default:
                {
                    printf("Entrer un nombre entre 1 et 3 \n");
                    goto operation;
                    break;
                }
                }
                break;
            }
         
        case 4:
        {
            int choix3;
        affiche:
            system("cls");
            printf("****************************Affichage****************************\n");
            printf(" 1- Ordre Ascendant \n2 -   Order Descendant  \n3 -Order Descendant par un chifre  \n4 -Order Descendant par un chifre  \n5 -Recherche Par CIN   \n6  -  Menu Principale  \n \n");
            printf("Entrer votre Choix : \t");
            scanf("%d", &choix3);
            switch (choix3)
            {
        
            case 1:
            {
                system("cls");
                printf("***********Ordre Ascendant*********** \n\n");
                TrieAscendant(table, n);
                int v;
                printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto back;
                }

                break;
            }
          
            case 2:
            {
                system("cls");
                printf("***********trie  Order Descendant***********\n\n");
                TrieDescendant(table, n);
                int v;
                printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto back;
                }
                break;
            }
            case 3:
            {
                printf("***********trie  Order Ascendant  superieur  un chifre***********\n\n");
                float chifre;
                printf("entrer le chifre \n");
                scanf("%f", &chifre);
                int i, taille= 0;
                CLT temp[100];
                for (i = 0; i < n; i++)
                {
                    if (table[i].Montant > chifre)
                    {
                        temp[taille] = table[i];
                        taille++;
                    }
                }
                TrieAscendant(temp, taille); 

                int r;
                printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                scanf("%d", &r);
                if (r == 0)
                {
                    system("cls");
                    goto back;
                }
                break;
            }
            case 4:
            {
                float chifre;
                printf("entrer le chifre \n");
                scanf("%f", &chifre);
                int i, k = 0;
                CLT temp[100];
                for (i = 0; i < n; i++)
                {
                    if (table[i].Montant > chifre)
                    {
                        temp[k] = table[i];
                        k++;
                    }
                }
                TrieDescendant(temp, k);

                int v;
                printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto back;
                }
                break;
            }
          
            case 5:
            {
                char c[50];
                int r;
                char *nom;
                printf("***********Recherche Par CIN***********\n\n");
                printf(" - Entrer  le CIN \n");
                scanf("%s", c);
                nom = search(table, 100, c);
                if (nom == NULL)
                {
                    printf(" cet identifiant ne correspond à aucun compte \n  ");
                }
                else
                {
                    printf(" \n - nom : %s  \n- num : %s   \n", nom, c);
                }
                printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
                scanf("%d", &r);
                if (r == 0)
                {
                    system("cls");
                    goto back;
                }
                break;
            }
            case 6:
            {
                system("cls");
                goto back;
                break;
            }
            default:
            {
                printf("choix est entre 1 et 6 \n");
                goto affiche;
                break;
            }
            }
            break;
        }

      
        case 5:
        {
            printf("****************************FIDELISATION****************************");
            Fidelisation(table, n);
            int v;
            printf("***********appuyez sur 0 pour revenir au menu principal***********\n");
            scanf("%d", &v);
            if (v == 0)
            {
                system("cls");
                goto back;
            }

            break;
        }
        case 6:
        {
            system("cls");
            printf("****************************QUITTER L'APPLICATION****************************\n");
            break;
        }
        }

    } while (choix < 1 || choix > 6);
    return 0;
}


void createanaccount(CLT comptes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
       
        printf(" \n\n\nEntrer CIN : \t ");
        scanf("%s", comptes[i].CIN);
        printf("Entrer le Nom  : \t ");
        scanf("%s", comptes[i].Nom);
        printf("Entrer le Prenom : \t ");
        scanf("%s", comptes[i].Prenom);
        printf("Entrer Montant : \t ");
        scanf("%f", &comptes[i].Montant);
        
    }
}
void Affichage(CLT comptes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        
        printf("- CIN : %s \n ", comptes[i].CIN);

        printf("- le Nom %s  : \n ", comptes[i].Nom);

        printf("- le Prenom : %s \n ", comptes[i].Prenom);

        printf("- Montant %f: \n\n\n ", comptes[i].Montant);
   
    }
}
char *search(CLT comptes[], int n, char *cin)
{
    int i = 0;
    while (i <= n - 1)
    {
        if (strcmp(comptes[i].CIN, cin) == 0)
        {
            return comptes[i].Nom;
        }
        i++;
    }
    return NULL;
}
void *Depot(CLT comptes[], int n, float Depot, char *cin)
{
    int i;
    int existe = 0;

    for (i = 0; i < n; i++)
    {
        if (strcmp(cin, comptes[i].CIN) == 0)
        {
             existe = 1;
            float m = comptes[i].Montant;
            comptes[i].Montant += Depot;
            system("cls");
            printf(" %s - %s\n ", comptes[i].Prenom, comptes[i].Nom);
            printf(" %.2f DH +%.2f DH =%.2f \n\n", m, Depot, comptes[i].Montant);
            break;
        }
    }
    if (existe == 0)
    {
        printf("n'existe pas \n");
    }
}
void *Retrait(CLT comptes[], int n, float retrait, char *cin)
{
    int i;
    int existe = 0;
    for (i = 0; i < n; i++)
    {
        if (strcmp(cin, comptes[i].CIN) == 0)
        {
            existe = 1;
            if (retrait > comptes[i].Montant)
            {
                printf("\n impossible  %.2f\n", retrait);
                break;
            }
            float m = comptes[i].Montant;
            comptes[i].Montant -= retrait;
            system("cls");
            printf(" %s - %s\n ", comptes[i].Prenom, comptes[i].Nom);

            printf(" %.2f DH -%.2f DH =%.2f \n\n", m, retrait, comptes[i].Montant);
        }
    }
    if (existe == 0)
    {
        printf(" n'existe pas \n");
    }
}
void TrieAscendant(CLT comptes[], int n)
{
    CLT temp;
    int i, echanges = 0;
    do
    {
        for (i = 0; i < n - 1; i++)
        {
            if (comptes[i].Montant > comptes[i + 1].Montant)
            {
                temp = comptes[i];
                comptes[i] = comptes[i + 1];
                comptes[i + 1] = temp;
            }
            echanges++;
        }
    } while (echanges > 0);

    Affichage(comptes, n);
}
void TrieDescendant(CLT comptes[], int n)
{
    CLT temp;
    int i, echanges = 0;
    do
    {
        for (i = 0; i < n - 1; i++)
        {
            if (comptes[i].Montant < comptes[i + 1].Montant)
            {
                temp = comptes[i];
                comptes[i] = comptes[i + 1];
                comptes[i + 1] = temp;
            }
            echanges++;
        }
    } while (echanges > 0);

    Affichage(comptes, n);
}
void Fidelisation(CLT comptes[], int n)
{
    int i;
    TrieDescendant(comptes, n);
    for (i = 0; i < 3; i++)
    {
        comptes[i].Montant = comptes[i].Montant * 1.013;
    }
    system("cls");
    Affichage(comptes, 3);
}
