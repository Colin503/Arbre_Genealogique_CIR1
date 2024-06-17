//
// Created by colin on 14/06/2024.
//

#ifndef S2_PROJETFINAL_ADVANCED_H
#define S2_PROJETFINAL_ADVANCED_H
#include "filemanager.h"


typedef struct s_noeud Noeud;
struct s_noeud {
    //Noeud fg;
    //Noeud fd;
};


typedef struct arbre_binaire {
    Noeud noyau;

}Arbre;

Person** fratrie(Population p,Person* humain);
Person** ancestorsPersons(Population t, Person* p) ;


#endif //S2_PROJETFINAL_ADVANCED_H
