package negozioBiciclette;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Negozio{
	
	//Implementazione del pattern Singleton per classe Negozio
	private static Negozio nInstance = null;
	
	//Attributo e costruttore della classe privati
	private ArrayList<Bicicletta> negozio;
	private Negozio(){ negozio = new ArrayList<Bicicletta>(); }

	//Gestione elaborazione pattern Singleton
    public static Negozio instance () {
    	if ( nInstance == null )
    		 nInstance = new Negozio();
    	return nInstance ;
	}
 
	//Metodi per la gestione del negozio
    //Inserimento con ordianmento selezionato dall'utente
	public void aggiungiBicicletta(Bicicletta b) { 
		negozio.add(b);
		Collections.sort(negozio);;
	}
	
	public Bicicletta prendiBicicletta(int posizione) { return negozio.get(posizione); 	}
	public int dimensioneNegozio() { return negozio.size(); }
	
	//Esempi di ricerca all'interno della della collezione che forniscono come 
	// una stringa contenente tutte le biciclette che corrispondono al valore fornito inn ingresso
	
	// -- Ricerca per prezzo
	public String cercaBicicletta(double _prezzo) {
		String s = "";
		for(Bicicletta b: negozio) {
			if(b.getPrezzo() == _prezzo)
				s = s + b.toString();
		}
		return s;
	}
	
	// -- Ricerca per peso
	public String cercaBicicletta(int _peso) {
		String s = "";
		for(Bicicletta b: negozio) {
			if(b.getPeso() == _peso)
				s = s + b.toString();
		}
		return s;
	}
	
	// -- Ricerca per tipo di Bicicletta ed utilizzo del metodo equals 
	public String cercaBicicletta(String tipo) {
		String s = "";
		for(Bicicletta b: negozio) {
			if(b.getTipo().equals(tipo))
				s = s + b.toString();
		}
		return s;
	}
	
	//Overload del metodo cercaBicicletta()
	
	//Utilizzo degli iteratori per scandire la lista di biciclette
	public String getInfoNegozio() {
		String s = "";
		Iterator<Bicicletta> n = negozio.iterator();
		while(n.hasNext()) {
			s = s + n.next().toString() + " \n";
		}
		return s;
	}

}
