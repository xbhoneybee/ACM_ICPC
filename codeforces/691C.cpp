#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;


//好难写 呜呜呜
int main()
{
    string s;
    while(cin>>s){
    int len=s.size();
    int dot=0;
    int prez=0,flag0=1;
    for(int i=0;i<len;i++) //去前缀0 找.
    {
        if(s[i]=='0'&&flag0)
        {prez++;}
        else if(s[i]=='.')
        {dot=1;flag0=0;}
        else flag0=0;
    }
    string ss=s.substr(prez,len-prez);
    if( ss.size()==0) ss="0";
    //cout<<ss<<endl;
    string sss;  //去后缀0
    if(dot){
        int len1=ss.size();
        if(ss[len1-1]=='.')
            sss=ss.substr(0,len1-1);
        else {
            int hindz=1,i;
            for(i=len1-1;i>=1;i--)
            {
                if(ss[i]=='0'&&hindz)
                    ;
                else if(ss[i]!='0') {
                    hindz=0; break;
                }
            }
            if(ss[i]=='.') i--;
            sss=ss.substr(0,i+1);
        }
        if(sss.size()==0) sss="0";
    }else{
    sss=ss;
    }
    //cout<<dot<<endl;
    //cout<<sss<<endl;
    if(sss=="0") {cout<<0<<endl;return 0;}
    int len3=sss.size(),i;
    for( i=0;i<len3;i++)
    {
        if(sss[i]=='.') break;
    }
    string ps ;//去后缀0
    if(i==len3)//10800 ||100
     {
      ps=sss;
      int nps=ps.size(),ffg=0;
      cout<<ps[0];
      for(int j=1;j<nps;j++)
      if(ps[j]!='0') {ffg=1;break;}
      if(ffg){
        cout<<'.';
        int houz=nps-1;
        for(;ps[houz]=='0';houz--);
        for(int j=1;j<=houz;j++)
            {   if(ps[j]!='.')
                cout<<ps[j];
            }
      }
      if((nps-1)!=0)
        cout<<'E'<<nps-1<<endl;
    }
    else if(i==0){//.0000102
        ps=sss;
        int nps=ps.size();
        int qianfz=1;
        for(;ps[qianfz]=='0';qianfz++);
        cout<<ps[qianfz];
        int i0hz=nps-1;
        for(;ps[i0hz]=='0';i0hz--);
        if(i0hz!=qianfz){
                cout<<'.';
            for(int j=qianfz+1;j<=i0hz;j++)
                cout<<ps[j];
        }
        cout<<'E'<<-qianfz<<endl;
    }
    else{//180.0098
    ps=sss;
    int nps=ps.size();
    cout<<ps[0]<<'.';
    int dotpos;
    for(int j=1;j<nps;j++)
        if(ps[j]!='.') cout<<ps[j];
        else dotpos=j;
        if((dotpos-1)!=0)
    cout<<'E'<<dotpos-1<<endl;
    }
    }
    return 0;
}