/**
 * @author: Lorenzo Ferrari
 * Desctizione: classe derivata dalla classe Bicicletta
 */
package negozioBiciclette;
import java.util.ArrayList;
import java.util.List;

public class MTBicicletta extends Bicicletta implements MTBInterface {

	//Campi della classe
	private int rapporti;
	private List<String> sticker; 
	
	//Uso della clausola super() per richiamare il costruttore della super classe
	public MTBicicletta() {
		super();
		sticker = new ArrayList<String>();
		this.rapporti = rapportiD;
	}
	
	public MTBicicletta(String materiale, double prezzo, int peso, int dim_cerchio, int rapporti) {
		super(materiale,prezzo,peso,dim_cerchio);
		sticker = new ArrayList<String>();
		this.rapporti = rapporti;
	}

	// Metodo che ritorna il parametro privato della classe derivata
	@Override
	public int getRapporti() { return this.rapporti; } 
	
	//Utilizzo di Varargs in Java
	//Si possono attaccare più sticker alla bicicletta
	@Override
	public void setSticker(String ... stickers) {
		for(String s: stickers)
			sticker.add(s);
	}
	public void setSticker(String _sticker) {sticker.add(_sticker);}
	
	@Override
	public int getNumSticker() { return sticker.size(); }
	
	//Implementazione del metodi astratti della classe base
	@Override
	String getTipo() {
		return "MTB";
	}
	
	//toString specifico per la classe derivata	
	public String toString() {
		return super.toString() + " " + printSpecific();
	}
		
	@Override
	String printSpecific() {
		return "\n"+"Rapporti: " + this.rapporti + "\n" 
			   + "Stickers: " + sticker.toString() +"\n";
	}
		
	//Esempio di utilizzo dell'interfaccia applicata al confronto tra i prezzi di due biciclette diverse
	@Override
	public int compareTo(Bicicletta o) {
		if (this.getPrezzo()> o.getPrezzo())
			return 1;
		else if(this.getPrezzo() == o.getPrezzo())
			return 0;
		else
			return -1;
	}
}
