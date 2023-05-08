package negozioBiciclette;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws SceltaErrataException {
		int scelta = 1,tipo,tipof;
		Scanner obj = new Scanner(System.in);
		String stringa_menu = "---- Operazioni negozio: ----\n" + 
							  "1 - Inserisci una nuova Bicicletta: \n" +
							  "2 - Mostra la lista del negozio: \n"+
							  "3 - Ricerca Bicicletta per peso: \n" +
							  "4 - Ricerca Bicicletta per prezzo: \n" +
							  "5 - Ricerca Bicicletta per Tipo: \n" +
							  "6 - Dimensione negozio: \n" +
							  "7 - Esci:\n" +
							  "---- Scelta ----";
		
		
		System.out.println("---- NEGOZIO APERTO ---- \n");
		Negozio n = Negozio.instance();
		
		while(scelta != 7 ) {
			System.out.println(stringa_menu);
			scelta = obj.nextInt();	
			
			switch(scelta) {
			case 1: {
				System.out.println("---- INSERIMENTO BICICLETTA ----\n");
				
				System.out.println("Inserire peso: ");
				int peso = obj.nextInt();
				System.out.println("Inserire dimensione cerchi: ");
				int dim_cerchio = obj.nextInt();
				System.out.println("Inserire prezzo: ");
				double prezzo = obj.nextDouble();
				System.out.println("Inserire materiale di cui è fatta: ");
				String mat = obj.nextLine();
				
				do {
				System.out.println("Inserire tipo di bicicletta:\n 1- Mountain Bike\n 2-Elettrica\n 3-Corsa\n: ");
				tipo = obj.nextInt();
				System.out.println("Tipo:" + tipo);
				if(tipo != 1 && tipo != 2 && tipo != 3) System.out.println("Tipologia non disponibile, riprovare\n ");			
				}while(tipo == 1 && tipo == 2 && tipo != 3);
				
				switch(tipo) {
					case 1: {
						System.out.println("Inserire numero di rapporti: ");
						int rapporti = obj.nextInt();
						n.aggiungiBicicletta(new MTBicicletta(mat,prezzo,peso,dim_cerchio,rapporti));
					}break;
					
					case 2: {
						System.out.println("Inserire velocità max bicicletta: ");
						int velo = obj.nextInt();
						System.out.println("Inserire capacità max batteria: ");
						int bat = obj.nextInt();
						n.aggiungiBicicletta(new EBicicletta(mat,prezzo,peso,dim_cerchio,velo,bat));
					}break;
					
					case 3: {
						System.out.println("Inserire numero di rapporti: ");
						int rapportiC = obj.nextInt();
						System.out.println("Inserire velocità max bicicletta: ");
						int veloC = obj.nextInt();
						do {
							System.out.println("Inserire tipologia freno bicicletta (1,2,3): ");
							tipof = obj.nextInt();
							if(tipof != 1 && tipof != 2 && tipo != 3) System.out.println("tipologia di freno non corretta, reinserire\n");
						}while(tipof != 1 && tipof != 2 && tipo != 3);
						n.aggiungiBicicletta(new CBicicletta(mat,prezzo,peso,dim_cerchio,rapportiC,veloC,tipof));
					}break;
					default: break;
				}
				
			}break;
			
			case 2: { 
				System.out.println("---- LISTA BICICLETTE NEGOZIO ----\n"); 
				System.out.println(n.getInfoNegozio()); 
			}break;
			
			case 3: { 
				System.out.println("Inserisce Peso di Bicicletta da ricercare: ");
				int peso_ric = obj.nextInt();
				System.out.println("--- Biciclette che corrispondono alla ricerca ---- \n");
				System.out.println(n.cercaBicicletta(peso_ric));				
			}break;
			
			case 4: { 
				System.out.println("Inserisce Prezzo di Bicicletta da ricercare: ");
				double prezzo_ric = obj.nextDouble();
				System.out.println("--- Biciclette che corrispondono alla ricerca ---- \n");
				System.out.println(n.cercaBicicletta(prezzo_ric));				
			}break;
			
			case 5: { 
				System.out.println("Inserisce Tipo di Bicicletta da ricercare: ");
				String tipo_ric = obj.nextLine();
				System.out.println("--- Biciclette che corrispondono alla ricerca ---- \n");
				System.out.println(n.cercaBicicletta(tipo_ric));				
			} break;
			
			case 6: System.out.println("Dimensione negozio:" + n.dimensioneNegozio()); break;
			
			default: throw new SceltaErrataException("Scelta Non presente nel menu");
			}
			
		}
		System.out.println("---- NEGOZIO CHIUSO ----");
	
	
	
	
	
	}

}
