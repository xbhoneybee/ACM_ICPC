#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
string getstring ( const int n )
{
std::stringstream newstr;
newstr<<n;
return newstr.str();
}
int getint ( string s )
{
return atoi(s.c_str());
}
int main()
{
    char mp[5][5];
    memset(mp,0,sizeof mp);
    for(int i=0;i<4;i++)
        scanf("%s",mp[i]);
    int state=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
            {
                if(mp[i][j]=='x'&&mp[i][j+1]=='x'&&mp[i][j+2]=='.')
                state=1;
                if(mp[i][j]=='.'&&mp[i][j+1]=='x'&&mp[i][j+2]=='x')
                state=1;
                if(mp[i][j]=='x'&&mp[i][j+1]=='.'&&mp[i][j+2]=='x')
                state=1;
            }
    }
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<2;i++)
            {
                if(mp[i][j]=='x'&&mp[i+1][j]=='x'&&mp[i+2][j]=='.')
                state=1;
                if(mp[i][j]=='.'&&mp[i+1][j]=='x'&&mp[i+2][j]=='x')
                state=1;
                if(mp[i][j]=='x'&&mp[i+1][j]=='.'&&mp[i+2][j]=='x')
                state=1;
            }
    }
    for(int i=0;i<2;i++)
    {
        if(mp[i][i]=='x'&&mp[i+1][i+1]=='x'&&mp[i+2][i+2]=='.')
        state=1;
        if(mp[i][3-i]=='x'&&mp[i+1][2-i]=='x'&&mp[i+2][1-i]=='.')
            state=1;
        if(mp[i][3-i]=='.'&&mp[i+1][2-i]=='x'&&mp[i+2][1-i]=='x')
            state=1;
        if(mp[i][3-i]=='x'&&mp[i+1][2-i]=='.'&&mp[i+2][1-i]=='x')
            state=1;
        if(mp[i][i]=='.'&&mp[i+1][i+1]=='x'&&mp[i+2][i+2]=='x')
        state=1;
        if(mp[i][i]=='x'&&mp[i+1][i+1]=='.'&&mp[i+2][i+2]=='x')
        state=1;
    }
    string s="";
    for(int i=0;i<3;i++)
        s+=mp[i][i+1];
    if(s=="x.x"||s==".xx"||s=="xx.")
        state=1;
    s="";
    s+=mp[0][2];s+=mp[1][1];s+=mp[2][0];/////
    if(s=="x.x"||s==".xx"||s=="xx.")
        state=1;
    s="";
    for(int i=0;i<3;i++)
        s+=mp[i+1][i];
    if(s=="x.x"||s==".xx"||s=="xx.")
        state=1;
    s="";
    s+=mp[1][3];s+=mp[2][2];s+=mp[3][1]; /////
    if(s=="x.x"||s==".xx"||s=="xx.")
        state=1;
    if(state==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
