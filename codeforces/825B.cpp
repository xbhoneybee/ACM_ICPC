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
char mp[20][20];
int main()
{
    for(int i=0;i<10;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
    {
        if(i+4<10)
        {
            int numX=0,numP=0;
            for(int k=0;k<5;k++)
            {
                if(mp[i+k][j]=='X')
                    numX++;
                else if(mp[i+k][j]=='.')
                    numP++;
            }
            if(numP==1&&numX==4)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
        if(j+4<10)
        {
            int numX=0,numP=0;
            for(int k=0;k<5;k++)
            {
                if(mp[i][j+k]=='X')
                    numX++;
                else if(mp[i][j+k]=='.')
                    numP++;
            }
            if(numP==1&&numX==4)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
        if(i+4<10&&j+4<10)
        {
            int numX=0,numP=0;
            for(int k=0;k<5;k++)
            {
                if(mp[i+k][j+k]=='X')
                    numX++;
                else if(mp[i+k][j+k]=='.')
                    numP++;
            }
            if(numP==1&&numX==4)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
        if(i+4<10&&j-4>=0)
        {
            int numX=0,numP=0;
            for(int k=0;k<5;k++)
            {
                if(mp[i+k][j-k]=='X')
                    numX++;
                else if(mp[i+k][j-k]=='.')
                    numP++;
            }
            if(numP==1&&numX==4)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
