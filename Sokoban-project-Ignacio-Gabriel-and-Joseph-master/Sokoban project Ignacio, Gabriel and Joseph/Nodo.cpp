#include"Nodo.h"

//Constructor parametrizado
Nodo::Nodo(char car) {
	this->caracter = car;
	this->punto = false;
	this->abajo = nullptr; 
	this->arriba = nullptr; 
	this->derecha = nullptr; 
	this->izquierda = nullptr; 
}

//Destructor
Nodo::~Nodo() {}
//Sets y gets
Nodo* Nodo::getArriba() { return arriba; }
Nodo* Nodo::getAbajo() { return abajo;  }
Nodo* Nodo::getIzquierda() { return izquierda;  }
Nodo* Nodo::getDerecha() { return derecha;  }
char Nodo::getCaracter() { return caracter;  }
bool Nodo::getPunto(){return punto;}
void Nodo::setPunto(){this->punto = true;}
void  Nodo::setArriba(Nodo* ar) { this->arriba = ar; }
void Nodo::setAbajo(Nodo* ab) { this->abajo = ab; }
void Nodo::setDerecha(Nodo* der) {this->derecha = der;}
void Nodo::setIzquierda(Nodo* iz) { this->izquierda = iz;  }
void Nodo::setCaracter(char car) { this->caracter = car;  }
char Nodo::toString() { return caracter;  }

bool Nodo::validaMovimiento(char dir)
{
	bool flag = true; 
	switch (dir) {
	case 'w': {
		if (arriba->getCaracter() == '#')
			flag = false; 
		if (arriba->getCaracter() == '$'|| arriba->getCaracter() == '!')
			if (arriba->getArriba()->getCaracter() == '$' || arriba->getArriba()->getCaracter() == '#'|| arriba->getArriba()->getCaracter() == '!')
				flag = false; 
			 
		break; 
	}
	case 'a': {
		if (izquierda->getCaracter() == '#')
			flag = false;
		if (izquierda->getCaracter() == '$'||izquierda->getCaracter() == '!')
			if (izquierda->getIzquierda()->getCaracter() == '$' || izquierda->getIzquierda()->getCaracter() == '#'|| izquierda->getIzquierda()->getCaracter() == '!')
				flag = false;
		break;
	}
	case 's': {
		if (abajo->getCaracter() == '#')
			flag = false;
		if (abajo->getCaracter() == '$'|| abajo->getCaracter() == '!')
			if (abajo->getAbajo()->getCaracter() == '$' || abajo->getAbajo()->getCaracter() == '#'|| abajo->getAbajo()->getCaracter() == '!')
				flag = false;
		break;
	}
	case 'd': {
		if (derecha->getCaracter() == '#')
			flag = false;
		if (derecha->getCaracter() == '$'|| derecha->getCaracter() == '!')
			if (derecha->getDerecha()->getCaracter() == '$' || derecha->getDerecha()->getCaracter() == '#'|| derecha->getDerecha()->getCaracter() == '!')
				flag = false;
		break;
	}
	default: {
		break; 
	}
	}
	return flag;
}
