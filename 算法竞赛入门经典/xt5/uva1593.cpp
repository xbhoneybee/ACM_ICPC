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
#define ll long long
#define LL long long
#define inf 1
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//uva 1593
int main()
{
    //freopen("output.txt","w",stdout);
    string data[1001];
    int id=0;
    while(!cin.eof())
        getline(cin,data[id++]);
    vector<string>vec[id];
    int hori=0;
    for(int i=0;i<id;i++)
    {
        int sta=-1,ed=0;
        if(data[i][0]!=' ')
            sta=0;
        for(int j=0;j<data[i].size();j++)
        {
            if(data[i][j]==' ')
                {
                    if(j+1<data[i].size()&&data[i][j+1]!=' ')
                        sta=j+1;
                }
            else
            {
                ed=j;
                if(j+1<data[i].size()&&data[i][j+1]==' ')
                    {
                        vec[i].push_back(data[i].substr(sta,ed-sta+1));
                        //cout<<data[i].substr(sta,ed-sta+1)<<"-";
                    }
            }
        }
        if(data[i][data[i].size()-1]!=' ')
            {
                vec[i].push_back(data[i].substr(sta,data[i].size()-sta));
                //cout<<data[i].substr(sta,data[i].size()-sta)<<endl;
            }
    hori=max(hori,(int)vec[i].size());
    }
    int horiarr[180]={0};
    for(int j=0;j<hori;j++)
        for(int i=0;i<id;i++)
        {
            if(vec[i].size()>j)
                horiarr[j]=max(horiarr[j],(int)vec[i][j].size());
        }
    for(int i=0;i<id;i++)
        {
        if(vec[i].size()==1&&vec[i][0].size()==0)
            continue;
        int j;
        for(j=0;j<vec[i].size()-1;j++)
            cout<<vec[i][j]<<string(horiarr[j]+1-vec[i][j].size(),' ');
        cout<<vec[i][j]<<endl;
        }
    return 0;
}

