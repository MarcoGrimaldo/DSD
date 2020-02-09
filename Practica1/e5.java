public class HolaMundo {

	public static void main(String[] args) {	
        int n, sum;

        String entradaTeclado = "";
        Scanner entradaEscaner = new Scanner (System.in);
        
        entradaTeclado = entradaEscaner.nextLine ();

        n = Integer.parseInt(entradaTeclado);
        sum = n + (++n);
		System.out.println(sum);
	}

}