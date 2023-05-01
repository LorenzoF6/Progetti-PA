/*
 * Nome : MTBicicletta.h
 * Autore : Ferrari Lorenzo
 * Descrizione : Implementazione della classe derivata CBicicletta
 */
#include "CBicicletta.h"
#include "MTBicicletta.h"
#include "EBicicletta.h"


#include <iostream>
#include <cstring>
using namespace std;

CBicicletta::CBicicletta(): Bicicletta(),MTBicicletta(),EBicicletta::EBicicletta() {
	 tipoFreno = CBicicletta::tipoFrenoST;
}

CBicicletta::CBicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN, int rapportiIN, int velocitaIN,int capBatteriaIN, int tipoFrenoIN) :
			Bicicletta(materialeIN,pesoIN,dim_cerchioIN,prezzoIN),MTBicicletta(rapportiIN),EBicicletta::EBicicletta(velocitaIN,capBatteriaIN){
	tipoFreno = tipoFrenoIN;
}

void CBicicletta::getInfo(){
	cout << "Bicicletta da Corsa:" << endl;
	Bicicletta::getInfo();
	MTBicicletta::printSpecific(); // Risoluzione esplicita del name clashing
	EBicicletta::printSpecific();
	CBicicletta::printSpecific();
}

void CBicicletta::printSpecific(){
	if(CBicicletta::getTipoFreno() == 1) cout << "Tipologia di freno: Architetto";
	else if(CBicicletta::getTipoFreno() == 2) cout << "Tipologia di freno: U-Braker";
	else if(CBicicletta::getTipoFreno() == 3) cout << "Tipologia di freno: V-Braker";
	else cout << "Tipologia di freno: NON SUPPORTATO";
	cout << "\n";
}

string CBicicletta::getTipo(){ return "C";}

int CBicicletta::getTipoFreno(){ return tipoFreno; }

CBicicletta::~CBicicletta() { cout << "Rimozione biciclette da corsa" << endl; }







