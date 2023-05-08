/**
 * @author: Lorenzo Ferrari
 * Desctizione: classe base ed astratta in quanto non implementa tutti i suoi metodi
 */
package negozioBiciclette;

public abstract class Bicicletta implements Comparable<Bicicletta> {
	
	//Campi classe Java
	private String telaio;
	private String materiale;
	private double prezzo;
	private int peso;
	private int dim_cerchio;
	
	//valori di default dei parametri definiti final e statici
	private static final double prezzoD = 300;
	private static final int dim_cerchioD = 24;
	private static final int pesoD = 6;
	private static final String materialeD = "carbonio";
	
	
	//costruttore vuoto di default
	Bicicletta(){
		this.dim_cerchio = dim_cerchioD;
		this.peso = pesoD;
		this.prezzo = prezzoD;
		this.materiale = materialeD;
		this.telaio = genTelaio();
	}
	
	//overloading del costruttore
	Bicicletta(String materiale, double prezzo, int peso, int dim_cerchio){
		this.dim_cerchio = dim_cerchio;
		this.peso = peso;
		this.prezzo = prezzo;
		this.materiale = materiale;
		this.telaio = genTelaio();
	}

	private String genTelaio() {
		String _t = ""; int x;
		for(int i = 0; i < 5; i++ ) {
			x = (int)(10*(Math.random()%10));
			_t = _t + String.valueOf(x);
		}
		return _t;
	}
	
	//Metodi get() per accedere ai campi privati della classe
	public int getPeso() { return this.peso; }
	public double getPrezzo() { return this.prezzo; }
	public int getDimCerchio() { return this.dim_cerchio; }
	public String getMaterile() { return this.materiale; }
	
	//Uso della clausola final per indicare che il metodo non può essere sostiuito nelle sottoclassi
	public final String getTelaio() { return this.telaio; }
	
	//Metodi astratti implementati solo nelle classi derivate
	abstract String getTipo();
	abstract String printSpecific();
	
	//Implementazione metodo equals
	public boolean equals (Object o) {
		if(o instanceof Bicicletta)
				return equals ((Bicicletta)o);
		return false ;
	}
	public boolean equals(Bicicletta b) {
		return this.getTipo().equals(b.getTipo());
	}
	
	//toString per far ritornare le informazioni relative ad una bicicletta
	public String toString() {
		return "Dati Bicicletta:\nTelaio:" + this.telaio + "\n" +
					"Materiale: " + this.materiale + "\n" +
					"Peso:" + this.peso + "\n" +
					"Prezzo:" + this.prezzo + "\n" +
					"Dimensione cerchio:" + this.dim_cerchio + "\n" +
					"Tipologia bicicletta:" +this.getTipo();		
	}
}
