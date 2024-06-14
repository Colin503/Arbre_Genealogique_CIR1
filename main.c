#include "population.h"

int main() {
       Population pop;
    pop = read_csv("../40.csv");
    linkPopulation(pop);
    Person** tab = fratrie(pop, pop.tab_personne[26]);
    for(int i=0;i<3;i++)
        printf("%d\n",tab[i]->id);
    return 0;
}
