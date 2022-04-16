#include "Header.h"

void rfReadPlayers(PlayerArray player, char *fileName){
    FILE *Dosya = fopen(fileName, "r");
    if(Dosya == NULL){
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    char chunk[128];

    while(fgets(chunk, 128, Dosya) != NULL){
        char *name = strtok(chunk, "#");
        double health = atof(strtok(NULL, "#"));
        double changeRate = atof(strtok(NULL, "#"));
        int diceNumber = atoi(strtok(NULL, "\n"));
        player->PlayerInsert(player, name, health, changeRate, diceNumber);
        //PlayerInsert(player, name, health, changeRate, diceNumber);
        //printf("%s | %f | %f | %d\n", name, health, changeRate, diceNumber);
    }

    fclose(Dosya);
}

void rfReadDice(DiceArray dice, char *fileName){
    FILE *Dosya = fopen(fileName, "r");
    if(Dosya == NULL){
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    char chunk[128];

    while(fgets(chunk, 128, Dosya) != NULL){
        char *diceNumber = strtok(chunk, "\n");
        dice->DiceInsert(dice, atoi(diceNumber));
        //DiceInsert(dice, atoi(diceNumber));
        //printf("%s | %d\n", name, diceNumber);
    }

    fclose(Dosya);
}