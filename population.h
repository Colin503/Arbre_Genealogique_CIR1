#ifndef PROJETCIR1_RENNES_GROUPE4_POPULATION_H
#define PROJETCIR1_RENNES_GROUPE4_POPULATION_H

#include "person.h"

typedef struct pop{
    Person** tab_personne;
    int nb_personne;
}Population;

void insert(Population* p, int key, Person* data );
void linkPopulation(Population p);

#endif //PROJETCIR1_RENNES_GROUPE4_POPULATION_H
