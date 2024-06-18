//
// Created by colin on 14/06/2024.
//

#ifndef S2_PROJETFINAL_ADVANCED_H
#define S2_PROJETFINAL_ADVANCED_H
#include "filemanager.h"


Person** fratrie(Population p,Person* humain);
Person** ancestorsPersons(Population t, Person* p) ;
void ancestors_debug(Person** tab,const char* filen);
Person* oldestancertor(Population t,Person* p);


#endif //S2_PROJETFINAL_ADVANCED_H
