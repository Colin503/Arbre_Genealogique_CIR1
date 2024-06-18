#ifndef PROJET_FIN_HTMLEXPORT_H
#define PROJET_FIN_HTMLEXPORT_H
#include "advanced.h"

int titreHTMLPerson(char* buffer, Person* p);
int fichePath(char* buffer, Person* p);
void exportAncestorHTML(const Population t,Person* p, char* path);
int printAncestorsToHTML(char* buffer, const Population t, Person* p);
void exportFratrieHTML(const Population t,Person* p, char* path);
int printFratrieToHTML(char* buffer, const Population t, Person* p);
#endif //PROJET_FIN_HTMLEXPORT_H
