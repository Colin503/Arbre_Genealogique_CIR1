#ifndef PROJET_FIN_HTMLEXPORT_H
#define PROJET_FIN_HTMLEXPORT_H
#include "advanced.h"

int titreHTMLPerson(char* buffer, Person* p);
int fichePath(char* buffer, Person* p);
void exportPersonHTML(const Population t,Person* p, char* path);
#endif //PROJET_FIN_HTMLEXPORT_H