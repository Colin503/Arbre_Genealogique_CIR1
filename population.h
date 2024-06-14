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
void linkPopulation(Population p);

}
#endif //S2_PROJETFINAL_PROJET_H
