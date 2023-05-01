/*
 * Negozio.cpp
 *
 *  Created on: 11 mar 2023
 *      Author: loren
 */

#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include "Negozio.h"
#include "Bicicletta.h"
#include "MTBicicletta.h"
#include "EBicicletta.h"
#include "CBicicletta.h"
using namespace std;

Negozio::Negozio() {
}

void Negozio::newBicicletta(){
	int peso, dim_cerchio, tipo;
	double prezzo;
	string materiale;
	cout << "Inserire una nuova bicicletta:\n" << endl;

	cout << "Peso: " ;
	cin >> peso;
	cout << "Dimensione cerchio delle ruote: ";
	cin >> dim_cerchio;

	cout << "prezzo: ";
	cin >> prezzo;

	cout << "Materiale con cui è fatta (carbonio,titanio,alluminio): ";
	cin >> materiale;

	char* materiale_pt = (char*)malloc(sizeof(char)*materiale.length());
	strcpy(materiale_pt,materiale.data());
	cout << endl;
	cout << "Tipo di Bicicletta da inserire : ";
	cin >> tipo;
	cout << endl;
	switch(tipo){
		//caso MTB
		case 0:{
			int rapporti;
			cout << "Numero di rapporti del cambio: ";
			cin >> rapporti;
			cout << "\n";
			cout << "Creazione Bicicletta da Montagna" << "\n";
			unique_ptr<Bicicletta> MTB_pt(new MTBicicletta(materiale_pt,peso,dim_cerchio,prezzo,rapporti));
			negozio.push_back(move(MTB_pt));
			cout << "Bicicletta da Montagna aggiunta\n";
			break;
		}
		//caso EB
		case 1:{
			int velocita, capBatteria;
			cout << "Velocita massima raggiunta dalla bici:";
			cin >> velocita;
			cout << "Capacità batteria della bicicletta:";
			cin >> capBatteria;
			cout << "Creazione Bicicletta Elettrica" << "\n";
			unique_ptr<Bicicletta> EB_pt(new EBicicletta(materiale_pt,peso,dim_cerchio,prezzo,velocita,capBatteria));
			negozio.push_back(move(EB_pt));
			cout << "Bicicletta elettrica aggiunta";
			break;
		}
		//caso CB
		case 2:{
			int tipoFreno, rapporti, velocita;
			cout << "Tipologia di freno della bicicletta (1,2,3): ";
			cin >> tipoFreno;
			cout << "Numero di rapporti bicicletta: ";
			cin >> rapporti;
			cout << "Velocità massima raggiunta dalla bicicletta: ";
			cin >> velocita;
			cout << "Creazione Bicicletta da Corsa" << "\n";
			unique_ptr<Bicicletta> CB_pt(new CBicicletta(materiale_pt,peso,dim_cerchio,prezzo,rapporti,velocita,0,tipoFreno));
			negozio.push_back(move(CB_pt));
			cout << "Bicicletta da corsa aggiunta";
			break;
		}
		default:{
			//Eccezzione nel caso l'utente non inserisca il tipo corretto;
			throw 403;
		}
	}

	free(materiale_pt);
}

void Negozio::getBiciInfo(Bicicletta &b)const {
	b.getInfo();
}

void Negozio::getListaBicicletta(){
	cout << "\n";
	cout << "Informazioni BICICLETTE presenti in Negozio:\n";
	for(auto const &n : negozio){ // Iterazione lungo il vettore di Biciclette
			n.get()->getInfo();
			cout << "\n";
	}
}
