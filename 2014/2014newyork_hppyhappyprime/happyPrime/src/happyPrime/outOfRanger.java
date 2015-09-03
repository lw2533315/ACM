package happyPrime;

public class outOfRanger extends Exception{
     public outOfRanger (){
    	 super("out of range 1-1000");
     }
     public outOfRanger (int a,int b){
    	 super("out of range 1-10000");
     }
}
