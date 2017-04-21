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
#define lowbit(x) x&-x

using namespace std;


//cf ed19 A math
int main()
{
    long long n,k;
    cin>>n>>k;
    if(k==1)
       {
        cout<<n<<endl;
        return 0;
       }
    if(pow(2,k)>n)
        cout<<-1<<endl;
    else if(pow(2,k)==n){
        for(int i=0;i<k;i++)
            cout<<2<<" ";
        cout<<endl;
    }else {
        vector<long long>vec;
        long long nn=n,div=2;
        while(nn>1)
        {
            if(nn%div==0)
            {
                vec.push_back(div);
                nn/=div;
                if(vec.size()==k-1)
                    {
                        if(nn>1)
                        vec.push_back(nn);
                        break;
                    }
            }else {
                div++;
            }
        }
        if(vec.size()<k)
            cout<<-1<<endl;
        else{
        for(int i=0;i<k;i++)
            cout<<vec[i]<<" ";
        cout<<endl;
        }
    }
    return 0;
}
