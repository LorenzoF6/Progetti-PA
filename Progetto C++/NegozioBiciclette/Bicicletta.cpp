/*
 * Nome : Bicicletta.cpp
 * Autore : Ferrari Lorenzo
 * Descrizione : Implementazione della classe Bicicletta.h
 */

#include "Bicicletta.h"
using namespace std;
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <cstring>

const char* Bicicletta::materialeST = "carbonio";

//Bicicletta inizializzata a valori generici (esempio definiti dal venditore)
Bicicletta::Bicicletta() {
	materiale = strcpy((char*)malloc(sizeof(char)*strlen(Bicicletta::materialeST)),Bicicletta::materialeST);
	peso = Bicicletta::pesoST;
	dim_cerchio = Bicicletta::dim_cerchioST;
	prezzo = Bicicletta::prezzoST;
	telaio = new string();
	*telaio = generaTelaio();
}
//Bicicletta inizializzata basandosi sui parametri forniti in ingresso
Bicicletta::Bicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN):
		 peso(pesoIN), dim_cerchio(dim_cerchioIN), prezzo(prezzoIN) {

	materiale = (char*)malloc(sizeof(char)*Bicicletta::DIM_MAX_MAT_NAME);
	strcpy(materiale,materialeIN);
	telaio = new string();
	*telaio = Bicicletta::generaTelaio();

}

Bicicletta::Bicicletta(const Bicicletta &NuovaBicicletta) {
	strcpy(materiale, NuovaBicicletta.materiale);
	Bicicletta::dim_cerchio = NuovaBicicletta.dim_cerchio;
	Bicicletta::peso = NuovaBicicletta.peso;
	Bicicletta::prezzo = NuovaBicicletta.prezzo;
	Bicicletta::telaio = NuovaBicicletta.telaio;
}

string Bicicletta::generaTelaio(){
	string _t;
	srand(time(0));
	for(int i = 0;i < 5;i++){
		_t = _t + to_string(rand()%10);
	}
	return _t;
}
string Bicicletta::getNumTelaio(){ return *telaio;}

char* Bicicletta::getMateriale(){ return Bicicletta::materiale; }

short Bicicletta::getPeso(){ return Bicicletta::peso; }

double Bicicletta::getPrezzo(){ return Bicicletta::prezzo; }

short Bicicletta::getDimCerchio(){ return Bicicletta::dim_cerchio; }

void Bicicletta::getBiciInfo(Bicicletta &b)const{
	b.getInfo();
}

void Bicicletta::getInfo(){
	cout << "Informazioni Bicicletta:" << endl;
	cout << "Numero del telaio:" << getNumTelaio() << endl;
	cout << "Tipo di Materiale:" << getMateriale() << endl;
	cout << "Peso della bicicletta:" << getPeso() << " Kg" << endl;
	cout << "Dimensione del cerchio:" << getDimCerchio() << "mm" << endl;
	cout << "Costo della bicicletta:" << getPrezzo() << "euro" << endl;
}

Bicicletta::~Bicicletta() {
 free(materiale);
 delete telaio;
 cout << "Bicicletta rimossa" << endl;
}
