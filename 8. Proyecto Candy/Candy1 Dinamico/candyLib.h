#ifndef CANDYLIB_H_INCLUDED
#define CANDYLIB_H_INCLUDED

struct ficha;
struct tablero;
struct juego;

void inicializarTablero (tipoTablero &t, int N, int M, char *fichas, char *etiqueta);
void buscarTripletaHorizontal(tipoTablero &t, int N, int M, tipoJuego &j);
void buscarTripletaVertical(tipoTablero &t, int N, int M, tipoJuego &j);
void buscarDiagonal1(tipoTablero &t, int N, int M, tipoJuego &j);
void dibujarTablero(tipoTablero &t, int N, int M, tipoJuego &j);
tipoFicha *obtenerFicha(tipoTablero &t,int N, int M, char c);
void nomJugador(tipoJuego &j);
void imprControlador(tipoJuego &j);
void leerMovimiento(tipoJuego &j, tipoTablero &t, char *ar);
void swap(tipoFicha *f1,tipoFicha *f2);
void ganadorFin(tipoJuego &j);


#endif // CANDYLIB_H_INCLUDED
