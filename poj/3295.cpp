#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 100000000
using namespace std;
//3295
int w[200];
void add(int v )
{
    for(int i =0;i<120;i++)
    {
        if(w[i]==-1)
            {w[i]=v;break;}
    }
}
void deal(char ch)
{
    int pos=0;
    for(;pos<120;pos++)
    {
        if(w[pos+1]==-1)
            break;
    }
    if(ch=='K')
    {
        if(w[pos]&&w[pos-1])
            w[pos-1]=1;
        else w[pos-1]=0;
    }else if(ch=='A')
    {
        if(w[pos]||w[pos-1])
           w[pos-1]=1;
        else w[pos-1]=0;
    }else if(ch=='C')
    {
        if(w[pos]<=w[pos-1])
            w[pos-1]=1;
        else w[pos-1]=0;
    }else {
        if(w[pos-1]==w[pos])
            w[pos-1]=1;
        else w[pos-1]=0;
    }
    w[pos]=-1;
}

///from右向左implementation时可能more than one variety ,so use array
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="0")
            break;

        int len=s.size();
        int flag=1;
        for(int p1=0;p1<=1;p1++)
            for(int q2=0;q2<=1;q2++)
                for(int r3=0;r3<=1;r3++)
                    for(int s4=0;s4<=1;s4++)
                        for(int t5=0;t5<=1;t5++)
        {
            memset(w,-1,sizeof w);
            for(int i=len-1;i>=0;i--)
            {
                if(s[i]=='p')
                {
                    add(p1);
                }else if(s[i]=='q')
                {
                    add(q2);
                }else if(s[i]=='r')
                {
                    add(r3);
                }else if(s[i]=='s')
                {
                    add(s4);
                }else if(s[i]=='t')
                {
                    add(t5);
                }else if(s[i]=='N')
                {
                    int pos=0;
                    for(;pos<120;pos++)
                    {
                        if(w[pos]==-1)
                            break;
                    }
                    w[pos-1]=w[pos-1]==0?1:0;
                }else
                {
                   deal(s[i]);
                }
            }
        if(w[0]==0)
            flag=0;
        }
        if(flag==1)
            cout<<"tautology"<<endl;
        else cout<<"not"<<endl;
    }
    return 0;
}
