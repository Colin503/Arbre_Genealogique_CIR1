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

Person** ancetre(Population p,Person* humain) {
    Person** tab_ancetre= malloc(7* sizeof(Person*)); //7 cases car on se limites à 2 générations pour l'instant
    tab_ancetre[0]=humain;
    tab_ancetre[1]=humain->p_father;
    tab_ancetre[2]=humain->p_mother;
    tab_ancetre[3]=humain->p_father->p_father;
    tab_ancetre[4]=humain->p_father->p_mother;
    tab_ancetre[5]=humain->p_mother->p_father;
    tab_ancetre[6]=humain->p_mother->p_mother;

    /*for (int i=0;i<p.nb_personne;i++) {
        if (p.tab_personne[i]->id == humain->father_id)  //id --> pere humain
            tab_ancetre[1] = p.tab_personne[i];
        if (p.tab_personne[i]->id == humain->mother_id) //id --> mere humain
            tab_ancetre[2] = p.tab_personne[i];
        if (tab_ancetre[1]!=NULL) {
            if (p.tab_personne[i]->id == tab_ancetre[1]->father_id)  //id --> pere du pere humain
                tab_ancetre[3] = p.tab_personne[i];
            if (p.tab_personne[i]->id == tab_ancetre[1]->mother_id) //id --> mere du pere humain
                tab_ancetre[4] = p.tab_personne[i];
        }
        if (tab_ancetre[2]!=NULL) {
            if (p.tab_personne[i]->id == tab_ancetre[2]->father_id) // id --> pere de la mere humain
                tab_ancetre[5] = p.tab_personne[i];
            if (p.tab_personne[i]->id == tab_ancetre[2]->mother_id) //id --> mere de la mere humain
                tab_ancetre[6] = p.tab_personne[i];
        }
    }*/
    return tab_ancetre;
}
