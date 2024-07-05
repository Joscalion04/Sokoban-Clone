#include"Mapa.h"


Mapa::Mapa()
{
	inicio = nullptr;
	jugador = nullptr;
	cantCajas = 0; 
}

Mapa::~Mapa()
{
	while (inicio != nullptr) {
		Nodo* Aux = inicio;
		inicio = Aux->getAbajo();
		this->eliminaFila(Aux);
	}
}

void Mapa::eliminaFila(Nodo* Aux)
{
	while (Aux != nullptr) {
		Nodo* aux = Aux;
		Aux = Aux->getIzquierda();
		delete aux;
	}
}

void Mapa::insertar(char dato, int caso)
{
	Nodo* aux = nullptr; ;
	Nodo* nuevo = new Nodo(dato);
	if (nuevo->getCaracter() == '.') { nuevo->setPunto(); }
	switch (caso) {
	case 1: {

		aux = inicio;
		if (inicio == nullptr) {
			inicio = nuevo;
		}
		else {
			aux = inicio;
			while (aux->getDerecha() != nullptr) {
				aux = aux->getDerecha();
			}
			aux->setDerecha(nuevo);
			nuevo->setIzquierda(aux);
		}
		break;
	}
	case 2: {
	
		aux = inicio;
		if (inicio->getAbajo() == nullptr) {
			inicio->setAbajo(nuevo);
			nuevo->setArriba(inicio);
		}
		else {
			while (aux->getAbajo() != nullptr) {
				aux = aux->getAbajo();
			}
			aux->setAbajo(nuevo);
			nuevo->setArriba(aux);
		}
		break;
	}
	case 3: {
		
		aux = inicio;
		while (aux->getAbajo() != nullptr) {
			aux = aux->getAbajo();
		}
		while (aux->getDerecha() != nullptr) {
			aux = aux->getDerecha();
		}
		nuevo->setIzquierda(aux);
		aux->setDerecha(nuevo);
		aux->getArriba()->getDerecha()->setAbajo(nuevo);
		nuevo->setArriba(aux->getArriba()->getDerecha());
		if (nuevo->getCaracter() == '@')
			this->jugador = nuevo;
		break;
	}
	default: { break; }
	}
	if (dato == '$') {
		cantCajas++;
	}
}

std::string Mapa::imprimir()
{
	std::stringstream text;
	Nodo* aux = inicio;
	while (aux != nullptr) {
		text << imprimirFila(aux);
		aux = aux->getAbajo();
	}
	system("cls");
	return text.str();
}

std::string Mapa::imprimirFila(Nodo* aux)
{
	std::stringstream text;
	while (aux->getDerecha() != nullptr) {
		if (aux->getCaracter() == '/' || aux->getCaracter() == 'x')
			text << ' ';
		else {
			if (aux->getCaracter() == '#') {
				text << "\033[36m";
				text << aux->toString();
				text << "\033[0m";
			}
			if (aux->getCaracter() == '$') {
				text << "\033[33m"; 
				text << aux->toString();
				text << "\033[0m";
			}
			if (aux->getCaracter() == '@') {
				if (aux->getPunto())
					text << "\033[35m";
				else
					text << "\033[31m";
				text << aux->toString();
				text << "\033[0m";
			}
			if (aux->getCaracter() == '!') {
				text << "\033[32m";
				text << aux->toString();
				text << "\033[0m";
			}
			if (aux->getCaracter() == '.') {
				text << "\033[31m";
				text << aux->toString();
				text << "\033[0m";
			}
			
		}
		aux = aux->getDerecha();
	}
	if (aux->getCaracter() != '/') {
		if (aux->getCaracter() == '#') {
			text << "\033[36m";
			text << aux->toString()<<'\n';
			text << "\033[0m";
		}
		else
			text << aux->toString() << '\n';
	}
	else {
		text << ' ' << '\n'; 
	}
	return text.str();
}



int Mapa::getCantCajas()
{
	return cantCajas;
}

void Mapa::cajasPendientes(int camb)
{
	if (camb > 0) {
		for (int i = 0; i < camb; i++){
			pilaCajas.push(1);
		}
			
	}
	else {
		pilaCajas.pop();
	}
}

void Mapa::setJugador(Nodo* jug)
{
	this->jugador = jug;
}

void Mapa::moverJugador(char move)
{
	switch (move) {
	case 'a': {
		if (jugador->validaMovimiento('a')) {
			mueveCaja(move);
			
			if (jugador->getIzquierda()->getPunto()) {
				if (!jugador->getPunto()){
					jugador->setCaracter('x');
					jugador->getIzquierda()->setCaracter('@');
				}
				else {
					jugador->setCaracter('.');
					jugador->getIzquierda()->setCaracter('@');
				}

			}
			else{
				if (jugador->getPunto()) {
					jugador->setCaracter('.');
					jugador->getIzquierda()->setCaracter('@');
				}
				else{
					jugador->setCaracter('x');
					jugador->getIzquierda()->setCaracter('@');
				}
				
			}
			
			jugador = jugador->getIzquierda();
		}
		break;
	}
	case 'd': {
		if (jugador->validaMovimiento('d')) {
			mueveCaja(move);
			

			if (jugador->getDerecha()->getPunto()) {
				if (!jugador->getPunto()) {
					jugador->setCaracter('x');
					jugador->getDerecha()->setCaracter('@');
				}
				else {
					jugador->setCaracter('.');
					jugador->getDerecha()->setCaracter('@');
				}

			}
			else {
				if (jugador->getPunto()) {
					jugador->setCaracter('.');
					jugador->getDerecha()->setCaracter('@');
				}
				else{
					jugador->setCaracter('x');
					jugador->getDerecha()->setCaracter('@');
				}
				
			}
			jugador = jugador->getDerecha();
		}
		break;
	}
	case 's': {
		if (jugador->validaMovimiento('s')) {
			mueveCaja(move);
			
			if (jugador->getAbajo()->getPunto()) {
				if (!jugador->getPunto()) {
					jugador->setCaracter('x');
					jugador->getAbajo()->setCaracter('@');
				}
				else {
					jugador->setCaracter('.');
					jugador->getAbajo()->setCaracter('@');
				}

			}
			else {
				if (jugador->getPunto()) {
					jugador->setCaracter('.');
					jugador->getAbajo()->setCaracter('@');
				}
				else {
					jugador->setCaracter('x');
					jugador->getAbajo()->setCaracter('@');
				}

			}
			jugador = jugador->getAbajo();
		}
		break;
	}
	case 'w': {
		if (jugador->validaMovimiento('w')) {
			mueveCaja(move);
			
			if (jugador->getArriba()->getPunto()) {
				if (!jugador->getPunto()) {
					jugador->setCaracter('x');
					jugador->getArriba()->setCaracter('@');
				}
				else {
					jugador->setCaracter('.');
					jugador->getArriba()->setCaracter('@');
				}

			}
			else {
				if (jugador->getPunto()) {
					jugador->setCaracter('.');
					jugador->getArriba()->setCaracter('@');
				}
				else {
					jugador->setCaracter('x');
					jugador->getArriba()->setCaracter('@');
				}

			}
			jugador = jugador->getArriba();
		}
		break;
	}
	default: {break; }
	}
}

std::vector<char> Mapa::getMovimientos()
{
	return moves;
}

void Mapa::ingresarMovimiento(char a)
{
	moves.push_back(a);
}

Nodo* Mapa::getJugador()
{
	return jugador;
}

void Mapa::mueveCaja(char lado)
{
	switch (lado) {
	case 'a': {
		if (jugador->getIzquierda()->getCaracter() == '$' || jugador->getIzquierda()->getCaracter() == '!') {
			if (jugador->getIzquierda()->getIzquierda()->getPunto()) {
				jugador->getIzquierda()->getIzquierda()->setCaracter('!');
				cajasPendientes(-1);
			}
			else { 
				if (jugador->getIzquierda()->getCaracter()=='!' && !jugador->getIzquierda()->getIzquierda()->getPunto()) { cajasPendientes(1); }
				jugador->getIzquierda()->getIzquierda()->setCaracter('$'); }

		}
		
		break;
	}
	case 'd': {
		if (jugador->getDerecha()->getCaracter() == '$' || jugador->getDerecha()->getCaracter() == '!') {
			if (jugador->getDerecha()->getDerecha()->getPunto()) {
				jugador->getDerecha()->getDerecha()->setCaracter('!');
				cajasPendientes(-1);
			}
			else { 
				if (jugador->getDerecha()->getCaracter() == '!' && !jugador->getDerecha()->getDerecha()->getPunto()) { cajasPendientes(1); }
				jugador->getDerecha()->getDerecha()->setCaracter('$'); }
		}
		break;
	}
	case 's': {
		if (jugador->getAbajo()->getCaracter() == '$' || jugador->getAbajo()->getCaracter() == '!') {
			if (jugador->getAbajo()->getAbajo()->getPunto()) {
				jugador->getAbajo()->getAbajo()->setCaracter('!');
				cajasPendientes(-1);
			}
			else { 
				if (jugador->getAbajo()->getCaracter() == '!' && !jugador->getAbajo()->getAbajo()->getPunto()) { cajasPendientes(1); }
				jugador->getAbajo()->getAbajo()->setCaracter('$'); 
			}

		}
			
		break;
	}
	case 'w': {
		if (jugador->getArriba()->getCaracter() == '$' || jugador->getArriba()->getCaracter() == '!') {
			if (jugador->getArriba()->getArriba()->getPunto()) {
				jugador->getArriba()->getArriba()->setCaracter('!');
				cajasPendientes(-1);
			}
			else { 
				if (jugador->getArriba()->getCaracter() == '!' && !jugador->getArriba()->getArriba()->getPunto()) { cajasPendientes(1); }
				jugador->getArriba()->getArriba()->setCaracter('$'); 
			}

		}
		break;
	}
	default: {break; }
	}
}


bool Mapa::ganador()
{
	if (pilaCajas.empty()){
		return true;
	}
	else{ return false; }
}

void Mapa::setMovimientos(std::vector<char> movimientos)
{
	moves = movimientos; 
}

