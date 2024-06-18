#include "filemanager.h"

Population read_csv(const char* filename){
    FILE* f = fopen(filename, "r");
    int n=0;
    char buffer[256];
    while (fgets(buffer,256,f))
        n++;
    Person** tab= malloc(n* sizeof(Person*));
    Population pop;
    pop.nb_personne=0;
    pop.tab_personne=tab;
    rewind(f);
    for(int i=0;i<n;i++){
        Person* p=initPerson(fgets(buffer,256,f));
        insert(&pop, i,p);
    }
    return pop;
}
Population write_csv(Population pop,const char* filename){
    FILE* f = fopen(filename, "w");
    for(int i=0; i<pop.nb_personne;i++)
        fprintf(f,"%d,%d,%d,%s,%s,%s,%s",pop.tab_personne[i]->id,pop.tab_personne[i]->father_id
        ,pop.tab_personne[i]->mother_id,pop.tab_personne[i]->lastname,pop.tab_personne[i]->firstname
    ,pop.tab_personne[i]->birth,pop.tab_personne[i]->birthzipcode);
    return pop;
}
