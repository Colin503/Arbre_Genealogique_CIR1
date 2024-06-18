#include "menu.h"
void free_population(Population pop) {
    for (int i=0; i<pop.nb_personne; i++)
        free(pop.tab_personne[i]);
    free(pop.tab_personne);
}
int main() {
    Population pop;
    char path_p[30];
    pop = read_csv("../10000.csv");
    linkPopulation(pop);
    fichePath_page(path_p,pop.tab_personne[4374]);
    exportAncestorHTML(pop,pop.tab_personne[4374],path_p);
    //exportFratrieHTML(pop,pop.tab_personne[9999],path_p);
    free_population(pop);
    return 0;
}
