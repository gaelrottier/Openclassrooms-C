#include <stdlib.h>
#include "main2.c"

typedef struct Menu Menu;
struct Menu {
    int menuId;
    char menuLibelle[100];
};

int main() {

    int choixMenu, i;

    Menu menus[4];
    Menu menu1 = {1, "Royal Cheese"};
    Menu menu2 = {2, "Mc Deluxe"};
    Menu menu3 = {3, "Mc Bacon"};
    Menu menu4 = {4, "Big Mac"};

    menus[0] = menu1;
    menus[1] = menu2;
    menus[2] = menu3;
    menus[3] = menu4;

    printf("=== Menu ===\n");
    for(i=0; i <= 3; i++) {
        printf("%d. %s\n", menus[i].menuId, menus[i].menuLibelle);
    }
    printf("Votre choix ? ");

    scanf("%d", &choixMenu);

    for(i=0; i <= 3; i++) {
        Menu menu = menus[i];
        if(choixMenu == menu.menuId) {
            printf("Vous avez choisi le menu %d. %s !", menu.menuId, menu.menuLibelle);
            break;
        }
    }
}
