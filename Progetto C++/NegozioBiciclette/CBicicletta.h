/*
 * Nome : MTBicicletta.h
 * Autore : Ferrari Lorenzo
 * Descrizione : Header della classe derivata che rappresenta una Bicicletta da Corsa
 */


#ifndef CBICICLETTA_H_
#define CBICICLETTA_H_

#include "MTBicicletta.h"
#include "EBicicletta.h"

class CBicicletta:public MTBicicletta, public EBicicletta {
public:
	CBicicletta();
	CBicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN, int rapportiIN, int velocitaIN,int capBatteriaIN, int tipoFrenoIN);

	//Implementazione polimorfismo run time
	virtual void getInfo();
	virtual string getTipo();
	virtual void printSpecific();

	int getTipoFreno();

		/*
		 * il distruttore virtual della classe derivata
		 * permette di invocare il distruttore della classe
		 * base, cioè Bicicletta
		 */
	virtual ~CBicicletta();

private:
	unsigned int tipoFreno; //Indica la tipologia di freno montata sulla biciletta

	static unsigned const int tipoFrenoST = 1;
};




#endif /* CBICICLETTA_H_ */
