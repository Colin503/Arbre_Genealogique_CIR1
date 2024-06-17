//
// Created by colin on 14/06/2024.
//

#include "advanced.h"


Person** fratrie(Population p,Person* humain) {
    Person** tab_fratrie;
    tab_fratrie[0]=humain;
    int indice=1;
    for (int i=0;i<p.nb_personne;i++) {
        if (p.tab_personne[i]->father_id==humain->father_id && p.tab_personne[i]->mother_id==humain->mother_id) {
            tab_fratrie[indice]=p.tab_personne[i];
            indice++;
        }
    }
    return tab_fratrie;
}

Person** ancestorsPersons(Population t, Person* p) {
    Person** tab_ancetre= malloc(7* sizeof(Person*)); //7 cases car on se limites à 2 générations pour l'instant
    tab_ancetre[0]=p;
    tab_ancetre[1]=p->p_father;
    tab_ancetre[2]=p->p_mother;
    tab_ancetre[3]=p->p_father->p_father;
    tab_ancetre[4]=p->p_father->p_mother;
    tab_ancetre[5]=p->p_mother->p_father;
    tab_ancetre[6]=p->p_mother->p_mother;
    
    return tab_ancetre;
}
