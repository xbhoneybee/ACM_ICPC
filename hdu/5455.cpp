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




//F

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
  //  freopen("a.txt","r",stdin);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        string s;
        cin>>s;
        bool hasc=false,nos=true;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]!='c'&&s[i]!='f')
            {
                nos=false;
                break;
            }
        }
        if(nos==false)
        {
            printf("Case #%d: -1\n",t);
            continue;
        }
        for(int i=0;i<len;i++){
            if(s[i]=='c')
                hasc=true;
        }
        if(!hasc){
            printf("Case #%d: %d\n",t,len/2+len%2);
            continue;}
        for(int i=0;i<len;i++){
            if(s[i]=='c')break;
            s+="f";
        }
        len=s.length();
        vector<int> cp;
        for(int i=0;i<len;i++)
            if(s[i]=='c')cp.push_back(i);
        bool ok=true;
        for(int i=0;i<cp.size()-1;i++){
            if(cp[i+1]-cp[i]<3){
                ok=false;
                break;
            }
        }
        if(len-cp[cp.size()-1]<3)ok=false;
        if(!ok){
            printf("Case #%d: -1\n",t);
        }else{
            printf("Case #%d: %d\n",t,cp.size());
        }
    }
    return 0;
}
