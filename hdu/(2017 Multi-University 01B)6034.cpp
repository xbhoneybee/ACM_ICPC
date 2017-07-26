//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

int n;
string str[100050];
int appear[30][100050];
vector<pair<int,int> >abc[30];
const long long mmd=1e9+7;
//<pos,times>
int abctoval[30];
int zero[30];
int firstandone[30];
int main()
{
    iosfalse
    int id=1;
    while(cin>>n)
    {
        memset(appear,0,sizeof appear);
        memset(abctoval,-1,sizeof abctoval);
        memset(firstandone,0,sizeof firstandone);
        memset(zero,0,sizeof zero);
        for(int i=0;i<=26;i++)
            abc[i].clear();
        for(int i=0;i<n;i++)
            {
                cin>>str[i];
                for(int power=0;power<str[i].size();power++)
                {
                    appear[str[i][str[i].size()-power-1]-'a'][power]++;
                }
                if(str[i].size()>1)
                    firstandone[str[i][0]-'a']++;
            }
        for(int i=0;i<26;i++)
        {
            for(int pos=0;pos<100005;pos++)
            {
                if(appear[i][pos]>=26)
                {
                    appear[i][pos+1]+=appear[i][pos]/26;
                    appear[i][pos]=appear[i][pos]%26;
                }
            }
        }
        for(int i=0;i<26;i++)
            for(int pos=100005;pos>=0;pos--)
        {
            if(appear[i][pos]>0)
                abc[i].push_back(make_pair(pos,appear[i][pos]));
        }
        //zero
        vector<int>canbezero;
        for(int i=0;i<26;i++)
        {
            if(firstandone[i]==0)
                {
                    canbezero.push_back(i);
                }
        }
        if(canbezero.size()==1)
            abctoval[canbezero[0]]=0;
        else {
            //处理多个未出现在首字母的情况
            int letter=1,let=0;
            for(;letter<canbezero.size();letter++)
            {
                if(abc[canbezero[letter]].size()==0)
                    {
                        let=letter;
                        break;
                    }
                if(abc[canbezero[let]].size()==0)
                {
                    break;
                }
                int poslet=0,poster=0;
                for(;poslet<abc[canbezero[let]].size()&&poster<abc[canbezero[letter]].size();poslet++,poster++)
                {
                    if(abc[canbezero[let]][poslet].first!=abc[canbezero[letter]][poster].first)
                    {
                        if(abc[canbezero[let]][poslet].first>abc[canbezero[letter]][poster].first)
                        {
                            let=letter;
                        }
                        break;
                    }else if(abc[canbezero[let]][poslet].second!=abc[canbezero[letter]][poster].second){
                        if(abc[canbezero[let]][poslet].second>abc[canbezero[letter]][poster].second)
                        {
                            let=letter;
                        }
                        break;
                    }
                }
                if(poster==abc[canbezero[letter]].size()&&poslet<abc[canbezero[let]].size())
                    let=letter;
            }
            abctoval[canbezero[let]]=0;
            //结束
        }
        for(int val=25;val>0;val--)
        {
            int letter,let;
            for(letter=0;letter<26;letter++)
            {
                if(abctoval[letter]==-1)
                {
                    let=letter;
                    break;
                }
            }
            for(letter++;letter<26;letter++)
            {
                if(abctoval[letter]>=0)
                    continue;
                if(abc[letter].size()==0)
                    continue;
                if(abc[let].size()==0)
                {
                    let=letter;
                    continue;
                }
                int poslet=0,poster=0;
                for(;poslet<abc[let].size()&&poster<abc[letter].size();poslet++,poster++)
                {
                    if(abc[let][poslet].first!=abc[letter][poster].first)
                    {
                        if(abc[let][poslet].first<abc[letter][poster].first)
                        {
                            let=letter;
                        }
                        break;
                    }else if(abc[let][poslet].second!=abc[letter][poster].second){
                        if(abc[let][poslet].second<abc[letter][poster].second)
                        {
                            let=letter;
                        }
                        break;
                    }
                }
                if(poslet==abc[let].size()&&poster<abc[letter].size())
                    let=letter;
            }
            abctoval[let]=val;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long tmp=0;
            for(int power=0;power<str[i].size();power++)
            {
                tmp=tmp*26+abctoval[str[i][power]-'a'];
                if(tmp>=mmd)
                    tmp%=mmd;
            }
            ans=(ans+tmp)%mmd;
        }
        cout<<"Case #"<<id++<<": "<<ans<<endl;
    }
    return 0;
}
