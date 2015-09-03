package happyPrime;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class happyPrime {
	public static boolean isPrime(int a){
		double compareNum=0;
		int temp;
		int []array=new int[4];
		double compareA=a;
		while(compareNum!=1){
			array[0]=a/1000;
//			System.out.println("a[0] is "+array[0]);
			temp=a%1000;
			array[1]=temp/100;
//			System.out.println("a[1] is "+array[1]);
			temp=a%100;
			
			
			array[2]=temp/10;
			array[3]=temp%10;
			compareNum=Math.pow(array[0],2.0)+Math.pow(array[1], 2)+
					Math.pow(array[2],2.0)+Math.pow(array[3], 2);
//			System.out.println("a is "+a);
			if(compareNum==compareA){
				return false;
			}
//			System.out.println("compare is "+compareNum);
			a=(int)compareNum;
		}
		return true;
	}
	public  static void main(String[] args){	
		List<Integer> list=new ArrayList<Integer>();
		System.out.println("enter the number");
		Scanner input=new Scanner(System.in);
		int number=0;
		int val=0;
		try{
			number=input.nextInt();
			if(number<1||number>1000){
				throw new outOfRanger();
			}
			else{
				while(number>0){
					val=input.nextInt();
					if(val<1||val>=10000)
						throw new outOfRanger(1,1);
					else{
						list.add(val);
						number--;}
				}
			}
		}catch(Exception e){
			System.out.println(e);
			return;
		}
		for(Integer x: list){
			if(isPrime(x))
				System.out.println(x+"\tYes");
			else
				System.out.println(x+"\tNo");
			
		}
	}
 
}
