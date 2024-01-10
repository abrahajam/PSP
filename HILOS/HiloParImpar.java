// Clase Hilo 3 no implementa método main()
// Se invocará desde otra clase
public class HiloParImpar implements Runnable{
	private int tipo;
	// Constructor
	public  HiloParImpar(int tipo) {
		this.tipo = tipo;
	}

	// Método run -> funcionalidad del hilo
	public void run() {
		if(tipo==1){
			for(int i = 2;i<100;i=i+2){
				System.out.println("HILO "+Thread.currentThread().getName() + " generando número par " +i);
			}
		}
		else{
			for(int i = 101;i<=200;i=i+2){
			System.out.println("HILO "+Thread.currentThread().getName() + " generando número impar " +i);
			}
		}
		
	}
}
