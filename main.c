#include "population.h"

int main() {
    Population pop;
    pop = read_csv("../40.csv");
    linkPopulation(pop);
    for(int i=0;i<pop.nb_personne;i++) {
        printf("Adresse:%p Id: %d Id father: %d Id mother: %d Nom: %s Prénom: %s Date de naissance: %d/%d/%d Ville de naissance: %s Adresse mère:%p, Adresse père:%p\n ",
               pop.tab_personne[i],pop.tab_personne[i]->id, pop.tab_personne[i]->father_id, pop.tab_personne[i]->mother_id,
               pop.tab_personne[i]->lastname, pop.tab_personne[i]->firstname, pop.tab_personne[i]->birthday,
               pop.tab_personne[i]->birthmonth, pop.tab_personne[i]->birthyear, pop.tab_personne[i]->birthzipcode, pop.tab_personne[i]->p_mother, pop.tab_personne[i]->p_father);
    }
    return 0;
}
