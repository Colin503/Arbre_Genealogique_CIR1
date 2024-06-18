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
    fichePath(path,pop.tab_personne[4724]);
    exportAncestorHTML(pop,pop.tab_personne[4724],path);
    //exportFratrieHTML(pop,pop.tab_personne[4724],path);
    free_population(pop);
    return 0;
}
