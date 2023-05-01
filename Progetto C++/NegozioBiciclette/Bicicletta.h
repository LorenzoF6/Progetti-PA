/*
 * Nome : Bicicletta.h
 * Autore : Ferrari Lorenzo
 * Descrizione : Header della classe principale Bicicletta
 */

#ifndef BICICLETTA_H_
#define BICICLETTA_H_

#include <string>
using namespace std;

class Bicicletta {
public:
	Bicicletta(); //Metodo costruttore della classe (Overload del costruttore)

	Bicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN); //Costruttore con parametri

	Bicicletta(const Bicicletta &other); //Definizione del copy constructor

	string getNumTelaio(); //Metodo per ottenere il numero del telaio

	char* getMateriale(); //Metodo per ottenere il materiale con il quale è stata realizzata la bicicletta

	short getPeso(); //Metodo per ottenere il peso della bicicletta

	short getDimCerchio(); //Metodo per ottenere la dimensioni dei cerchi

	double getPrezzo(); //Metodo per ottenere il prezzo della bicicletta

	void getBiciInfo(Bicicletta &b)const;

	/* Prefisso per implementare polimorfismo run-time.
	 * Notazione = 0 permette di implementare il metodo
	 * anche nelle classi derivate
	 */
	virtual void getInfo() = 0; //Informazioni sulla bicicletta

	virtual void printSpecific() = 0; // Informazioni specifiche della classe derivata

	virtual string getTipo() = 0; //Tipologia della bicicletta

	// Distruttore della classe
	virtual ~Bicicletta();

	private:
		string *telaio; // Numero del telaio della bicicletta
		char *materiale; // Materiale con cui è fatta la bicicletta (carbonio,titanio,alluminio)
		unsigned short int dim_cerchio; // Dimensioni dei cerchi della bicilcetta (in mm)
		unsigned short int peso; // Peso della bicicletta (in kg)
		double prezzo; // prezzo della bicicletta (in Euro)

		//Variabili statiche
		static unsigned const short dim_cerchioST = 24;
		static unsigned const short pesoST = 4 ;

		//Variabili costanti
		const double prezzoST = 300;
		static const char* materialeST;
		const unsigned int DIM_MAX_MAT_NAME = 20;

	protected :
		string generaTelaio();
};

#endif /* BICICLETTA_H_ */
