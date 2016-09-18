#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#include<list>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;


//cf 9.17
//two point 时没考虑清楚kmp退回的情况。WA点
int main()
{
    queue<int> q;
    char s[50005];
    cin>>s;
    int l=0,r=25;
    int ap[30];
    memset(ap,-1,sizeof ap);
    int len=strlen(s);
    if(len<26)
        {
            cout<<-1<<endl;
            return 0;
        }
    int seq=0;
    while(1){
    int flag=0;
    memset(ap,-1,sizeof ap);
    for(int i=l;i<=r;i++,seq++)
    {
        //cout<<l<<" L and r  "<<r<<" s[i]  "<<s[i]<<"  seq  i "<<seq<<endl;
        if(s[i]!='?')
        {
        if(ap[s[i]-'A']==-1)
            ap[s[i]-'A']=seq;
        else {
            l=ap[s[i]-'A']+1;r=l+25;
            seq=ap[s[i]-'A']+1;//注意退回
         //cout<<l<<" L and r  "<<r<<endl;
            for(;!q.empty();)
            {

                q.pop();
            }
           // cout<<r<<" "<<len<<endl;
            if(r>=len)
            {
           // cout<<l<<" L  r"<<r<<" len "<<len<<endl;
            cout<<-1<<endl;
            return 0;
            }
            else {flag=1;
            break;}
            }
        }
        else{
            q.push(i);
        }
    }
    if(flag) continue;
    for(int j=0;j<26;j++)
        {
            if(ap[j]==-1&&!q.empty())
            {
                s[q.front()]='A'+j;
                q.pop();
            }
        }
    break;
    }
    for(int i=0;i<len;i++)
        if(s[i]=='?')
        s[i]='A';
    cout<<s<<endl;
    return 0;
}
