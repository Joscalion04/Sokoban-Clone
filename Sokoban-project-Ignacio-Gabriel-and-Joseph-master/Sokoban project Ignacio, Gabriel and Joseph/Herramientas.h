#pragma once
#include"Mapa.h"
#include<fstream>

int convierteInt(std::string); 
char convierteChar(std::string); 
void ingresaLinea(std::string, Mapa*); 
Mapa* leeMapa(std::string); 
void guardarPartida(Mapa*, int);



