//
// Created by colin on 17/06/2024.
//

#include "menu.h"

void menu(Population t) {
    char temp;
    char path[30];
    int id;
    printf("Hey, que souhaitez vous rechercher ?\n\n(1) La Fratrie d'une personne\n(2) Les ancetres d'une personne sur 4 générations\n(3) Le plus lointain ancetre d'une personne\n");
    scanf("%c",&temp);
    switch (temp) {
        case '1':
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d",&id);
            fichePath(path,t.tab_personne[id]);
            exportFratrieHTML(t,t.tab_personne[id],path);
            break;
        case '2':
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d",&id);
            fichePath(path,t.tab_personne[id]);
            exportAncestorHTML(t,t.tab_personne[id],path);
            break;
        case '3':
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d",&id);
            Person* old=oldestancertor(t,t.tab_personne[id]);
            printf("Nom : %s\nPrenom : %s\nDate de naissance : %d/%d/%d\nVille de naissance : %s\n",old->lastname,old->firstname,old->birthday,old->birthmonth,old->birthyear,old->birthzipcode);
            break;
    }
}

void affichage_tableau(Person** tab) {
    int i=0;
    do { printf("id : %d\nnom : %s\nprenom : %s\n",tab[i]->id,tab[i]->lastname,tab[i]->firstname);i++; }
        while (tab[i]->id!=0);
}

void affichage_fratrie(Fratrie f) {
    for (int i=0;i<f.taille;i++) {
        printf("id : %d\nnom : %s\nprenom : %s\n",f.tab[i]->id,f.tab[i]->lastname,f.tab[i]->firstname);i++;
    }
}
