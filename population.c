//
// Created by colin on 13/06/2024.
//

#include "population.h"


void insert(Population* p, int key, Person* data ) {
    p->tab_personne[key]=data;
    p->nb_personne++;
}

void linkPopulation(Population p){
    int nb_pers=p.nb_personne;
    Person** tab_id= malloc(nb_pers* sizeof(Person*));
    for(int i=0;i<nb_pers;i++) {
        tab_id[i] = NULL;
        tab_id[p.tab_personne[i]->id] = p.tab_personne[i];
    }
    for(int i=0;i<nb_pers;i++){
        Person* pers=p.tab_personne[i];
        pers->p_mother=tab_id[pers->mother_id];
        pers->p_father=tab_id[pers->father_id];
    }

}
