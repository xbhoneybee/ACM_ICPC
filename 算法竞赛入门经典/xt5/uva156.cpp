#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


//uva156
void Tolower(string& str)
{
    transform(str.begin(),str.end(),str.begin(),::tolower);
}
string change(string ssr)
{
    Tolower(ssr);
    sort(ssr.begin(),ssr.end());
    return ssr;
}
int main()
{
    //freopen("output.txt","w",stdout);
    string str;
    map<string,string>mp;
    while(cin>>str)
    {
        if(str=="#")
            break;
        string tpstr=change(str);
        if(mp.count(tpstr)==1)
        {
            mp[tpstr]="-1";
        }else mp[tpstr]=str;
    }
    vector<string>vec;
    map<string,string>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second!="-1")
                vec.push_back(it->second);
        }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0;
}