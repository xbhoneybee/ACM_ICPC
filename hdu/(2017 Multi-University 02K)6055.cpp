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

//经过分析发现整点只能形成正方形
bool mp[205][205];
int n;
vector<pair<int,int> >vec;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)
    {
        return a.first<b.first;
    }
    else return a.second<b.second;
}
int main()
{
    iosfalse
    while(cin>>n)
    {
        memset(mp,false,sizeof mp);
        vec.clear();
        int leftmargin=300,rightmargin=0,upmargin=300,downmargin=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            mp[x+100][y+100]=true;
            vec.push_back(make_pair(x+100,y+100));
            leftmargin=min(leftmargin,y+100);
            rightmargin=max(rightmargin,y+100);
            upmargin=min(upmargin,x+100);
            downmargin=max(downmargin,x+100);
        }
        sort(vec.begin(),vec.end(),cmp);
        int ans=0;
        for(int p1=0;p1<vec.size();p1++)
        {
            int x1=vec[p1].first;
            int y1=vec[p1].second;
            {
                for(int p2=p1+1;p2<vec.size();p2++)
                {
                    int x2=vec[p2].first;
                    int y2=vec[p2].second;
                    {
                        if(x1==x2)//向下寻找
                        {
                            int len=y2-y1;
                            if(x1+len<=downmargin&&mp[x1+len][y1]==true&&mp[x2+len][y2]==true)
                                ;//ans++;
                        }else if(y1==y2)//向右寻找
                        {
                            int len=x2-x1;
                            if(y1+len<=rightmargin&&mp[x1][y1+len]==true&&mp[x2][y2+len]==true)
                                {
                                    ans++;
                                }
                        }else if(y1>y2)
                        {
                            int x3=x1+(y1-y2);
                            int y3=y1+(x2-x1);
                            int x4=x2+(y1-y2);
                            int y4=y2+(x2-x1);
                            if(x3<=downmargin&&y3<=rightmargin&&x4<=downmargin&&y4<=rightmargin&&mp[x3][y3]==true&&mp[x4][y4]==true)
                                ;//ans++;
                        }else {
                            int x3=x1+(y2-y1);
                            int y3=y1-(x2-x1);
                            int x4=x2+(y2-y1);
                            int y4=y2-(x2-x1);
                            if(x3<=downmargin&&y3>=leftmargin&&x4<=downmargin&&y4>=leftmargin&&mp[x3][y3]==true&&mp[x4][y4]==true)
                                ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
