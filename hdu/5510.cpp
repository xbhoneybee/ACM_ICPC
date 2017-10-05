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
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

string str[501];
int cont[505];
int main()
{
    iosfalse
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int maxlen=0;
        for(int i=1;i<=n;i++)
        {
            cin>>str[i];
        }
        int ans=-1;
        cont[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                bool bh;
                int pos=str[i].find(str[j]);
                if(pos<0)
                    bh=false;
                else bh=true;
                if(cont[j]==1)
                {
                    if(bh)
                    {
                        cont[i]=1;
                        break;
                    }else {
                        cont[i]=-1;
                        ans=i;
                        break;
                    }
                }else {
                    if(bh)
                    {
                        ;
                    }else {
                        cont[i]=-1;
                        ans=i;
                        break;
                    }
                }
                if(j==1)
                    cont[i]=1;
            }
        }
        there :
            ;
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
