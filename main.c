#include "population.h"

int main() {
    Person* p1= initPerson("0,0,0,-,-,-,-");
    Person* p= initPerson("17,39,13,Hodgkins,Florencia,28/12/1839,Herefordshire");
    Person* p2= initPerson("13,0,0,Mccormick,Rosina,22/2/1815,Worcestershire");
    Person* p3= initPerson("39,0,0,Hodgkins,Salvatore,23/9/1808,Herefordshire");
 printf("Id: %d\nId father: %d\nId mother: %d\nNom: %s\nPrénom: %s\nDate de naissance: %d/%d/%d\nVille de naissance: %s\n ",
           p->id,p->father_id,p->mother_id,p->lastname,p->firstname,p->birthday,p->birthmonth,p->birthyear,p->birthzipcode);
    Population pop;
    Person** tab= malloc(40* sizeof(Person));
    pop.tab_personne=tab;
    insert(&pop,0,p1);
    insert(&pop,1,p);
    insert(&pop,2,p2);
    insert(&pop,3,p3);
    linkPopulation(pop);
    printf("%p\n",pop.tab_personne[0]->p_father);
    printf("%p\n",pop.tab_personne[0]->p_mother);

    printf("%p\n",pop.tab_personne[1]->p_mother);
    printf("%p\n",pop.tab_personne[2]);
    printf("%p\n",pop.tab_personne[2]->p_mother);
    printf("%p\n",pop.tab_personne[2]->p_father);
    printf("%p\n",pop.tab_personne[1]->p_father);
    printf("%p\n",pop.tab_personne[3]);
    printf("%p\n",pop.tab_personne[3]->p_mother);
    printf("%p\n",pop.tab_personne[3]->p_father);
    return 0;
}
