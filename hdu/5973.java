import java.io.BufferedInputStream;
import java.math.BigDecimal;
import java.util.Scanner;


//由于有100位，所以高精度二分求根号5 黄金分割为 (sqrt(5)+1)/2
public class Main {
	public static void  main(String []args)
	{
		BigDecimal a,b,c;
		  Scanner cin = new Scanner (new BufferedInputStream(System.in));
		  while(cin.hasNextBigDecimal()==true)
		  {
			  a=cin.nextBigDecimal();
			  b=cin.nextBigDecimal();
			  if(a.compareTo(b)==1)
			  {
				  BigDecimal tmp=a;
				  a=b;
				  b=tmp;
			  }
			  c=b.subtract(a);
			  double l=2,r=3,one=1,ten=10;
			  BigDecimal Good,L,R,ONE,Ten;
			  L=BigDecimal.valueOf(l);
			  R=BigDecimal.valueOf(r);
			  ONE=BigDecimal.valueOf(one);
			  Ten=BigDecimal.valueOf(ten);
			  int cnt=101;
			  while(cnt>0)
			  {
				  cnt--;
				  ONE=ONE.divide(Ten);
			  }
			  while(R.subtract(L).compareTo(ONE)>=0)
			  {
				  BigDecimal M=L.add(R);
				  M=M.divide(new BigDecimal(2));
				  if(M.multiply(M).compareTo(new BigDecimal(5))>=0)
				  {
					  R=M;
				  }else L=M;
			  }
			  Good=L.add(new BigDecimal(1));
			  Good=Good.divide(new BigDecimal(2));
			  BigDecimal Want=Good.multiply(c);
			  BigDecimal limit=BigDecimal.valueOf(0.9999999999999999);
			  if(Want.subtract(a).compareTo(limit)==-1&&Want.compareTo(a)>=0)
			  {
				  System.out.println(0);
			  }else System.out.println(1);  
		  }
		  cin.close();
	}
}
