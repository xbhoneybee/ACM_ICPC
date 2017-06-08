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


//cf 06 07


//C
vector<int>vec[30];
char str[2000];
int nstr[2000];
int n,m;
int pre[30];
int main()
{
    cin>>n;
    cin>>str;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        nstr[i]=str[i]-'a';
    }
    memset(pre,-1,sizeof pre);
    for(int i=0;i<n;i++)
    {
        if(pre[nstr[i]]==-1)
            pre[nstr[i]]=i;
        else {
            int len=i-pre[nstr[i]]-1;
            pre[nstr[i]]=i;
            vec[nstr[i]].push_back(len);
        }
    }
    for(int q=0;q<m;q++)
    {
        int change,time;
        char och;
        int id;
        cin>>time>>och;
        id=och-'a';
        int all=0,output=0;
        change=time;
        if(vec[id].size()==0)
        {
            bool ap=false;
            for(int i=0;i<n;i++)
            {
                if(nstr[i]==id)
                    ap=true;
            }
            if(ap)
                change++;
            change=min(change,n);
            cout<<change<<endl;
            continue;
        }
        int top=-1;
        for(int i=0;i<vec[id].size();i++)
        {
            if(change>vec[id][i]||(i+1<vec[id].size()&&vec[id][i+1]==0&&vec[id][i]==change))
            {
                change-=vec[id][i];
                all+=(vec[id][i]+1);
                if(top==-1)
                    top=i;
            }else if(change==vec[id][i]){//未考虑change==vec[id][i] 之后下一个vec[id][i]==0时不需要左移的情况 WA6
                output=max(all+change+2,output);
                if(top==-1||top==i)
                    {
                        if(top==i)
                            top++;
                        continue;
                    }
                change+=vec[id][top];
                i--;
                all-=(vec[id][top]+1);
                top++;
            }else {
                output=max(all+change+1,output);
                if(top==-1||top==i)
                    {
                        if(top==i)//这里左边界也要右移 WA6
                            top++;
                        continue;
                    }
                change+=vec[id][top];
                i--;
                all-=(vec[id][top]+1);
                top++;
            }
        }
        if(change>0)
        {
            output=max(output,all+1+change);
        }
        output=min(output,n);
        cout<<output<<endl;
    }
    return 0;
}
