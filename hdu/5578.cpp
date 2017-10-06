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

int pos[300];
string str;
int main()
{
	int T,cas=1;
	cin>>T;
	while(T--)
    {
        cin>>str;
        int ans=1000000;
        memset(pos,-1,sizeof pos);
        for(int i=0;i<str.size();i++)
        {
            if(pos[str[i]-'a']==-1)
                pos[str[i]-'a']=i;
            else {
                ans=min(ans,i-pos[str[i]-'a']);
                pos[str[i]-'a']=i;
            }
        }
        if(ans==1000000)
            ans=-1;
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
        str.clear();
    }
	return 0;
}
