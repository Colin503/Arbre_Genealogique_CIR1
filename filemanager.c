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
