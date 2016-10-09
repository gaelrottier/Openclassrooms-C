#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"

int sommeTableau(int tableau[], int tailleTableau)
{
    int sommeTableau = 0, i = 0;

    for(i = 0; i < tailleTableau; i++)
        {
            sommeTableau += tableau[i];
        }

    return sommeTableau;
}

double moyenneTableau(int tableau[], int tailleTableau)
{
    return sommeTableau(tableau, tailleTableau) / tailleTableau;
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
    int i = 0;

    for (i = 0; i < tailleTableau; i++)
        {
            tableauCopie[i] = tableauOriginal[i];
        }
}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax)
{
    int i = 0;

    for(i = 0; i < tailleTableau; i++)
        {
            if(tableau[i] > valeurMax)
                tableau[i] = 0;
        }
}

void ordonnerTableau(int tableau[], int tailleTableau)
{

    int i = 0, j = 0, caseTableau = 0;

    //Pour chaque case
    for(i = 0; i < tailleTableau; i++)
        {
            for(j = i + 1; j < tailleTableau; j++)
                {
                    if(tableau[i] > tableau[j])
                        {
                            caseTableau = tableau[j];
                            tableau[j] = tableau[i];
                            tableau[i] = caseTableau;
                        }
                }

        }
}

int main()
{
    int tableau[4] = {1, 2, 4, 5};

    printf("Somme : %d\n", sommeTableau(tableau, 4));
    printf("Moyenne : %lf\n", moyenneTableau(tableau, 4));

    int tableauCopie[4];

    copie(tableau, tableauCopie, 4);
    printf("Copie : %d %d %d %d\n", tableauCopie[0], tableauCopie[1], tableauCopie[2], tableauCopie[3]);

    maximumTableau(tableauCopie, 4, 2);
    printf("Maximum : %d %d %d %d\n", tableauCopie[0], tableauCopie[1], tableauCopie[2], tableauCopie[3]);

    int tableauAOrdonner[5] = {15, 81, 13, 22, 13};

    ordonnerTableau(tableauAOrdonner, 5);
    printf("Ordonner : %d %d %d %d %d\n", tableauAOrdonner[0], tableauAOrdonner[1], tableauAOrdonner[2], tableauAOrdonner[3], tableauAOrdonner[4]);

    return 0;
}
