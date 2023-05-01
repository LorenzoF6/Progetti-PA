/*
 * Nome : Negozio.h
 * Autore : Ferrari Lorenzo
 * Descrizione : Header della classe Negozio che permette di operare con le diverse classi
 *
 */


#ifndef NEGOZIO_H_
#define NEGOZIO_H_
#include <vector>
#include <memory>
#include "Bicicletta.h"

/*
 * Classe Negozio implementata secondo il design pattern Singleton
 * in modo da garantire l'univocità dell'istanza di questa classe
 */
class Negozio {
public:
	static Negozio& getInstance(){
		static Negozio instance; //si garantisce la distruzione dell'istanza creata
		return instance;
	}

	/*
	 * Metodo che mi permette di creare una nuova bicicletta
	 * La funzione restituisce uno smart pointer che fa riferimento ad una
	 * bicicletta creata e la inserisce nel vettore STL
	 */
	void newBicicletta();

	void getBiciInfo(Bicicletta &b) const; //Metodo che fornisce le informazioni di una specidfica bicicletta presente in negozio

	void getListaBicicletta(); //Metodo che fornisce le informazioni di tutte le biciclette presenti in negozio

	//Esempio di funzione inline che restituisce il numero di biciclette presenti in negozio
	inline int getNumBicicletta(){
		return negozio.size();
	}

private:
	Negozio(); //Costruttore della classe Negozio

	Negozio(Negozio const&); //Copy constructor della classe negozio

	// Vettore STL di unique_ptr in cui ciascuno di essi punta ad una delle biciclette presenti in negozio
	// In questo modo si evita l'effetto slicing
	vector<unique_ptr<Bicicletta>> negozio;
};

#endif /* NEGOZIO_H_ */
