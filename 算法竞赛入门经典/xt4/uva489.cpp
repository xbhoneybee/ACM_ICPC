#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
char s1[103],s2[103];
int rnd;
int main()
{
   while(scanf("%d %s %s",&rnd,s1,s2)&&rnd!=-1)
   {
       printf("Round %d\n",rnd);
       int n1[30]={0};
       int dead=0;
       int len1=strlen(s1);
       int len2=strlen(s2);
       int guess[256]={0};
       int win=1;
       for(int i=0;i<len1;i++)
       {
           n1[s1[i]-'a']=1;
       }
       for(int i=0;i<len2;i++)
       {
           int tmp=s2[i]-'a';
           if(n1[tmp]==0&&guess[tmp]==0)
            {
                dead++;
                guess[tmp]=1;
            }
           else { 
                n1[tmp]=0;
           }
           if(dead>=7){
            win=0;break;
           }
           for(int i=0;i<27;i++)
            {
                if(n1[i]!=0)
                    break;
                if(i==26) win=-1;
            }
            if(win==-1) break;
       }
        if(win==1) cout<<"You chickened out."<<endl;
        else if(win==-1) cout<<"You win."<<endl;
        else cout<<"You lose."<<endl;
   }
    return 0;
}
