#include "htmlexport.h"

// Fonction pour générer le titre HTML pour une personne
int titreHTMLPerson(char* buffer, Person* p){
    int nb=0;
    nb+= sprintf(buffer, "<h2>");
    nb+= sprintf(buffer+nb,"%s",p->firstname);
    nb+= sprintf(buffer+nb, " ");
    nb+=sprintf(buffer+nb,"%s",p->lastname);
    nb+= sprintf(buffer+nb, "</h2>");
    return nb;
}

// Fonction pour générer le chemin de la page HTML de l'arbre ou de la fratrie
int fichePath_page(char* buffer, Person* p){
    int nb=0;
    nb+= sprintf(buffer,"%s","../site_arbre/");
    nb+= sprintf(buffer+nb,"%d",p->id);
    nb+= sprintf(buffer+nb,"%s","-page.html");
    return nb;
}

// Fonction pour générer le chemin de la fiche HTML
int fichePath(char* buffer, Person* p){
    int nb=0;
    nb+= sprintf(buffer,"../site_arbre/");
    nb+= sprintf(buffer+nb,"%d",p->id);
    nb+= sprintf(buffer+nb,"%s","-fiche.html");
    return nb;
}

// Fonction pour générer l'HTML des ancêtres d'une personne
int printAncestorsToHTML(char* buffer, const Population t, Person* p){
    Person** ancetres = ancestorsPersons(t,p);
    int nb=0;
    nb+= sprintf(buffer+nb,"<div class='ligne'>\n");
    char titre[30];
    // Génération des noeuds des ancêtres de la 3ème génération (Arrière Grand-Parents)
    for(int i=14;i>=7;i--){
        fichePath(titre, ancetres[i]);
        if(strcmp(ancetres[i]->firstname,"-")!=0) {
            nb+= sprintf(buffer+nb, "<div class='pers'><a href=\"%s\" ><p>Nom: %s <br>Prenom: %s </p></a></div>\n",titre, ancetres[i]->firstname,
                    ancetres[i]->lastname);
            exportficheHTML(t,ancetres[i],titre);
        }else{
            nb+= sprintf(buffer+nb,"<div class='inconnu'><p>Inconnu</p></div>\n");}
    }    nb+= sprintf(buffer+nb,"</div>\n");
    nb+=sprintf(buffer+nb,"<div class='ligne'>\n");
    // Génération des noeuds des ancêtres de la 2ème génération (Grand-Parents)
    for(int i=6;i>=3;i--){
        fichePath(titre, ancetres[i]);
        if(strcmp(ancetres[i]->firstname,"-")!=0) {
            nb+=sprintf(buffer+nb, "<div class='pers'><a href=\"%s\" ><p>Nom: %s <br>Prenom: %s </p></a></div>\n",titre, ancetres[i]->firstname,
                        ancetres[i]->lastname);
            exportficheHTML(t,ancetres[i],titre);
        }else{
            nb+=sprintf(buffer+nb,"<div class='inconnu'><p>Inconnu</p></div>\n");}
    }    nb+=sprintf(buffer+nb,"</div>\n");
    nb+=sprintf(buffer+nb,"<div class='ligne'>\n");
    // Génération des noeuds des ancêtres de la 1ère génération (Parents)
    for(int i=2;i>=1;i--){
        fichePath(titre, ancetres[i]);
        if(strcmp(ancetres[i]->firstname,"-")!=0) {
            nb+=sprintf(buffer+nb, "<div class='pers'><a href=\"%s\" ><p>Nom: %s <br>Prenom: %s </p></a></div>\n",titre, ancetres[i]->firstname,
                        ancetres[i]->lastname);
            exportficheHTML(t,ancetres[i],titre);
        }else{
            nb+=sprintf(buffer+nb,"<div class='inconnu'><p>Inconnu</p></div>\n");}
    }    nb+=sprintf(buffer+nb,"</div>\n");
    nb+=sprintf(buffer+nb,"<div class='ligne'>\n");
    // Génération du noeud de la personne elle-même
    fichePath(titre, ancetres[0]);
    nb+=sprintf(buffer+nb, "<div class='pers'><a href=\"%s\" ><p>Nom: %s <br>Prenom: %s </p></a></div>\n",titre, ancetres[0]->firstname,
                ancetres[0]->lastname);
    exportficheHTML(t,ancetres[0],titre);
    nb+=sprintf(buffer+nb,"</div>\n");
    free(ancetres);// Libère la mémoire allouée pour le tableau d'ancêtres
    return nb;
}

// Fonction pour exporter la page HTML des ancêtres d'une personne
void exportAncestorHTML(const Population t,Person* p, char* path){
        FILE* f =fopen(path,"w");
        fprintf(f,("<!DOCTYPE html>\n"
                   "<html>\n"
                   "<head>\n"
                   "\t<meta charset=\"utf-8\">\n"
                   "\t<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\">\n"
                   "\t<script type=\"text/javascript\" src=\"fichier.js\"></script>\n"
                   "    <link rel=\"icon\" href=\"img/30924.png\" type=\"image/icon type\">\n"
                   "\n"
                   "    <title>Arbre Généalogique</title>\n"
                   "</head>\n"
                   "\n"
                   "<body>\n\t<div id='tree'>"));
        char buffer[100];
        titreHTMLPerson(buffer, p); // Génère le titre HTML pour la personne
        fprintf(f,"\t%s\n",buffer);
        char buffer2[TAILLE_MAX];
        printAncestorsToHTML(buffer2,t, p);// Génère le contenu HTML des ancêtres
        fprintf(f,"\t%s\n",buffer2);
        fprintf(f,"</div></body>\n</html>");
        fclose(f);

}

// Fonction pour générer le contenu HTML d'une fiche personnelle
int contenu_fiche(char* buffer, const Population t, Person* p){
    int nb=0;
    nb+=sprintf(buffer+nb,"<div class='fiche'><p>Prénom: %s\n<br>Nom: %s\n",p->firstname,p->lastname);
    nb+=sprintf(buffer+nb,"<br>Date de naissance: %d/%d/%d<br>Lieu de naissance: %s </p></div>",p->birthday,p->birthmonth,p->birthyear,p->birthzipcode);
    return nb;
}
// Fonction pour exporter la fiche HTML d'une personne
void exportficheHTML(const Population t,Person* p, char* path){
    FILE* f =fopen(path,"w");
    fprintf(f,("<!DOCTYPE html>\n"
               "<html>\n"
               "<head>\n"
               "\t<meta charset=\"utf-8\">\n"
               "\t<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\">\n"
               "\t<script type=\"text/javascript\" src=\"fichier.js\"></script>\n"
               "    <link rel=\"icon\" href=\"img/30924.png\" type=\"image/icon type\">\n"
               "\n"
               "    <title>Fiche</title>\n"
               "</head>\n"
               "\n"
               "<body>\n\t<div id='tree'>"));
    char buffer[100];
    titreHTMLPerson(buffer, p); // Génère le titre HTML pour la personne
    fprintf(f,"\t%s\n",buffer);
    char buffer2[TAILLE_MAX];
    contenu_fiche(buffer2,t,p);// Génère le contenu HTML de la fiche
    fprintf(f,"\t%s\n",buffer2);
    fprintf(f,"</div></body>\n</html>");
    fclose(f);
}

// Fonction pour générer l'HTML de la fratrie d'une personne
int printFratrieToHTML(char* buffer, const Population t, Person* p){
    Fratrie fr= fratrie(t,p);
    int nb=0;
    nb+= sprintf(buffer+nb,"<div class='ligne'>\n");
    char titre[30];
    for(int i=0;i<fr.taille;i++){
        fichePath(titre, fr.tab[i]);
        nb+=sprintf(buffer+nb,"<div class='pers'><a href=\"%s\" ><p>Nom: %s <br>Prenom: %s </p></a></div>\n",titre,fr.tab[i]->firstname,fr.tab[i]->lastname);
        exportficheHTML(t,fr.tab[i],titre);
    }
    nb+=sprintf(buffer+nb,"</div>\n");
    return nb;
}

// Fonction pour créer la page HTML de la fratrie d'une personne
void exportFratrieHTML(const Population t,Person* p, char* path){
    FILE* f =fopen(path,"w");
    fprintf(f,("<!DOCTYPE html>\n"
               "<html>\n"
               "<head>\n"
               "\t<meta charset=\"utf-8\">\n"
               "\t<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\">\n"
               "\t<script type=\"text/javascript\" src=\"fichier.js\"></script>\n"
               "    <link rel=\"icon\" href=\"img/30924.png\" type=\"image/icon type\">\n"
               "\n"
               "    <title>Fratrie</title>\n"
               "</head>\n"
               "\n"
               "<body>\n\t<div id='tree'>"));
    char buffer[100];
    titreHTMLPerson(buffer, p);// Génère le titre HTML pour la personne
    fprintf(f,"\t%s\n",buffer);
    char buffer2[1000];
    printFratrieToHTML(buffer2,t, p);// Génère le contenu HTML de la fratrie
    fprintf(f,"\t%s\n",buffer2);
    fprintf(f,"</div></body>\n</html>");
}
