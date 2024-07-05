#pragma once
#include"Herramientas.h"
#include<Windows.h>
#include <iosfwd> 
#include<conio.h>
class Interfaz
{
public:
	static Mapa* map;
	static int numMap;
public:
	static int menuPrincipal();
	static int menuNiveles();
	static void finalJuego();
	static int niveles();
	static Mapa* cargarNivel(int op);
	static std::string controles();
	static void imprimirPanel(Mapa*);
	static void repeticion(Mapa*, int);
	static void jugar();
	static bool cargaPartidaGuardada();
	static void mensajeSalida();
	static void mensajeGane(); 
	static void colores(std::string); 
	static int validaEntrada(std::string);
	static void noHayPartida(); 
};

