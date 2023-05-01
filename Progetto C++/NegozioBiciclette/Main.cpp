/*
 * Nome : Main.cpp
 * Autore : Lorenzo Ferrari
 * Descrizione : Classe main per testare il progetto
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include "Bicicletta.h"
#include "MTBicicletta.h"
#include "EBicicletta.h"
#include "Negozio.h"
using namespace std;

int main(){

	// creazione dell'istanza di negozio seguendo il design pattern specificato prima
	Negozio &n = Negozio::getInstance();

	bool continua = true;
	char car;

	while(continua){
		cout << "Inserisci una bicicletta:" << endl;
			try {
				n.newBicicletta();
				cout << endl;
				n.getListaBicicletta();
			}catch (int x){
				cout << "Tipologia di bicicletta non presente" << endl;
			}
		cout << "Vuoi inserire un nuova bicicletta: (Y: si, N:no)" << endl;
		cin >> car;
		if(toupper(car) == 'N') continua = false;
	}
}

