//
// Created by colin on 14/06/2024.
//

#ifndef S2_PROJETFINAL_ADVANCED_H
#define S2_PROJETFINAL_ADVANCED_H
#include "filemanager.h"

typedef struct fratrie{
    Person** tab;
    int taille;
}Fratrie;

Fratrie fratrie(Population p,Person* humain);
Person** ancestorsPersons(Population p,Person* humain);
void ancestors_debug(Person** tab,const char* filen);
void fratrie_debug(Person** tab,const char* filen);


#endif //S2_PROJETFINAL_ADVANCED_H
