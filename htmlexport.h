#ifndef PROJET_FIN_HTMLEXPORT_H
#define PROJET_FIN_HTMLEXPORT_H
#include "advanced.h"
#define TAILLE_CHEMIN_ACCES 100
#define TAILLE_MAX 100000

int titreHTMLPerson(char* buffer, Person* p);
int fichePath_page(char* buffer, Person* p);
int fichePath(char* buffer, Person* p);
void exportAncestorHTML(const Population t,Person* p, char* path);
void exportficheHTML(const Population t,Person* p, char* path);
int printAncestorsToHTML(char* buffer, const Population t, Person* p);
void exportFratrieHTML(const Population t,Person* p, char* path);
int printFratrieToHTML(char* buffer, const Population t, Person* p);
int contenu_fiche(char* buffer, const Population t, Person* p);
#endif //PROJET_FIN_HTMLEXPORT_H
