#include "menu.h"

void free_population(Population pop) {
    for (int i=0; i<pop.nb_personne; i++)
        free(pop.tab_personne[i]);
    free(pop.tab_personne);
}

int main() {
    Population pop = read_csv("../resources/10000.csv");
    linkPopulation(pop);
    menu(pop);
    free_population(pop);
    return 0;
}
