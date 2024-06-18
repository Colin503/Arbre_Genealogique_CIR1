//
// Created by colin on 17/06/2024.
//

#include "menu.h"

void menu(Population t,Person** tab) {
    char temp;
    char path[30];
    int id;
    printf("Hey, que souhaitez vous rechercher ?\n\n(1) La Fratrie d'une personne\n(2) Les ancetres d'une personne sur 2 générations\n(3) ...\n(4) ...\n");
    scanf("%c",&temp);
    switch (temp) {
        case '1':
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d",&id);
            printf("%s %d\n",path,fichePath(path, t.tab_personne[id]));
            exportPersonHTML_fratrie(t,t.tab_personne[id],path);
            break;
        case '2':
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d",&id);
            printf("%s %d\n",path,fichePath(path, t.tab_personne[id]));
            exportPersonHTML_generation2(t,t.tab_personne[id],path);
            break;
        case '3':
            break;
        case '4':
            break;
    }


}


void affichage_tableau(Person** tab) {
    int taille=0;
    while (tab[taille]!=NULL) {
        taille++;
    }
    for (int i=0;i<taille;i++) {
        printf("id : %d\nnom : %s\nprenom : %s\n",tab[i]->id,tab[i]->firstname,tab[i]->lastname);
    }
}
