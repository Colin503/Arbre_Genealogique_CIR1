#include "population.h"

int main() {
    Person* p1= initPerson("0,0,0,-,-,-,-");
    Person* p= initPerson("17,39,13,Hodgkins,Florencia,28/12/1839,Herefordshire");
    Person* p2= initPerson("17,39,13,Hodgkins,Florencia,28/12/1839,Herefordshire");
    Person* p3= initPerson("17,39,13,Hodgkins,Florencia,28/12/1839,Herefordshire");
    printf("Id: %d\nId father: %d\nId mother: %d\nNom: %s\nPrénom: %s\nDate de naissance: %d/%d/%d\nVille de naissance: %s\n ",
           p->id,p->father_id,p->mother_id,p->lastname,p->firstname,p->birthday,p->birthmonth,p->birthyear,p->birthzipcode);
    Population pop;
    insert(pop,0,p1);
    insert(pop,1,p);
    insert(pop,2,p2);
    insert(pop,3,p3);
    return 0;
}
