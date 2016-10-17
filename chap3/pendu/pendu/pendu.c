#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pendu.h"

#define NB_VIES 10
#define DICT_FILENAME "dict.txt"
#define WORD_SIZE 100

int play(const char *mot, size_t motSize)
{
    int vies = NB_VIES, i, guessedRight = 0;

    char *motAffiche = malloc(sizeof(char) * motSize + 1);

    for (i = 0; i < motSize; i++)
        motAffiche[i] = '_';
    motAffiche[motSize] = '\0';

    while (vies > 0)
    {
        printf("Mot a trouver : %s\n", motAffiche);

        guessedRight = guessChar(mot, &motAffiche, motSize);

        if (guessedRight == 0)
        {
            vies--;
            printf("Rate ! Il vous reste %d vies\n", vies);
        }

        if (strcmp(mot, motAffiche) == 0)
        {
            return 1;
        }
    }

    free(motAffiche);
    printf("Vous n'avez plus de vies !\n");
    return 0;
}

int guessChar(const char* mot, char** motAffiche, size_t motSize)
{
    char guess;
    int i, guessedRight = 0;

    guess = getchar();
    guess = toupper(guess);

    while (getchar() != '\n');

    for (i = 0; i <= motSize; i++)
    {
        if (mot[i] == guess)
        {
            (*motAffiche)[i] = guess;
            guessedRight = 1;
        }
    }

    return guessedRight;
}

int loadWord(char mot[])
{
    FILE *dict = NULL;
    char *dictFile = DICT_FILENAME, currentChar;
    int nbMots = 0, randomIdx = 0, motSize = 0;

    //Chargement du dictionnaire
    fopen_s(&dict, dictFile, "r");

    if (dict == NULL)
    {
        printf("Le dictionnaire de mots n'existe pas.");
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            //Lecture du fichier
            currentChar = fgetc(dict);
            if (currentChar == '\n')
                //Comptage des lignes
                nbMots++;
        }
        while (currentChar != EOF);

        //Génération d'un index aléatoire pour choisir un mot
        randomIdx = rand() % nbMots;

        rewind(dict);

        while (randomIdx > 0)
        {
            //Lecture du fichier
            currentChar = fgetc(dict);
            if (currentChar == '\n')
                randomIdx--;
        }

        //Lecture de la ligne et assignation du mot
        fgets(mot, WORD_SIZE, dict);

        motSize = strlen(mot) -1; //Pour enlever le \n
        (*(&mot))[motSize] = '\0';

        fclose(dict);
    }

    return motSize;
}

int main()
{
    char mot[WORD_SIZE] = { 0 };
    int victoire = 0, nbLettresMot = 0;

    srand(time(NULL));

    printf("Bonjour, nous allons jouer au pendu\n");

    nbLettresMot = loadWord(&mot);

    victoire = play(&mot, nbLettresMot);

    if (victoire == 1)
    {
        printf("Victoire ! Vous avez trouve le mot %s !\n", mot);
    }
    else
    {
        printf("Dommage, vous avez perdu. Le mot etait %s\n", mot);
    }

    system("pause");

    return EXIT_SUCCESS;
}