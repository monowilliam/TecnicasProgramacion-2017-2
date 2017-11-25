#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//------INICIO DE LAS ESTRUCTURAS PRINCIPALES--------
struct ficha{  
	char simbolo;
	char etiqueta;
};
typedef struct ficha tipoFicha;


struct tablero{
	// int N=5, M=5;
	tipoFicha matrix[5][5];	
};
typedef struct tablero tipoTablero;


struct juego{
	int score;
	int movimientos;
	char * nomJugador;
};
typedef struct juego tipoJuego;
//------FINAL ESTRUCTURAS PRINCIPALES--------

void buscarTripletaHorizontal(tipoTablero &t, int N, int M, tipoJuego &j){
	char fichas[] = "@#$%*";
	for (int i=0; i<N; i++){
		for( int k=0; k<M-2; k++){
			if(t.matrix[i][k].simbolo == t.matrix[i][k+1].simbolo && t.matrix[i][k+1].simbolo== t.matrix[i][k+2].simbolo){
				cout << "Candy Horizontal en: "<<t.matrix[i][k].etiqueta<<"-"<<t.matrix[i][k+1].etiqueta<<"-"<<t.matrix[i][k+2].etiqueta <<" กGana 10 Puntos!"<<"\n"<<endl;
				j.score=j.score+10;
				char smb= fichas[rand()%5]; 
				char smb1= fichas[rand()%5];
				char smb2= fichas[rand()%5];
				t.matrix[i][k].simbolo=smb;
				t.matrix[i][k+1].simbolo=smb1;
				t.matrix[i][k+2].simbolo=smb2;
			}
		}
	}
}


void buscarTripletaVertical(tipoTablero &t, int N, int M, tipoJuego &j){
	char fichas[] = "@#$%*";
	for (int i=0; i<N-2; i++){
		for( int k=0; k<M; k++){
			if(t.matrix[i][k].simbolo == t.matrix[i+1][k].simbolo && t.matrix[i+1][k].simbolo== t.matrix[i+2][k].simbolo){
				cout << "Candy Vertical en: "<< t.matrix[i][k].etiqueta<<"-"<<t.matrix[i+1][k].etiqueta<<"-"<<t.matrix[i+2][k].etiqueta<< " กGana 10 Puntos!"<< "\n"<<endl;
				j.score=j.score+10;
				char smb= fichas[rand()%5]; 
				char smb1= fichas[rand()%5];
				char smb2= fichas[rand()%5];
				t.matrix[i][k].simbolo=smb;
				t.matrix[i+1][k].simbolo=smb1;
				t.matrix[i+2][k].simbolo=smb2;
			}
		}
	}
}


void inicializarTablero (tipoTablero &t, int N, int M, char *fichas, char *etiqueta){
	int k=0;
	for(int i=0; i<N; i++){
		int n=0;
		for(int j=0; j<M; j++){
			char smb= fichas[rand()%5];
			char etq= etiqueta[k++];
			t.matrix[i][j].simbolo=smb;
			t.matrix[i][j].etiqueta=etq;
		}
	}
}


void dibujarTablero(tipoTablero &t, int N, int M, tipoJuego &j){
	system("cls");
	buscarTripletaHorizontal(t,5,5,j);
	buscarTripletaVertical(t,5,5,j);
	cout<<endl ;
	cout<<"\t ษออออออออออออออออออออออออออออออออออออออป "<<endl;
	cout<<"\t บ           Candy Proyecto             บ"<< endl ;
	cout<<"\t บ ------ William y Juan Esteban ------ บ "<< endl ;
	cout<<"\t ศออออออออออออออออออออออออออออออออออออออผ "<<endl<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << t.matrix[i][j].simbolo<<" "<<t.matrix[i][j].etiqueta << " \t ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}


tipoFicha *obtenerFicha(tipoTablero &t, char c){
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			if(t.matrix[i][j].etiqueta==c){
				return &t.matrix[i][j];
			}
		}
	}
	return NULL;
}


void nomJugador(tipoJuego &j){
	cout<<"Digita el nombre del Jugador: ";
	cin>>j.nomJugador;
}


void imprControlador(tipoJuego &j){
	cout<<"\n Los movimientos restantes son: "<<j.movimientos<<endl;
	cout<<"\n El puntaje del jugador "<<j.nomJugador<<" es: "<<j.score<<endl<<endl;
}


void leerMovimiento(tipoJuego &j, tipoTablero &t, char *ar){
		imprControlador(j);
		for (int i=0; i<2; i++){
			cin>>ar[i];
		}
		j.movimientos=j.movimientos-1;

}


void swap(tipoFicha *f1,tipoFicha *f2){
	cout<<f1->simbolo<<f2->simbolo<<endl;
	char temp;
	temp=f1->simbolo;
	f1->simbolo=f2->simbolo;
	f2->simbolo=temp;
	cout<<f1->simbolo<<f1->simbolo<<endl;
}


void ganadorFin(tipoJuego &j){
	system("cls");
	cout<<endl;
	cout<<"\t ษออออออออออออออออออออออออออออออออออออออออออออป "<<endl;
	cout<<"\t บ  El puntaje TOTAL del jugador "<<j.nomJugador<<" es: "<<j.score<<endl;
	cout<<"\t ศออออออออออออออออออออออออออออออออออออออออออออผ " << endl<< endl;
}




