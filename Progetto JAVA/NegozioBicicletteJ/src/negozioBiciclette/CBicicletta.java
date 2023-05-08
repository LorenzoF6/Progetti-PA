/**
 * @author: Lorenzo Ferrari
 * Desctizione: classe derivata dalla classe Bicicletta che mediante interfacce implmenta l' 'ereditarietà multipla' dalle classi MTBicicletta e EBicicletta
 */
package negozioBiciclette;
import java.util.ArrayList;
import java.util.List;

public class CBicicletta extends Bicicletta implements MTBInterface,EBInterface {

	// Campo effettivo della classe derivaata
	private int tipoFreno;
	
	//Campo Statico & Default effettivo della classe 
	private static final int tipoFrenoD = 1;
	
	/** Campi delle due classe MTBicicletta E EBiciclcetta aggiunti in quanto,
		non potendo applicare l'ereditarietà multipla in Java, posso fare 'ereditare' 
		i metodi mediante l'implementazione di interfacce ad hoc, mentre i paramentri delle 
		altre due sottoclassi devono essere ricopiati e creati dalla stessa classe CBicicletta.
	**/
	//Campi delle calssi MTBicicletta e EBicicletta che devono essere istanziati direttamente da CBicicletta
		private int velocita;
		private int capBatteria;
		private int rapporti;
		private List<String> sticker;
		
	//Costruttore di default della classe derivata
	public CBicicletta(){
		super();
		velocita = velocitaD;
		capBatteria = 0;
		rapporti = rapportiD;
		tipoFreno = tipoFrenoD;
	}
	
	//Overload del costruttore
	public CBicicletta(String materiale, double prezzo, int peso, int dim_cerchio, int rapporti, int velocita, int tipoFreno) {
		super(materiale,prezzo,peso,dim_cerchio);
		this.tipoFreno = tipoFreno;
		
		sticker = new ArrayList<String>();
		this.rapporti = rapporti;

		this.velocita = velocita;
		this.capBatteria = 0;
	}
	
	@Override
	public int compareTo(Bicicletta o) {
		if (this.getPrezzo()> o.getPrezzo())
			return 1;
		else if(this.getPrezzo() == o.getPrezzo())
			return 0;
		else
			return -1;
	}

	@Override
	String getTipo() { return "C"; }

	@Override
	String printSpecific() {
		return "Velocita: " + this.velocita + "\n" + "Capacità batteria: " + this.capBatteria + "\n" +
				"Rapporti: " + this.rapporti + "\n" + "Stickers: " + sticker.toString() +"\n" +
				"Tipologia freno: " + this.getTipoFreno() + "\n";
	}

	String getTipoFreno() {
		String result = "";
		switch(this.tipoFreno) {
		case 1: result = "Architetto"; break;
		case 2: result =  "U-brake"; break;
		case 3: result = "V-brake"; break;
		}
		return result;
	}
	
	//toString della classe della derivata
	public String toString() {
		return super.toString() + " " + printSpecific();
	}
	
	// Metodi 'ereditati' dalla classe EBicicletta
	@Override
	public int getVelocita() { return this.velocita; }
	
	@Override
	public int getCapBatteria() { return this.capBatteria; }

	//Metodi 'ereditati' dalla classe MTBicicletta
	@Override
	public int getRapporti() { return this.rapporti; }

	@Override
	public int getNumSticker() { return sticker.size();	}

	@Override
	public void setSticker(String... stickers) {
		for(String s: stickers)
			sticker.add(s);
	}
}
