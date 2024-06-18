#ifndef PROJET_FIN_FILEMANAGER_H
#define PROJET_FIN_FILEMANAGER_H
#include "population.h"

Population read_csv(const char* filename);
Population write_csv(Population pop,const char* filename);

#endif //PROJET_FIN_FILEMANAGER_H
