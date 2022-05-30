#ifndef geo_h
#define geo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "figuras.h"
#include "arvore.h" 

// faz a leitura do arquivo .geo passado de parâmetro e cria todas as figuras necessárias
void interpretandoGeo(FILE* geoFile, ArvB arvore);

#endif