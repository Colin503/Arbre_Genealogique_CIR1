#ifndef PROJETCIR1_RENNES_GROUPE4_HTMLEXPORT_H
#define PROJETCIR1_RENNES_GROUPE4_HTMLEXPORT_H

//Nombre maximum de carctères contenus dans le chemin d'accès
#define TAILLE_CHEMIN_ACCES 100
//Nombre maximum de caractères pour le corps de la page HTML
#define TAILLE_MAX 100000 

#include "advanced.h"


int titreHTMLPerson(char* buffer, Person* p);
int fichePath_page(char* buffer, Person* p);
int fichePath(char* buffer, Person* p);
void exportAncestorHTML(Person* p, char* path);
void exportficheHTML(Person* p, char* path);
int printAncestorsToHTML(char* buffer, Person* p);
void exportFratrieHTML(const Population t,Person* p, char* path);
int printFratrieToHTML(char* buffer, const Population t, Person* p);
int contenu_fiche(char* buffer, Person* p);
#endif //PROJETCIR1_RENNES_GROUPE4_HTMLEXPORT_H
