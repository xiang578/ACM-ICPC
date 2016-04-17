import java.io.*;

import java.math.*;

import java.util.*;

import java.text.*;

public class Main

{

    public static void main(String[] args)

    {

        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int T;
        T=cin.nextInt();
        for(int i=1;i<=T;i++)
        {
            BigInteger a,b;
            a=cin.nextBigInteger();
            b=cin.nextBigInteger();
       System.out.println(a.subtract(BigInteger.valueOf(2)).multiply(a.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2)).mod(b));

        }

    }

}
