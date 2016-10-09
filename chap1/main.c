#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int MIN = 1;

int main() {
    srand(time(NULL));

    play();

    return 0;
}

int initGame() {
    int nbPlayers, nombreMystere;
    bool nbPlayersOk = true;

    system("cls"); //Pour effacer l'écran

    printf("Bienvenue !\n");

    do {
        nbPlayersOk = true;

        //Sélection du nombre de joueurs
        printf("Voulez-vous jouer seul ou a deux ?");
        scanf("%d", &nbPlayers);

        switch(nbPlayers) {
            case 1:
                //Génération du nombre
                nombreMystere = selectDifficulte();
                break;
            case 2:
                //Saisie du nombre
                system("cls");
                printf("------------------------------------------------------------\n");
                printf("--------- Veuillez saisir un nombre a faire deviner --------\n");
                printf("------------------------------------------------------------\n");

                scanf("%d", &nombreMystere);
                break;
            default:
                printf("Ce jeu se joue a 1 ou 2 joueurs.\n");
                nbPlayersOk = false;
                break;

        }
    } while(!nbPlayersOk);

    system("cls");

    return nombreMystere;
}

void play() {
    bool restart;
    int nbEssais, nombreMystere, guess;
    signed char restartReponse[1];

    do {
        //Récupération nombre mstère
        nombreMystere = initGame();
        nbEssais = 0;

        printf("Bienvenue, essayez de trouver le nombre !\n");

        do {
            printf("Quel est le nombre ?\n");
            scanf("%d", &guess);

            if(guess > nombreMystere)
                printf("C'est moins ! ");
            else if (guess < nombreMystere)
                printf("C'est plus ! ");

            nbEssais++;
        } while(guess != nombreMystere);

        printf("Bravo, vous avez trouve en %d essais !", nbEssais);

        printf("Voulez-vous recommencer (o)?");
        scanf("%s", restartReponse);

    } while(!strcmp(restartReponse, "o"));
}

//Choix du niveau de difficulte
int selectDifficulte() {
    int niveauDifficulte, maxNumber;
    bool niveauDifficulteOk;

    do {
        niveauDifficulteOk = true;

        printf("Veuillez choisir un niveau de difficulte :\n");
        printf("1. entre 1 et 100\n");
        printf("2. entre 1 et 1000\n");
        printf("3. entre 1 et 10000\n");

        scanf("%d", &niveauDifficulte);

        switch(niveauDifficulte) {
            case 1 :
                maxNumber = 100;
                break;
            case 2:
                maxNumber = 1000;
                break;
            case 3:
                maxNumber = 10000;
                break;
            default:
                printf("Veuillez choisir un des 3 niveaux de difficulte.\n");
                niveauDifficulteOk = false;
                break;
        }

    } while(!niveauDifficulteOk);

    //Génération du nombre
    return (rand() % (maxNumber - MIN + 1)) + MIN;
}
