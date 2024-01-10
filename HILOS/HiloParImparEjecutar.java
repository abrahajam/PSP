public class HiloParImparEjecutar {
public static void main(String[] args) {
	HiloParImpar HiloPar = new HiloParImpar(1);
	HiloParImpar HiloImpar = new HiloParImpar(2);
		
	Thread hilo1 = new Thread(HiloPar,"xx");
	Thread hilo2 = new Thread(HiloImpar,"yy");

	
	hilo1.start();
	hilo2.start();
	}// main
}
