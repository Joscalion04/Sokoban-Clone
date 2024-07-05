#include "Controladora.h"

void Controladora::control0()
{
    control1s();
}

int Controladora::control1()
{
    return Interfaz::menuPrincipal();
}

void Controladora::control1s()
{
    int op = 0;
    int aux = -1;
    do {
        op = control1();
        switch (op) {
        case 1: {
           aux = control3();
            if (Interfaz::map->ganador()&&aux==1) { control5(); }
            aux = -1; 
            break;
        }
        case 2: {
            aux = control4();
            if (Interfaz::map->ganador() && aux == 1) { control5(); }
            aux = -1; 
            break;
        }
        case 3: {
            Interfaz::mensajeSalida();
            break;
        }
        }
    } while (op != 3);
}

int Controladora::control2()
{
    return Interfaz::niveles();
}

int Controladora::control3()
{
    int op = control2();
    if (op != 0) {
        Interfaz::map = Interfaz::cargarNivel(op);
        Interfaz::imprimirPanel(Interfaz::map);
        Interfaz::jugar();
        return 1;
    }
    else
        return 0;
}

int  Controladora::control4()
{
    if (Interfaz::cargaPartidaGuardada()) {
        Interfaz::jugar();
        return 1; 
    }
    else {
        Interfaz::noHayPartida();
        return 0; 
    }
}



void Controladora::control5()
{
    int op = 0;
    int mapa = 0;
    while (op != 3) {
        if (Interfaz::map->ganador()) {
            op = Interfaz::menuNiveles();

            switch (op) {
            case 1:
                Interfaz::repeticion(Interfaz::map, Interfaz::numMap); break;
            case 2:
                mapa = Interfaz::numMap;
                if (mapa <= 2) {
                    mapa++;
                    delete Interfaz::map; 
                    Interfaz::map = Interfaz::cargarNivel(mapa);
                    Interfaz::imprimirPanel(Interfaz::map);
                    Interfaz::jugar();
                }
                else { Interfaz::finalJuego(); op = 3; }
                break;

            }
        }
        else {
            op = 3;
        }


    }
}
