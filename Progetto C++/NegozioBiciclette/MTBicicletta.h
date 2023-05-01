/*
 * Nome : MTBicicletta.h
 * Autore : Ferrari Lorenzo
 * Descrizione : Header della classe derivata che rappresenta una Bicicletta da Montagna
 */


#ifndef MTBICICLETTA_H_
#define MTBICICLETTA_H_

#include "Bicicletta.h"

class MTBicicletta: public virtual Bicicletta {
public:

	//Costruttori della classe derivata
	MTBicicletta(int rapportiIN);
	MTBicicletta();
	MTBicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN, int rapportiIN);

	//Implementazione polimorfismo run time
	virtual void getInfo();
	virtual string getTipo();
	virtual void printSpecific();

	short getRapporti();

	/*
	 * il distruttore virtual della classe derivata
	 * permette di invocare il distruttore della classe
	 * base, cioè Bicicletta
	 */
	virtual ~MTBicicletta();

private:
	unsigned short int rapporti; //indica il numero di rapporti che ha la bicicletta

	unsigned short const int rapportiST = 7;
};

#endif /* MTBICICLETTA_H_ */
