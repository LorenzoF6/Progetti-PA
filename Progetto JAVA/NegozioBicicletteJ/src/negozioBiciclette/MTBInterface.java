// Interfaccia che aiuta nell'implementazione dell'ereditarietà 'multipla' per la classe CBicicletta
package negozioBiciclette;

public interface MTBInterface {
	int getRapporti();
	int getNumSticker();
	void setSticker(String ... stickers);

	int rapportiD = 7;
}
