#include "menu.h"

int main() {
    Population pop;
    pop = read_csv("../resources/10000.csv");
    linkPopulation(pop);
    Person** tab_fratrie= fratrie(pop,pop.tab_personne[4576]);
    affichage_tableau(tab_fratrie);
    free(tab_fratrie);
    return 0;
}
