import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n;
		BigInteger[] a=new BigInteger[300];
		a[0]=BigInteger.ONE;
		a[1]=BigInteger.ONE;
		for(int i=2;i<=200;i++)
			a[i]=a[i-1].add(a[i-2]);
		while(in.hasNext())
		{
			n=in.nextInt();
			if(n==0)
				System.out.println();
			else
				System.out.println(a[n]);
		}
		in.close();
	}

}
