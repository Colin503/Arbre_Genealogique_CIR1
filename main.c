#include "population.h"

int main() {
    Person *p = initPerson("1,7,24,Mccormick,Rozanne,23/10/1807,Staffordshire");
    Person** tab_personne= malloc(40*sizeof(Person));
    //tab_personne[0]=p;
    Population pop1;
    pop1.tab_personne=tab_personne;
    pop1.nb_personne=0;
    Person* p1= initPerson("0,0,0,-,-,-,-");
    Person* p2= initPerson("17,39,13,Hodgkins,Florencia,28/12/1839,Herefordshire");
    Person* p3= initPerson("17,39,13,Hodgkins,Florencia,28/12/1839,Herefordshire");
    Population* pop=&pop1;
    insert(pop,0,p1);
    insert(pop,1,p);
    insert(pop,2,p2);
    insert(pop,3,p3);
    printf("%d\n%d\n%d\n",pop1.tab_personne[0]->id,pop1.tab_personne[1]->id,pop1.tab_personne[2]->id);
    return 0;
}
