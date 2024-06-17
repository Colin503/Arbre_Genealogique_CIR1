#include "htmlexport.h"
int titreHTMLPerson(char* buffer, Person* p){
    int nb=0;
    nb+= sprintf(buffer, "<h2>");
    nb+= sprintf(buffer+nb,"%s",p->firstname);
    nb+= sprintf(buffer+nb, " ");
    nb+=sprintf(buffer+nb,"%s",p->lastname);
    nb+= sprintf(buffer+nb, "</h2>");
    return nb;
}
int fichePath(char* buffer, Person* p){
    int nb=0;
    nb+= sprintf(buffer,"%s","../site_arbre/");
    nb+= sprintf(buffer+nb,"%d",p->id);
    nb+= sprintf(buffer+nb,"%s","-fiche.html");
    return nb;
}
void exportPersonHTML(const Population t,Person* p, char* path){
    FILE* f =fopen(path,"w");
    fprintf(f,("<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "\t<meta charset=\"utf-8\">\n"
              "\t<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\">\n"
              "\t<script type=\"text/javascript\" src=\"fichier.js\"></script>\n"
              "    <link rel=\"icon\" href=\"img/30924.png\" type=\"image/icon type\">\n"
              "\n"
              "    <title>Arbre généalogique</title>\n"
              "</head>\n"
              "\n"
              "<body>\n\t<div id='tree'>"));
    char buffer[100];
    titreHTMLPerson(buffer, p);
    fprintf(f,"\t%s\n",buffer);
    fratrie(t,p);
    Person** ancetres = ancestorsPersons(t,p);
    for(int i=0;i<7;i++){
        if(strcmp(ancetres[i]->firstname,"-")!=0)
            fprintf(f,"<div><p>Prenom: %s Nom: %s</p></div>\n",ancetres[i]->firstname,ancetres[i]->lastname);
        else
            fprintf(f,"<div><p>Inconnu</p></div>\n");
    }
    fprintf(f,"</div></body>\n</html>");

}