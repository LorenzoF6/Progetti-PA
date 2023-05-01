/*
 * Nome : EBicicletta.cpp
 * Autore : Ferrari Lorenzo
 * Descrizione : Implementazione della classe derivata che rappresenta una Bicicletta Elettrica
 */


#include "EBicicletta.h"
#include <iostream>
using namespace std;

EBicicletta::EBicicletta(): Bicicletta() {
	velocita = EBicicletta::velocitaST;
	capBatteria = EBicicletta::capBatteriaST;
}


EBicicletta::EBicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN,int velocitaIN, int capBatteriaIN):
		Bicicletta(materialeIN,pesoIN,dim_cerchioIN,prezzoIN), velocita(velocitaIN), capBatteria(capBatteriaIN){
}

EBicicletta::EBicicletta(int velocitaIn,int capBatteriaIN): Bicicletta() {
	velocita = velocitaIn;
	capBatteria = capBatteriaIN;
}

void EBicicletta::getInfo(){
	cout << "Bicicletta Elettrica:" << endl;
	Bicicletta::getInfo();
	EBicicletta::printSpecific();
}

void EBicicletta::printSpecific(){
	cout << "Velocità: " << getVelocita() << endl;
	cout << "Capacità batteria: " << getCapBatteria() << endl;
}

string EBicicletta::getTipo(){ return "EB";}

short EBicicletta::getVelocita(){ return velocita; }

short EBicicletta::getCapBatteria(){ return capBatteria; }

EBicicletta::~EBicicletta(){ cout << "Rimozione delle bicicletta elettrica" << endl; }
