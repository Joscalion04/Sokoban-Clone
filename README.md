# Sokoban-Clone
Este repositorio contiene un proyecto universitario desarrollado en C++ cuyo objetivo es aplicar estructuras de datos dinámicas para simular el conocido juego Sokoban de manera sencilla en la consola.

## Objetivos
El objetivo de este proyecto es desarrollar un clon del popoular juego "Sokoban" haciendo enfasis en la aplicacion de estructuras de datos dinamicas que proporciona el lenguaje C++ mediante los punteros simulando un grid de lista enlazada multiple con construccion dinamica mediante mecanismos de recursividad e iteracion segun sea mas eficiente.

## Características

### Manejo de Interfaz
- **Modelo de Controlador Simple:** Utiliza un modelo de controlador sencillo con wrappers para manejar los recursos.
- **Creación de Interfaz Simple:** Se ha implementado una interfaz básica en la consola usando el wrapper del controlador.
- **Diseño de Interfaz:** La interfaz del juego incluye colores y música para mejorar la experiencia tipo arcade.
- **Construcción del Grid en Pantalla:** El grid dinámico se genera mediante un algoritmo de iteración dividida y evaluación constante, asegurando una representación precisa del estado del juego en la pantalla.

### Construccion del Grid Dinamico
- **Diseño del Grid** Se crea una estructura de datos de tipo grid dinamico mediante una lista enlazada multiple con nodos de direccion cuadruple.
- **Lectura de Persistencia:** Los mapas son almacenado en archivos txt, permitiendo agregar mas niveles en futuro, los archivos txt mantienen un patron de cifrado para lectura simple en el prrograma.
- **Construccion del Grid:** El grid dinamico se crea utilizando un algoritmo de iteracion dividida y constante evaluacion para una coherencia de informacion acorde a la creacion del mapa seleccionado.
- **Destruccion del Grid** La destruccion del grid dinamico se disena mediante algoritmos de iteracion dividida e sentido contrario y reconstruccion del grid en tiempo de eliminacion.

## Algoritmos y Diseño del Programa
- **Algoritmos de Impresion:** Se mantienen algortimos de iteracion dividida y recursividad simple para la impresion de grids e informacion en pantalla.
- **Algortimos de Construccion:** Se mantienen algortimos de iteracion dividida y recursividad simple para la creacion y lectura de datos dinamicos en el programa.
- **Estructruas de Datos de lJuego:** El juego mantiene estruturas de datos dinamicas mediante punteros con informacion simple.
- **Tecnicas de Diseño del Juego:** El juego mantiene tecnicas de diseño simples como el uso de banderas booleanas, manejo de datos primitivos y controladores de flujo condicionales.

## Tecnologías Utilizadas
- **Lenguaje de Programación:** C++
- **Librerias:**
    - **Persistencia de Datos:** fstream
    - **API de Multimedia:** mmsystem
    - **API de Windows:** windows
    - **Control de Flujo y Memoria:** iomanip, iosfwd, conio

## Creditos

Este repositorio fue realizado como proyecto universitario.
Integrantes:
 - Ignacio Bonilla Rojas
 - Gabriel Robleto
 - Joseph Leon Cabezas (Joscalion04)
