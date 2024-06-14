//
// Created by colin on 13/06/2024.
//

#ifndef S2_PROJETFINAL_PROJET_H
#define S2_PROJETFINAL_PROJET_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "person.h"

typedef struct pop{
    Person** tab_personne;
    int nb_personne;
}Population;

void insert(Population* p, int key, Person* data );

#endif //S2_PROJETFINAL_PROJET_H
