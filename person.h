#ifndef PROJETCIR1_RENNES_GROUPE4_PERSON_H
#define PROJETCIR1_RENNES_GROUPE4_PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct person{
    int id;
    int father_id;
    int mother_id;
    char lastname[20];
    char firstname[20];
    int birthday; int birthmonth; int birthyear;
    char birthzipcode[30];
    struct person * p_father;
    struct person * p_mother;
}Person;

Person* initPerson(char* csvline);

#endif //PROJETCIR1_RENNES_GROUPE4_PERSON_H
