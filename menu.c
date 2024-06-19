#include "menu.h"

void menu(Population t) {
    char temp;
    char path[TAILLE_CHEMIN_ACCES];
    int id;

    printf("Hey, que souhaitez vous rechercher ?\n\n(1) La Fratrie d'une personne\n(2) Les ancetres d'une personne sur 4 générations\n(3) Le plus lointain ancetre d'une personne\n");
    scanf("%c",&temp); 
    switch (temp) { 
        case '1': //Cas pour trouver la fratrie d'une personne
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d", &id);
            fichePath_page(path, t.tab_personne[id]);
            exportFratrieHTML(t, t.tab_personne[id], path);
            break;
        case '2': //Cas pour trouver les ancetre d'une personne sur 5 générations (4 sont affichés dans le html)
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d", &id);
            fichePath_page(path, t.tab_personne[id]);
            exportAncestorHTML(t.tab_personne[id], path);
            break;
        case '3': //Cas pour trouver le plus lointain ancetre d'une personne
            printf("Entrez l'id de la personne que vous souhaitez rechercher --> ");
            scanf("%d", &id);
            Person *old = oldestancertor( t.tab_personne[id]);
            if(old->id!=t.tab_personne[id]->id) {
                fichePath(path, t.tab_personne[id]);
                exportficheHTML(t.tab_personne[id], path);
                printf("Id: %d\nNom : %s\nPrenom : %s\nDate de naissance : %d/%d/%d\nVille de naissance : %s\n",
                       old->id, old->lastname,
                       old->firstname, old->birthday, old->birthmonth, old->birthyear, old->birthzipcode);
                fichePath(path, old);
                exportficheHTML(old, path);
            } else{
                printf("Cette personne n'a pas d'ancêtres connus dans cette dans cette base de données.\n");
            }
            break;
        default: //Si l'utlisateur rentre un caractère invalide , le programme se ferme
            printf("Choix invalide. Fin du programme.\n");
            break;
    }

}

void affichage_tableau(Person** tab) { //fonciton de test pour afficher un tableau de personne
    int i=0;
    do { printf("id : %d\nnom : %s\nprenom : %s\n",tab[i]->id,tab[i]->lastname,tab[i]->firstname);i++; }
    while (tab[i]->id!=0);
}

void affichage_fratrie(Fratrie f) { //fonction de test pour affiche la fratrie 
    for (int i=0;i<f.taille;i++) {
        printf("id : %d\nnom : %s\nprenom : %s\n",f.tab[i]->id,f.tab[i]->lastname,f.tab[i]->firstname);
        i++;
    }
}
