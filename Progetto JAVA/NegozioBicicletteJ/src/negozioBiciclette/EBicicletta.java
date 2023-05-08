/**
 * @author: Lorenzo Ferrari
 * Desctizione: classe derivata dalla classe Bicicletta
 */
package negozioBiciclette;

public class EBicicletta extends Bicicletta implements EBInterface {

	//Campi della classe
	private int velocita;
	private int capBatteria;
	
	public EBicicletta() {
		super();
		this.capBatteria = capBatteriaD;
		this.velocita = velocitaD;
	}

	public EBicicletta(String materiale, double prezzo, int peso, int dim_cerchio, int velocita, int capBatteria) {
		super(materiale,prezzo,peso,dim_cerchio);
		this.velocita = velocita;
		this.capBatteria = capBatteria;
	}
	
	// Metodi che ritornano i parametri privati della classe derivata
	@Override
	public int getVelocita() { return this.velocita; }
	@Override
	public int getCapBatteria() { return this.capBatteria; }
		
	//Implementazione dei metodi astratti della classe base
	@Override
	String getTipo() {
		return "EB";
	}
	
	@Override
	String printSpecific() {
		return "\n"+"Velocita: " + this.velocita + "\n" +
			   "Capacità batteria: " + this.capBatteria + "\n";
	}
	
	//toString della classe della derivata
	public String toString() {
		return super.toString() + " " + printSpecific();
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
}
