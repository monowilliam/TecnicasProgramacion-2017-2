#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//------INICIO DE LAS ESTRUCTURAS --------
struct ficha{  
	char simbolo;
	char etiqueta;
};
typedef struct ficha tipoFicha;


struct tablero{
	tipoFicha **matrix;	
};
typedef struct tablero tipoTablero;


struct juego{
	int score;
	int movimientos;
	char * nomJugador;
};
typedef struct juego tipoJuego;
//------FINAL ESTRUCTURAS--------


void inicializarTablero (tipoTablero &t, int N, int M, char *fichas, char *etiqueta){
	
	/*Descripción: Esta función se encarga de inicializar el tablero con sus respectivo 
					tamaño N x M.
	Entradas: Le entra una estructura tipoTablero t, con dos enteros N para el tamaño 
				las filas, y M para el tamaño de las columnas; un arreglo de Fichas: @#$%^&/*+=~?¡ y 
				de Etiquetas: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789,.- que se
				adaptan al tamaño de la matriz que viene en la estructura.
	Salidas: El tablero inicializado de N x M.*/
	
	t.matrix = new tipoFicha*[N];
	for (int i=0; i<N; i++){
		t.matrix[i] = new tipoFicha[M]; 
	}
	int k=0;
	for(int i=0; i<N; i++){
		int n=0;
		for(int j=0; j<M; j++){
			char smb= fichas[rand()%12];
			char etq= etiqueta[k++];
			t.matrix[i][j].simbolo=smb;
			t.matrix[i][j].etiqueta=etq;
		}
	}
}


void buscarTripletaHorizontal(tipoTablero &t, int N, int M, tipoJuego &j){
	
	/*Descripción: Esta función se encarga de buscar tres simbolos iguales en linea horizontal
					de la matriz de tamaño N x M y sumarle 10 puntos, y volver a llenar aleatoriamente
					estas posiciones.
	Entradas: Le entra la estructura tipoTablero t valida con dos enteros N para el tamaño 
				las filas, y M para el tamaño de las columnas, y tipoJuego j con datos validos con la información del puntaje.
	Salidas: Aumenta el puntaje de 10 puntos, junto con la tripleta horizontal aleatoria y sus respectivas
				posiciones.*/
	
	char fichas[] = "@#$%^&/*+=~?¡";
	for (int i=0; i<N; i++){
		for( int k=0; k<M-2; k++){
			if(t.matrix[i][k].simbolo == t.matrix[i][k+1].simbolo && t.matrix[i][k+1].simbolo== t.matrix[i][k+2].simbolo){
				cout << "Candy Horizontal en: "<<t.matrix[i][k].etiqueta<<"-"<<t.matrix[i][k+1].etiqueta<<"-"<<t.matrix[i][k+2].etiqueta <<" ¡Gana 10 Puntos!"<<"\n"<<endl;
				j.score=j.score+10;
				char smb= fichas[rand()%12]; 
				char smb1= fichas[rand()%12];
				char smb2= fichas[rand()%12];
				t.matrix[i][k].simbolo=smb;
				t.matrix[i][k+1].simbolo=smb1;
				t.matrix[i][k+2].simbolo=smb2;
			}
		}
	}
}


void buscarTripletaVertical(tipoTablero &t, int N, int M, tipoJuego &j){
	
	/*Descripción: Esta función se encarga de buscar tres simbolos iguales en linea vertical
					de la matriz de tamaño N x M y sumarle 10 puntos, y volver a llenar aleatoriamente
					estas posiciones.
	Entradas: Le entra la estructura tipoTablero t valida con dos enteros N para el tamaño 
				las filas, y M para el tamaño de las columnas, y tipoJuego j con datos validos con la información del puntaje.
	Salidas: Aumenta el puntaje de 10 puntos, junto con la tripleta horizontal aleatoria y sus respectivas
				posiciones.*/
	
	char fichas[] = "@#$%^&/*+=~?¡";
	for (int i=0; i<N-2; i++){
		for( int k=0; k<M; k++){
			if(t.matrix[i][k].simbolo == t.matrix[i+1][k].simbolo && t.matrix[i+1][k].simbolo== t.matrix[i+2][k].simbolo){
				cout << "Candy Vertical en: "<< t.matrix[i][k].etiqueta<<"-"<<t.matrix[i+1][k].etiqueta<<"-"<<t.matrix[i+2][k].etiqueta<< " ¡Gana 10 Puntos!"<< "\n"<<endl;
				j.score=j.score+10;
				char smb= fichas[rand()%12]; 
				char smb1= fichas[rand()%12];
				char smb2= fichas[rand()%12];
				t.matrix[i][k].simbolo=smb;
				t.matrix[i+1][k].simbolo=smb1;
				t.matrix[i+2][k].simbolo=smb2;
			}
		}
	}
}

void buscarDiagonal1(tipoTablero &t, int N, int M, tipoJuego &j){
	
	/*Descripción: Esta función se encarga de buscar tres simbolos iguales en linea vertical
					de la matriz de tamaño N x M y sumarle 10 puntos, y volver a llenar aleatoriamente
					estas posiciones.
	Entradas: Le dentra a la estructura tipoTablero y tipoJuego, con dos enteros N para el tamaño 
				las filas, y M para el tamaño de las columnas.
	Salidas: Aumenta el puntaje de 10 puntos, junto con la tripleta horizontal aleatoria y sus respectivas
				posiciones.*/
	char fichas[] = "@#$%^&/*+=~?¡";
	int bandera=1;
	int k=0;
	for (int i=0; i<N-1; i++){
		if(t.matrix[i][k].simbolo==t.matrix[i+1][k+1].simbolo){
			bandera=1;	
		}
		else{
			bandera=0;
			i=N+1;
		}
		k++;
	}
	if(bandera==1){
		j.score=j.score+100;
		char smb1= fichas[rand()%12];
		char smb2= fichas[rand()%12];
		t.matrix[0][0].simbolo=smb1;
		t.matrix[1][1].simbolo=smb2;
		cout<<"diagonal"<<endl;
	}
}

void dibujarTablero(tipoTablero &t, int N, int M, tipoJuego &j){
	
	/*Descripción: Esta funcion imprime todos los símbolos de las fichas, formando
					el tablero y busca las tripletas iguales horizontales y verticales.
	Entradas: Le dentra una estructura tipoTablero y tipoJuego junto con el tamaño de la matriz N y M.
	Salidas: Imprime el tablero dibujado dentro del juego y si hay tripletas iguales en horizontal y vertical.*/
	
	system("cls");
	buscarTripletaHorizontal(t,N,M,j);
	buscarTripletaVertical(t,N,M,j);
	buscarDiagonal1(t,N,M,j);
	cout<<endl ;
	cout<<"\t ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» "<<endl;
	cout<<"\t º           Candy Proyecto             º"<< endl ;
	cout<<"\t º ------ William y Juan Esteban ------ º "<< endl ;
	cout<<"\t ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ "<<endl<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << t.matrix[i][j].simbolo<<" "<<t.matrix[i][j].etiqueta << " \t ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}


tipoFicha *obtenerFicha(tipoTablero &t,int N, int M, char c){
	
	/*Descripción: Esta función se encarga de obtener por teclado las posiciones de las
					fichas.
	Entradas: Le dentra una estructura tipoTablero, y un caracter obtenido por leerMovimiento()
				en la posición [0] o [1].
	Salidas: Obtiene la posición de la ficha del tipoTablero. */
	
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if(t.matrix[i][j].etiqueta==c){
				return &t.matrix[i][j];
			}
		}
	}
	return NULL;
}


void nomJugador(tipoJuego &j){
	
	/*Descripción: Esta función se encarga de pedir el nombre del jugador cada vez que se inicie el juego.
	Entradas: Una estructura tipoJuego donde está el arreglo nomJugador.
	Salidas:  El nombre del jugador guardado en el arreglo nomJugador.*/
	
	cout<<"Digita el nombre del Jugador: ";
	cin>>j.nomJugador;
}


void imprControlador(tipoJuego &j){
	
	/*Descripción: Esta función se encarga de imprimir los movimientos y el puntaje del jugador y su nombre
					A lo largo del juego.
	Entradas: Una estructura tipoJuego.
	Salidas: Los movimientos restantes, el nombre del jugador y su puntaje.*/
	
	cout<<"\n Los movimientos restantes son: "<<j.movimientos<<endl;
	cout<<"\n El puntaje del jugador "<<j.nomJugador<<" es: "<<j.score<<endl<<endl;
}


void leerMovimiento(tipoJuego &j, tipoTablero &t, char *ar){

	/*Descripción: Esta función se encarga de obtener por teclado los valores de los movimientos y restarle 1 cada vez
					que se ejecute.
	Entradas: Una estructura tipoJuego y tipoTablero y un arreglo de dos caracteres.
	Salidas: Implementa imprControlador y obtiene los valores por teclado de las posiciones junto con sus movimientos. */
		
	imprControlador(j);
	for (int i=0; i<2; i++){
	cin>>ar[i];
	}
	j.movimientos=j.movimientos-1;
}


void swap(tipoFicha *f1, tipoFicha *f2){
	
	/*Descripción: Esta función se encarga de intercambiar las posiciones del valor
					de las fichas entradas por teclado.	
	Entradas: Le dentra dos estructuras tipoFichas que son guardadas en variables c1 y c2 
				implementadas en obtenerFicha.
	Salidas: devuelve las posiciones nuevas con sus cambios respectivos en fichas.*/

	cout<<f1->simbolo<<f2->simbolo<<endl;
	char temp;
	temp=f1->simbolo;
	f1->simbolo=f2->simbolo;
	f2->simbolo=temp;
	cout<<f1->simbolo<<f1->simbolo<<endl;
}


void ganadorFin(tipoJuego &j){
	
	/*Descripción: Esta funcion finaliza el juego al acabar los movimientos disponibles.
	Entradas: Le entra una estructura tipoJuego j inicializada correctamente, donde están los movimientos validos.
	Salidas: Imprime el nombre del jugador, y el puntaje total cuando se acaban los movimientos válidos. */
	
	system("cls");
	cout<<endl;
	cout<<"\t ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» "<<endl;
	cout<<"\t º  El puntaje TOTAL del jugador "<<j.nomJugador<<" es: "<<j.score<<endl;
	cout<<"\t ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ " << endl<< endl;
}
