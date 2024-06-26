#include "advanced.h"

Fratrie fratrie(Population p,Person* humain) { //Fontion qui renvoie un tableau de personne contenant la fratrie de la personne humain
    Fratrie f;
    f.taille = 0;
    if(humain->father_id != 0 || humain->mother_id != 0) { // --> si ses parents ne sont pas inconnus
        for (int i = 0; i < p.nb_personne; i++)
            if (p.tab_personne[i]->father_id == humain->father_id && p.tab_personne[i]->mother_id == humain->mother_id) --> si ils ont les memes parents que humain
                f.taille++;
        f.tab = malloc(f.taille * sizeof(Person *)); //on alloue de la mémoire
        f.taille = 0;
        for (int i = 0; i < p.nb_personne; i++)
            if (p.tab_personne[i]->father_id == humain->father_id &&
                p.tab_personne[i]->mother_id == humain->mother_id) {
                f.tab[f.taille] = p.tab_personne[i];
                f.taille++;
            }
    }
    else{
        f.taille=1;
        f.tab = malloc( sizeof(Person *)); //on alloue de la mémoire
        f.tab[0] = humain; 
    }
    return f; //on renvoie la fratrie
}

Person** ancestorsPersons(Person* p) { //Fonction qui renvoie un tableau de personne contenant les 30 ancetres d'une personne
    Person** tab_ancetre= malloc(31* sizeof(Person*)); //31 cases car on se limite à 5 générations
    tab_ancetre[0] = p;

    tab_ancetre[1] = p->p_father;
    tab_ancetre[2] = p->p_mother;

    tab_ancetre[3] = p->p_father->p_father;
    tab_ancetre[4] = p->p_father->p_mother;
    tab_ancetre[5] = p->p_mother->p_father;
    tab_ancetre[6] = p->p_mother->p_mother;

    tab_ancetre[7] = p->p_father->p_father->p_father;
    tab_ancetre[8] = p->p_father->p_father->p_mother;
    tab_ancetre[9] = p->p_father->p_mother->p_father;
    tab_ancetre[10] = p->p_father->p_mother->p_mother;
    tab_ancetre[11] = p->p_mother->p_father->p_father;
    tab_ancetre[12] = p->p_mother->p_father->p_mother;
    tab_ancetre[13] = p->p_mother->p_mother->p_father;
    tab_ancetre[14] = p->p_mother->p_mother->p_mother;


    tab_ancetre[15] = p->p_father->p_father->p_father->p_father;
    tab_ancetre[16] = p->p_father->p_father->p_father->p_mother;
    tab_ancetre[17] = p->p_father->p_father->p_mother->p_father;
    tab_ancetre[18] = p->p_father->p_father->p_mother->p_mother;
    tab_ancetre[19] = p->p_father->p_mother->p_father->p_father;
    tab_ancetre[20] = p->p_father->p_mother->p_father->p_mother;
    tab_ancetre[21] = p->p_father->p_mother->p_mother->p_father;
    tab_ancetre[22] = p->p_father->p_mother->p_mother->p_mother;
    tab_ancetre[23] = p->p_mother->p_father->p_father->p_father;
    tab_ancetre[24] = p->p_mother->p_father->p_father->p_mother;
    tab_ancetre[25] = p->p_mother->p_father->p_mother->p_father;
    tab_ancetre[26] = p->p_mother->p_father->p_mother->p_mother;
    tab_ancetre[27] = p->p_mother->p_mother->p_father->p_father;
    tab_ancetre[28] = p->p_mother->p_mother->p_father->p_mother;
    tab_ancetre[29] = p->p_mother->p_mother->p_mother->p_father;
    tab_ancetre[30] = p->p_mother->p_mother->p_mother->p_mother;

    return tab_ancetre;
}

Person* oldestancertor(Person* p) { //Renvoie l'ancetre le plus lointain d'une personne
    Person* ancestor=p;
    int temp=p->birthyear;
    Person** tab_ancestor= ancestorsPersons(p); //On utilise la fonctions ancestorsPersons pour créer le tableau des ancetres de la personne.
    for (int i=0;i<31;i++) {
        if (tab_ancestor[i]->id!=0) {
            if (tab_ancestor[i]->birthyear<temp) { //On itère sur le tableau et on compare leur année de naissance pour trouver le plus jeune
                ancestor = tab_ancestor[i];
                temp = tab_ancestor[i]->birthyear;
            }
        }
    }
    return ancestor;
}
