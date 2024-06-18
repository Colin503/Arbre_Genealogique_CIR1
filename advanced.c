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
    Person** tab_ancetre= malloc(31* sizeof(Person*)); //31 cases car on se limites à 5 générations pour l'instant
        tab_ancetre[0] = p;

        tab_ancetre[1] = p->p_father;
        tab_ancetre[2] = p->p_mother;

        tab_ancetre[3] = p->p_father->p_father;
        tab_ancetre[4] = p->p_father->p_mother;
        tab_ancetre[5] = p->p_mother->p_father;
        tab_ancetre[6] = p->p_mother->p_mother;

        tab_ancetre[7] = p->p_father->p_father->p_father;
        tab_ancetre[8] = p->p_father->p_father->p_mother;
        tab_ancetre[9] = p->p_father->p_mother->p_father;
        tab_ancetre[10] = p->p_father->p_mother->p_mother;
        tab_ancetre[11] = p->p_mother->p_father->p_father;
        tab_ancetre[12] = p->p_mother->p_father->p_mother;
        tab_ancetre[13] = p->p_mother->p_mother->p_father;
        tab_ancetre[14] = p->p_mother->p_mother->p_mother;


        tab_ancetre[15] = p->p_father->p_father->p_father->p_father;
        tab_ancetre[16] = p->p_father->p_father->p_father->p_mother;
        tab_ancetre[17] = p->p_father->p_father->p_mother->p_father;
        tab_ancetre[18] = p->p_father->p_father->p_mother->p_mother;
        tab_ancetre[19] = p->p_father->p_mother->p_father->p_father;
        tab_ancetre[20] = p->p_father->p_mother->p_father->p_mother;
        tab_ancetre[21] = p->p_father->p_mother->p_mother->p_father;
        tab_ancetre[22] = p->p_father->p_mother->p_mother->p_mother;
        tab_ancetre[23] = p->p_mother->p_father->p_father->p_father;
        tab_ancetre[24] = p->p_mother->p_father->p_father->p_mother;
        tab_ancetre[25] = p->p_mother->p_father->p_mother->p_father;
        tab_ancetre[26] = p->p_mother->p_father->p_mother->p_mother;
        tab_ancetre[27] = p->p_mother->p_mother->p_father->p_father;
        tab_ancetre[28] = p->p_mother->p_mother->p_father->p_mother;
        tab_ancetre[29] = p->p_mother->p_mother->p_mother->p_father;
        tab_ancetre[30] = p->p_mother->p_mother->p_mother->p_mother;
        
    return tab_ancetre;
}
void ancestors_debug(Person** tab,const char* filen){
    FILE* f= fopen(filen,"w");
    for(int i=0; i<7;i++){
        fprintf(f,"%d,%d,%d,%s,%s,%s,%s",tab[i]->id,tab[i]->father_id,tab[i]->mother_id,tab[i]->firstname,tab[i]->lastname,tab[i]->birth,tab[i]->birthzipcode);
    }
    fclose(f);
}

Person* oldestancertor(Population t,Person* p) {
    Person* ancestor;
    Person** tab_ancestor= ancestorsPersons(t,p);
    for (int i=0;i<31;i++) {
        if (tab_ancestor[31-i]!=NULL) {
            ancestor=tab_ancestor[31-i];
            return ancestor;
        }
    }
}
