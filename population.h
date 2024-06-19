#ifndef PROJET_FIN_POPULATION_H
#define PROJET_FIN_POPULATION_H

#include "person.h"

typedef struct pop{
    Person** tab_personne;
    int nb_personne;
}Population;

void insert(Population* p, int key, Person* data );
void linkPopulation(Population p);

#endif //PROJET_FIN_POPULATION_H
