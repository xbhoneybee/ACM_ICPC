#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
#define Pair pair<int,int>
using namespace std;
string getstr(int x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}
bool check1(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='1'&&str[i]!='2'&&str[i]!='5'&&str[i]!='6'&&str[i]!='8'&&str[i]!='9'
           &&str[i]!='0')
            return false;
    }
    return true;
}
string fan(string str)
{
    string ret;
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='5'||str[i]=='8')
            ret+=str[i];
        else if(str[i]=='6')
            ret+='9';
        else ret+='6';
    }
    return ret;
}
int getint(string str)
{
    int x;
    sscanf(str.c_str(),"%d",&x);
    return x;
}
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        string str;
        str=getstr(i);
        if(check1(str)==false)
            {
                continue;
            }

        str=fan(str);

        if(str[0]=='0')
            continue;
        int x=getint(str);
        if(x!=i&&x<=N)
            cout<<i<<endl;
    }
    return 0;
}
