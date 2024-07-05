#pragma once
#include"Nodo.h"
#include <sstream>
#include<stack>
#include<vector>

class Mapa {
public:
	Mapa();
	~Mapa();
	void eliminaFila(Nodo* ); //Recorre la fila eliminando cada uno de sus nodos 
	void insertar(char , int ); //Inserta cada elemento en la lista (char) y los casos determinan si hay un salto de linea (int)
	std::string imprimir(); //Recorre verticalmente la lista llamando al imprimirFila para cada fila 
	std::string imprimirFila(Nodo*); //Recorre horizontalmente la fila imprimiendo cada nodo 
	int getCantCajas(); //Devuelve la cantidad de cajas presentes en el mapa
	void cajasPendientes(int); //Modifica la pila para determinar cuantas cajas faltan de posicionarse en un punto
	void setJugador(Nodo*); //Determina el nodo en el que se ubica el jugador al iniciar la partida
	void moverJugador(char move); //Mueve al jugador segun la tecla que presiona
	std::vector<char> getMovimientos(); //Retorna el vector en el que se almacenan los movimientos que realiza el usuario durante la partida
	void ingresarMovimiento(char); //Ingresa el movimiento que realiza el jugador al vector
	Nodo* getJugador(); //Retorna el nodo en el que se encuentra el jugador
	void mueveCaja(char);  //Realiza las validaciones y movimiento de las cajas en caso de que el jugador interactua con ellas
	//std::string imprimeMapa(Nodo*, std::string); //
	bool ganador(); //Determina cuando la pila llega a la situacion de que no hay mas cajas pendientes de colocar en puntos
	void setMovimientos(std::vector<char>); //Setea en el vector de movimientos un vector que entra por parametros. 
	

private:
	Nodo* inicio;
	Nodo* jugador;
	//char aux;
	std::stack<int> pilaCajas; 
	std::vector<char> moves; 
	int cantCajas; 
};
