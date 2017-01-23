//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#define ll long long
#define LL long long
#define inf 1000000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

///注意换局部变量
vector<set<int> >setvec;
map< set<int> ,int>mp;
int findseq(set<int> st)
{
    if(mp.count(st)==1)
        return mp[st];
    else setvec.push_back(st);
    mp[st]=setvec.size()-1;
    return setvec.size()-1;
}
void OUT(stack<int> &stk)
{
    int ans=stk.top();
    ans=setvec[ans].size();
    printf("%d\n",ans);
}
void PUSH(stack<int> &stk)
{
    set<int> sst;
    int num=findseq(sst);
    stk.push(num);
    OUT(stk);
}
void  DUP(stack<int> &stk)
{
    int sst=stk.top();
    stk.push(sst);
    OUT(stk);
}
void UNION(stack<int > &stk)
{
    int sst1=stk.top();
    set<int> st1=setvec[sst1];
    stk.pop();
    int sst2=stk.top();
    set<int> st2=setvec[sst2];
    stk.pop();
    int sst;
    set<int> st;
    set<int>::iterator it;
    for(it=st1.begin();it!=st1.end();it++)
        st.insert(*it);
    for(it=st2.begin();it!=st2.end();it++)
        st.insert(*it);
    sst=findseq(st);
    stk.push(sst);
    OUT(stk);
}
void INTERSECT(stack<int > &stk)
{
    int sst1=stk.top();
    set<int> st1=setvec[sst1];
    stk.pop();
    int sst2=stk.top();
    set<int> st2=setvec[sst2];
    stk.pop();
    set<int> st;
    set<int>::iterator it;
    for(it=st1.begin();it!=st1.end();it++)
        {
            if(st2.count(*it))
            st.insert(*it);
        }
    stk.push(findseq(st));
    OUT(stk);
}
void ADD(stack<int> &stk)
{
    int sst1=stk.top();
    stk.pop();
    int sst2=stk.top();
    stk.pop();
    set<int> st2=setvec[sst2];
    st2.insert(sst1);
    stk.push(findseq(st2));
    OUT(stk);
}
int main()
{
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        stack<int>stk;
        mp.clear();
        setvec.clear();
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            char cmd[20];
            scanf("%s",cmd);
            if(cmd[0]=='P')
                PUSH(stk);
            else if(cmd[0]=='D')
                DUP(stk);
            else if(cmd[0]=='U')
                UNION(stk);
            else if(cmd[0]=='I')
                INTERSECT(stk);
            else if(cmd[0]=='A')
                ADD(stk);
        }
        printf("***\n");
    }
    return 0;
}