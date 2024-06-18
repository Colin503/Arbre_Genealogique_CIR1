#include "menu.h"
void free_population(Population pop) {
    for (int i=0; i<pop.nb_personne; i++)
        free(pop.tab_personne[i]);
    free(pop.tab_personne);
}
int main() {
    Population pop;
    char path[30];
    pop = read_csv("../10000.csv");
    linkPopulation(pop);
    Person** tab_fratrie= fratrie(pop,pop.tab_personne[4576]);
    fichePath(path,pop.tab_personne[4576]);
    exportPersonHTML(pop,pop.tab_personne[4576],path);
    affichage_tableau(tab_fratrie);
    free(tab_fratrie);
    return 0;
}
