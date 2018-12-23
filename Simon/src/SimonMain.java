import java.util.Random;
import java.util.Timer;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author angeladietz
 *
 */
public class SimonMain {

	static int length = 20;
	static Random r = new Random();
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int sequence[] = new int[length];
		generate(sequence);
		
		/*for (int i = 0; i<length; i++) {
			System.out.println(sequence[i]);
		}*/
		
		Game(sequence);

	}
	

	//make this a new class Game
	static public void Game(int[] sequence) {
		Timer tmr = new Timer();
		Scanner sc = new Scanner(System.in);
		int n =0;
		System.out.println("Lettuce begin\n");
		for (int i = 0; i < length; i++) {
			while (n <= i) {
				System.out.println(sequence[n]);
				n++;
			}
			n=0;
			while(n <=i) {
				if(sc.nextInt() ==sequence[n]){
					if (n ==i) {
						System.out.println("Great work team!");
					}
					//correct input
				}
				else {
					//incorrect input
					//stop game
				}
				n++;
			}
			n=0;
		}
	}

	static public void generate(int[] sequence) {
		for (int i = 0; i<length; i++) {
			sequence[i] = r.nextInt(4)+1;
		}
	}
	
	
	

}
