//
// Created by colin on 13/06/2024.
//

#include "population.h"


void insert(Population p, int key, Person* data ) {
    p.tab_personne[key]=data;
    p.nb_personne++;
}
