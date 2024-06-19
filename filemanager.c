#include "filemanager.h"

//Fonction qui lit le fichier texte et rentre les informations de chaque ligne.
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
    for(int i=0;i<n;i++){//Récupère chaque ligne, initialise les personnes et les insère dans une population.
        Person* p=initPerson(fgets(buffer,256,f));
        insert(&pop, i,p);
    }
    return pop;//Retourne une population en fonction du fichier rentré en paramètre
}
//Fonction de débug de la fonction read_csv()
//Elle réécrit les données lues par la fonction read_csv()
Population write_csv(Population pop,const char* filename){
    FILE* f = fopen(filename, "w");
    for(int i=0; i<pop.nb_personne;i++)
        fprintf(f,"%d,%d,%d,%s,%s,%d/%d/%d,%s",pop.tab_personne[i]->id,pop.tab_personne[i]->father_id
        ,pop.tab_personne[i]->mother_id,pop.tab_personne[i]->lastname,pop.tab_personne[i]->firstname
    ,pop.tab_personne[i]->birthday,pop.tab_personne[i]->birthmonth,pop.tab_personne[i]->birthyear,pop.tab_personne[i]->birthzipcode);
    return pop;
}
