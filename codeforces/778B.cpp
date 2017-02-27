
#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>1
#include<vector>
#include<map>
#include<sstream>
#define ll long lo`ng
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
//代码要尽量简洁
int n,m;
map<string,int>mp;
string name[5005],formula[5005],a_formula[5005],bitwise[5005];
bool isd[5005];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>name[i]>>formula[i]>>formula[i];
        isd[i]=true;
        int len_here=formula[i].size();
        for(int seq=0;seq<len_here;seq++)
            if(formula[i][seq]!='1'&&formula[i][seq]!='0')
            {
                isd[i]=false;
                break;
            }
        if(isd[i]==false)
        {
           cin>>bitwise[i]>>a_formula[i];
        }
        mp[name[i]]=i;
    }
    mp["?"]=n;
    string ansmin="",ansmax="";
    for(int i=0;i<m;i++)
    {
        int add[2]={0};
        int posi[5005];
        for(int setnum=0;setnum<2;setnum++)
        {
            posi[n]=setnum;
            for(int id=0;id<n;id++)
            {
                if(isd[id]==true)
                    {
                        posi[id]=formula[id][i]-'0';
                        add[setnum]+=posi[id];
                    }
                else {
                    if(bitwise[id][0]=='A') {posi[id]=(posi[mp[formula[id]]])&(posi[mp[a_formula[id]]]);add[setnum]+=posi[id];}
                    else if(bitwise[id][0]=='X') {posi[id]=(posi[mp[formula[id]]])^(posi[mp[a_formula[id]]]);add[setnum]+=posi[id];}
                    else {posi[id]=(posi[mp[formula[id]]])|(posi[mp[a_formula[id]]]);add[setnum]+=posi[id];}
                }
            }
        }
        if(add[0]<=add[1]) ansmin+='0';
            else ansmin+='1';
        if(add[0]>=add[1]) ansmax+='0';
            else ansmax+='1';
    }
    cout<<ansmin<<endl;
    cout<<ansmax<<endl;
    return 0;
}
