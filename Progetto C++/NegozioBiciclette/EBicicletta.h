/*
 * Nome : EBicicletta.h
 * Autore : Ferrari Lorenzo
 * Descrizione : Header della classe derivata che rappresenta una Bicicletta Elettrica
 */


#ifndef EBICICLETTA_H_
#define EBICICLETTA_H_

#include "Bicicletta.h"

class EBicicletta: public virtual Bicicletta {
public:
	EBicicletta(int velocitaIN,int capBatteriaIN);
	EBicicletta();
	EBicicletta(char *materialeIN, int pesoIN, int dim_cerchioIN, int prezzoIN,int velocitaIN, int capBatteriaIN);

	//Implementazione polimorfismo run time
	virtual void getInfo();
	virtual string getTipo();
	virtual void printSpecific();

	short getVelocita();
	short getCapBatteria();

		/*
		 * il distruttore virtual della classe derivata
		 * permette di invocare il distruttore della classe
		 * base, cioè Bicicletta
		 */
	virtual ~EBicicletta();

private:
	unsigned short int velocita; //indica la velocità massiama che la bicicletta può raggiungere (in Km/h)
	unsigned short int capBatteria; //indica la dimensione massima della batteria della bicicletta (in Kwh)

	static unsigned const int velocitaST = 15;
	static unsigned const int capBatteriaST = 30;
};

#endif /* EBICICLETTA_H_ */
