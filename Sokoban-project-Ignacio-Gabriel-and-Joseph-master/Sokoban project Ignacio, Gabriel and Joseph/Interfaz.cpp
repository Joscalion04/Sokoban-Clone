#include "Interfaz.h"
#include<iomanip>
#include<mmsystem.h>

#pragma comment(lib, "winmm.lib")

Mapa* Interfaz::map = new Mapa();
int Interfaz::numMap = 0;

int Interfaz::menuPrincipal()
{
    system("cls");
    PlaySound(TEXT("Ambiente.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    std::string op = " ";
    std::cout<<std::setw(70) << "\033[33m     -----------------------------Sokoban-----------------------------" << '\n';
    std::cout << std::setw(70) << "|        Press (1): Nueva Partida                               |" << '\n';
    std::cout << std::setw(70) << "|        Press (2): Cargar ultima Partida                       |" << '\n';
    std::cout << std::setw(70) << "|        Press (3): Salir                                       |" << '\n';
    std::cout << std::setw(50) << "     -----------------------------Sokoban-----------------------------\033[0m" << '\n';
    std::cin >> op;

    system("cls");
    return validaEntrada(op);
}

int Interfaz::menuNiveles()
{
    system("cls");
    std::string op = " ";
    std::cout << std::setw(50) << "\033[33m        -----------------------------Sokoban-----------------------------" << '\n';
    std::cout << std::setw(50) << "        |        Press (1): Ver repeticion                               |" << '\n';
    std::cout << std::setw(50) << "        |        Press (2): Siguiente nivel                              |" << '\n';
    std::cout << std::setw(50) << "        |        Press (3): Salir                                        |" << '\n';
    std::cout << std::setw(50) << "        -----------------------------Sokoban-----------------------------\033[0m" << '\n';
    std::cin >> op;

    system("cls");
    return validaEntrada(op); 
}

void Interfaz::finalJuego()
{
    colores("HAS FINALIZADO EL ULTIMO NIVEL"); 
}



int Interfaz::niveles()
{
    std::string op = " ";
    std::cout << std::setw(50) << "\033[33m        -----------------------------Sokoban-----------------------------" << '\n';
    std::cout << std::setw(50) << "        |        Press (1): Nivel 1                                     |" << '\n';
    std::cout << std::setw(50) << "        |        Press (2): Nivel 2                                     |" << '\n';
    std::cout << std::setw(50) << "        |        Press (3): Nivel 3                                     |" << '\n';
    std::cout << std::setw(50) << "        -----------------------------Sokoban-----------------------------\033[0m" << '\n';
    std::cin >> op;
    return validaEntrada(op);
}

inline Mapa* Interfaz::cargarNivel(int op)
{
    switch (op) {
    case 1: {
        numMap = 1;
        PlaySound(TEXT("Lv1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        return leeMapa("../Nivel1.txt");
        break;
    }
    case 2: {
        numMap = 2;
        PlaySound(TEXT("Lv2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        return leeMapa("../Nivel2.txt");
        break;
    }
    case 3: {
        numMap = 3;
        PlaySound(TEXT("Lv3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        return leeMapa("../Nivel3.txt");
        break;
    }
    default: {

        break; }
    }
}



std::string Interfaz::controles()
{
    std::stringstream s;
    s << "\033[33m*************************************************** \033[0m" << '\n';
    s << "\033[33m* w: arriba  a: izquierda  s: abajo  d: derecha   * \033[0m" << '\n';
    s << "\033[33m* r: reiniciar nivel  m: MENU                     * \033[0m" << '\n';
    s << "\033[33m* g: guardar el nivel                             * \033[0m" << '\n';
    s << "\033[33m*************************************************** \033[0m" << '\n';
    return s.str();
}

void Interfaz::imprimirPanel(Mapa* map)
{

    std::stringstream s;
    s << "\033[31m";
    s << map->imprimir() << "\033[0m" << '\n';
    s << controles();
    std::cout << s.str();
}



void Interfaz::repeticion(Mapa* map, int num)
{
    Mapa* Aux = cargarNivel(num);
    imprimirPanel(Aux);
    for (int i = 0; i < map->getMovimientos().size(); i++) {
        Aux->moverJugador(map->getMovimientos().at(i));
        Sleep(500);
        imprimirPanel(Aux);
    }
}

void Interfaz::jugar()
{

    char a;
    while (true) {
        a = _getch();
        if (a == 'r') {
            delete map;
            map = cargarNivel(numMap);
        }
        if (a == 'g') {
            guardarPartida(map, numMap);
        }
        if (a == 'm') {
            break; 
        }
        
        map->moverJugador(a);
        imprimirPanel(map);
        map->ingresarMovimiento(a);
        if (map->ganador()) {
            map->ingresarMovimiento(a);
            imprimirPanel(map);
            Sleep(100); 
            system("cls");
            mensajeGane();
            break;
        }
        if (a != 'w' && a != 'a' && a != 's' && a != 'd' && a != 'r' && a!='m' && a!='g') {
        }
       
    }
}

void Interfaz::mensajeSalida()
{
    colores("Gracias por jugar nuestro videojuego"); 
}

void Interfaz::mensajeGane() {

    PlaySound(TEXT("Victoria.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    colores("¡Excelente has ganado el nivel"); 
    PlaySound(TEXT("Ambiente.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Interfaz::colores(std::string texto)
{
    for (int i = 0; i < 6; i++) {
        switch (i) {
        case 0: {
            std::cout << std::setw(70) << "\033[31m"<<texto<<"\033[0m"<<'\n';
            Sleep(150);
            system("cls");
            break;
        }
        case 1: {
            std::cout << std::setw(70) << "\033[32m" << texto << "\033[0m" << '\n';
            Sleep(150);
            system("cls");
            break;
        }
        case 2: {
            std::cout << std::setw(70) << "\033[33m" << texto << "\033[0m" << '\n';
            Sleep(150);
            system("cls");
            break;
        }
        case 3: {
            std::cout << std::setw(70) << "\033[34m" << texto << "\033[0m" << '\n';
            Sleep(150);
            system("cls");
            break;
        }
        case 4: {
            std::cout << std::setw(70) << "\033[35m" << texto << "\033[0m" << '\n';
            Sleep(150);
            system("cls");
            break;
        }
        case 5: {
            std::cout << std::setw(70) << "\033[36m" << texto << "\033[0m" << '\n';
            Sleep(150);
            system("pause");
            break;
        }
        }
    }
}

int Interfaz::validaEntrada(std::string entrada)
{
    int op = 0; 
    for (char c : entrada) {
        if (!std::isxdigit(c))
            return op; 
    }
    
    op = convierteInt(entrada);
    if (op > 0 && op <= 3)
        return op;
    else
        return 0; 
}

void Interfaz::noHayPartida()
{
    colores("No hay ninguna partida guarda"); 
}

bool Interfaz::cargaPartidaGuardada() {

    std::ifstream entrada;
    entrada.open("../partidaGuardada.txt");
    std::string val;
    int num;
    char move;
    std::vector<char> moves;
    std::getline(entrada, val, '\n');
    num = convierteInt(val);
    if (num != 0) {
        map = cargarNivel(num);
        while (entrada.good()) {
            std::getline(entrada, val, '\t');
            move = convierteChar(val);
            moves.push_back(move);
        }
        map->setMovimientos(moves);
        for (int i = 0; i < moves.size(); i++) {
            map->moverJugador(moves.at(i));
            Sleep(50);
            imprimirPanel(map);
        }
        return true;
    }
    else
        return false; 
}





