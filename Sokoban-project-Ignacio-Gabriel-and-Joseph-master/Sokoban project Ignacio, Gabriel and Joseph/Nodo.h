#pragma once
#include<iostream>

class Nodo {
public:
	//Constructor parametrizado
	Nodo(char Caracter); 
	//Destructor
	~Nodo(); 
	//Sets y gets
	Nodo* getArriba(); 
	Nodo* getAbajo(); 
	Nodo* getIzquierda(); 
	Nodo* getDerecha(); 
	char getCaracter();
	bool getPunto();
	void setPunto();
	void setArriba(Nodo*); 
	void setAbajo(Nodo*); 
	void setDerecha(Nodo*); 
	void setIzquierda(Nodo*); 
	void setCaracter(char); 
	char toString(); 

	bool validaMovimiento(char); 

private:
	char caracter;
	Nodo* derecha;
	Nodo* izquierda;
	Nodo* abajo;
	Nodo* arriba;
	bool punto;
};


