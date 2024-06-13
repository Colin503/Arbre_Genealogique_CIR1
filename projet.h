//
// Created by colin on 13/06/2024.
//

#ifndef S2_PROJETFINAL_PROJET_H
#define S2_PROJETFINAL_PROJET_H
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





#endif //S2_PROJETFINAL_PROJET_H
