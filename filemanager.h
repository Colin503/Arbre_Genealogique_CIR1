#ifndef PROJETCIR1_RENNES_GROUPE4_FILEMANAGER_H
#define PROJETCIR1_RENNES_GROUPE4_FILEMANAGER_H

#include "population.h"

Population read_csv(const char* filename);
Population write_csv(Population pop, const char* filename);

#endif //PROJETCIR1_RENNES_GROUPE4_FILEMANAGER_H
