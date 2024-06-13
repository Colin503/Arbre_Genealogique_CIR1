#include "person.h"
Person* initPerson(char* csvline){
    Person* pers= malloc(sizeof(Person));
    FILE* f = fopen(csvline, "r");
    char chaine[64];
    if(csvline==NULL)
        printf("Prblm\n");
    else{
        int j=0,k=0;
        for(int i=0;i< strlen(csvline);i++){
            if(!(csvline[i]==',' || csvline[i]=='/')) {
                chaine[j] = csvline[i];
                j++;
                chaine[j]='\0';
            }
            else{
                j=0;
                switch(k){
                    case 0:
                        pers->id= atoi(chaine);
                        break;
                    case 1:
                        pers->father_id= atoi(chaine);
                        break;
                    case 2:
                        pers->mother_id= atoi(chaine);
                        break;
                    case 3:
                        strcpy(pers->lastname,chaine);
                        break;
                    case 4:
                        strcpy(pers->firstname,chaine);
                        break;
                    case 5:
                        pers->birthday= atoi(chaine);
                        break;
                    case 6:
                        pers->birthmonth= atoi(chaine);
                        break;
                    case 7:
                        pers->birthyear= atoi(chaine);
                        break;
                    case 8:
                        strcpy(pers->birthzipcode,chaine);
                        break;
                }
                k++;
            }
        }
    }
    pers->p_father=NULL;
    pers->p_mother=NULL;
    return pers;
}
