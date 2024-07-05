#include "Herramientas.h"
int convierteInt(std::string dato) {
	std::stringstream s(dato);
	int valor;
	s >> valor;
	return valor;
}

char convierteChar(std::string dato) {
	std::stringstream s(dato);
	char valor;
	s >> valor;
	return valor;
}

void ingresaLinea(std::string line, Mapa* map) {

	char car = ' ';
	int cas = 0;

	for (int i = 1; i < line.length(); i += 2) {
		car = convierteChar(line.substr(i, i));
		cas = convierteInt(line.substr(i + 1, i + 1));
		map->insertar(car, cas);
	}
}

Mapa* leeMapa(std::string path) {
	char caracter;
	int caso;
	std::ifstream entrada;
	std::string pal = " ";
	Mapa* map = new Mapa();
	entrada.open(path);
	while (entrada.good()) {
		std::getline(entrada, pal, '\n');
		ingresaLinea(pal, map);
	}
	map->cajasPendientes(map->getCantCajas());
	return map;
}

void guardarPartida(Mapa* map, int numMap)
{
	std::ofstream salida; 
	salida.open("../partidaGuardada.txt", std::ios::trunc); 
	salida << numMap << '\n'; 
	std::vector<char>::iterator it = map->getMovimientos().begin();

	// Recorrer el vector
	for (const char& movimiento : map->getMovimientos()) {
		salida << movimiento << '\t';
	}
	salida.close(); 
}

