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

int main()
{
    iosfalse
    string good,model;
    int n;
    cin>>good>>model;
    cin>>n;
    bool hasstar=false;
    for(int i=0;i<model.size();i++)
    {
        if(model[i]=='*')
            hasstar=true;
    }
    bool alpha[30];
    memset(alpha,false,sizeof alpha);
    for(int i=0;i<good.size();i++)
        alpha[good[i]-'a']=true;
    for(int i=0;i<n;i++)
    {
        string tgoal;
        cin>>tgoal;
        int leng=tgoal.size();
        int lenm=model.size();
        if(abs(leng-lenm)>0)
        {
            if(hasstar==false||leng<lenm-1)
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        bool ok=true;
        for(int j=0,k=0;j<lenm&&k<leng;j++,k++)
        {
            if(model[j]=='?')
            {
                if(alpha[tgoal[k]-'a']==false)
                {
                    ok=false;
                    cout<<"NO"<<endl;
                    break;
                }
            }else if(model[j]=='*')
            {
                if(lenm>leng)
                {
                    k--;
                }else {
                    //*补足长度为leng-lenm+1的字符串
                    bool hasgood=false;
                    for(int add=0;add<leng-lenm+1;add++,k++)
                    {
                        if(alpha[tgoal[k]-'a']==true)
                        {
                        hasgood=true;
                        break;
                        }
                    }
                    if(hasgood)
                    {
                        ok=false;
                        cout<<"NO"<<endl;
                        break;
                    }
                    k--;
                }
            }else {
                if(model[j]!=tgoal[k])
                {
                    ok=false;
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(ok)
            cout<<"YES"<<endl;
    }
    return 0;
}
