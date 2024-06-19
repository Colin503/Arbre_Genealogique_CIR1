#ifndef PROJET_FIN_ADVANCED_H
#define PROJET_FIN_ADVANCED_H

#include "filemanager.h"

typedef struct fratrie{
    Person** tab;
    int taille;
}Fratrie;

Fratrie fratrie(Population p,Person* humain);
Person** ancestorsPersons(Person* humain);
Person* oldestancertor(Person* p);
void ancestors_debug(Person** tab,const char* filen);
void fratrie_debug(Person** tab,const char* filen);

#endif //PROJET_FIN_ADVANCED_H
