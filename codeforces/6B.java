import java.util.Arrays;
import java.util.Comparator;
import java.util.*;
import java.util.Scanner;

public  class Main{
	
	public static void main(String[] args)
	{
		Scanner cin=new Scanner (System.in);
		int n,m;
		n=cin.nextInt();m=cin.nextInt();
		String tmp=cin.next();
		char boss=tmp.charAt(0);
		cin.nextLine();
		String []map=new String [n];
		for(int i=0;i<n;i++)
		{
			map[i]=cin.nextLine();
		}
		int ans=0;
		int []alph=new int [30];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(map[i].charAt(j)==boss)
				{
					if(j-1>=0&&map[i].charAt(j-1)!='.'&&map[i].charAt(j-1)!=boss)
						{
						if(alph[map[i].charAt(j-1)-'A']==0)
							{
							alph[map[i].charAt(j-1)-'A']=1;
							ans++;
							}
						}
					if(j+1<m&&map[i].charAt(j+1)!='.'&&map[i].charAt(j+1)!=boss)
						if(alph[map[i].charAt(j+1)-'A']==0)
						{
						alph[map[i].charAt(j+1)-'A']=1;
						ans++;
						}
					if(i-1>=0&&map[i-1].charAt(j)!='.'&&map[i-1].charAt(j)!=boss)
						if(alph[map[i-1].charAt(j)-'A']==0)
						{
						alph[map[i-1].charAt(j)-'A']=1;
						ans++;
						}
					if(i+1<n&&map[i+1].charAt(j)!='.'&&map[i+1].charAt(j)!=boss)
						if(alph[map[i+1].charAt(j)-'A']==0)
						{
						alph[map[i+1].charAt(j)-'A']=1;
						ans++;
						}
				}
			}
		System.out.println(ans);
		
	}//main
}

