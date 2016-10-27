import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
    Scanner cin=new Scanner(System.in);
 
    	int n=cin.nextInt();
    	int num7=n/7;
    	int mod=n%7;
    	switch(mod){
    	case 0:{
    		StringBuffer s=new StringBuffer("");
    		StringBuffer a=new StringBuffer("7");
    		while(num7>0) 
    			{
    			if(num7%2==1)
    				s.append(a);
    			a.append(a);
    			num7/=2;
    			}
    			System.out.print(s);
    		break;
    		}
    	case 1:{ 
    		if(num7>=1) 
    			{
    			System.out.print("44");num7--;
    			StringBuffer s=new StringBuffer("");
    			StringBuffer a=new StringBuffer("7");
        		while(num7>0) 
        			{
        			if(num7%2==1)
        				s.append(a);
        			a.append(a);
        			num7/=2;
        			}
        			System.out.print(s);
    			}
    		else 
    			System.out.print(-1);
    		break;
    		}
    	case 2:{
    		if(num7>=2) 
			{
			System.out.print("4444");num7-=2;
			StringBuffer s=new StringBuffer("");
			StringBuffer a=new StringBuffer("7");
    		while(num7>0) 
    			{
    			if(num7%2==1)
    				s.append(a);
    			a.append(a);
    			num7/=2;
    			}
    			System.out.print(s);
			}
		else 
			System.out.print(-1);
    		break;
		}
    	case 3:{ 
    		if(num7>=3) 
			{
			System.out.print("444444");num7-=3;
			StringBuffer s=new StringBuffer("");
			StringBuffer a=new StringBuffer("7");
    		while(num7>0) 
    			{
    			if(num7%2==1)
    				s.append(a);
    			a.append(a);
    			num7/=2;
    			}
    			System.out.print(s);
			}
		else 
			System.out.print(-1);
    		break;
		}    	
    	case 4:{
    		System.out.print("4");
    		StringBuffer s=new StringBuffer("");
    		StringBuffer a=new StringBuffer("7");
    		while(num7>0) 
    			{
    			if(num7%2==1)
    				s.append(a);
    			a.append(a);
    			num7/=2;
    			}
    			System.out.print(s);
			break;
    		}
    	case 5:{ 
    		if(num7>=1) 
			{
			System.out.print("444");num7--;
			StringBuffer s=new StringBuffer("");
			StringBuffer a=new StringBuffer("7");
    		while(num7>0) 
    			{
    			if(num7%2==1)
    				s.append(a);
    			a.append(a);
    			num7/=2;
    			}
    			System.out.print(s);
			}
		else 
			System.out.print(-1);
    		break;
		}
    	case 6:{
    		if(num7>=2) 
			{
			System.out.print("44444");num7-=2;
			StringBuffer s=new StringBuffer("");
			StringBuffer a=new StringBuffer("7");
    		while(num7>0) 
    			{
    			if(num7%2==1)
    				s.append(a);
    			a.append(a);
    			num7/=2;
    			}
    			System.out.print(s);
			}
		else 
			System.out.print(-1);
    		break;
		}
    }
    	System.out.println();
    
    }//main
}//Main
