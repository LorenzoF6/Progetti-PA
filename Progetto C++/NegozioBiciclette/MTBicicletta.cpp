/*
 * Nome : MTBicicletta.cpp
 * Autore : Ferrari Lorenzo
 * Descrizione : Implementazione della classe derivata che rappresenta
 * una Bicicletta da Montagna
 */


#include "MTBicicletta.h"
#include <iostream>
using namespace std;

MTBicicletta::MTBicicletta(): Bicicletta() {
	rapporti = MTBicicletta::rapportiST;
}

MTBicicletta::MTBicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN, int rapportiIN) :
			Bicicletta(materialeIN,pesoIN,dim_cerchioIN,prezzoIN), rapporti(rapportiIN){
}

MTBicicletta::MTBicicletta(int rapportiIN): Bicicletta() {
	rapporti = rapportiIN;
}

void MTBicicletta::getInfo(){
	cout << "Bicicletta da Montagna:" << endl;
	Bicicletta::getInfo();
	MTBicicletta::printSpecific();
}

void MTBicicletta::printSpecific(){
	cout << "Numero rapporti: " << getRapporti() << endl;
}

string MTBicicletta::getTipo(){ return "MTB";}

short MTBicicletta::getRapporti(){ return rapporti; }

MTBicicletta::~MTBicicletta() { cout << "Rimozione bicicletta da montagna" << endl; }

