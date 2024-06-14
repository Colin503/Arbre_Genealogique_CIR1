#include "person.h"

int main() {
    Person* p= initPerson("1,7,24,Mccormick,Rozanne,23/10/1807,Staffordshire");
    printf("Id: %d\nId father: %d\nId mother: %d\nNom: %s\nPrénom: %s\nDate de naissance: %d/%d/%d\nVille de naissance: %s\n ",
           p->id,p->father_id,p->mother_id,p->lastname,p->firstname,p->birthday,p->birthmonth,p->birthyear,p->birthzipcode);
    return 0;
}
