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
struct Rec{
int num,e,c;
}r[105];
bool judge(int x)
{
    for(int in=0;in<n;in++)
    {
        int recnum[5];
        recnum[0]=r[in].num/1000;
        recnum[1]=(r[in].num/100)%10;
        recnum[2]=(r[in].num/10)%10;
        recnum[3]=r[in].num%10;
        int xnum[5];
        xnum[0]=x/1000;
        xnum[1]=(x/100)%10;
        xnum[2]=(x/10)%10;
        xnum[3]=x%10;
        int ee=0,cc=0;
        bool usedx[5],usedr[5];
        memset(usedx,false,sizeof usedx);//写的很僵
        memset(usedr,false,sizeof usedr);
        for(int i=0;i<4;i++)
        {
            if(xnum[i]==recnum[i])
                {
                    cc++;
                    usedx[i]=true;
                    usedr[i]=true;
                }
        }
        ee=cc;
        for(int i=0;i<4;i++)
        {
            if(usedr[i]==false)
            for(int j=0;j<4;j++)
            {
                if(usedx[j]==false&&recnum[i]==xnum[j])
                    {
                        ee++;
                        usedx[j]=true;
                        break;
                    }
            }
        }
        if((ee!=r[in].e)||(cc!=r[in].c))
            return false;
    }
    return true;
}
int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
           cin>> r[i].num>>r[i].e>>r[i].c;
        }
       for(int i=1000;i<=9999;i++)
       {
           if(judge(i))
            {
                ans.push_back(i);
            }
       }
       if(ans.size()==1)
        cout<<ans[0]<<endl;
       else cout<<"Not sure"<<endl;
    }
    return 0;
}
