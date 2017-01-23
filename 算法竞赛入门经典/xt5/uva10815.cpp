#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


//Uva 10815
void Tolower(string& str)
{
    transform(str.begin(),str.end(),str.begin(),::tolower);
}
int main()
{
    //freopen("output.txt","w",stdout);
    set<string>st;
    string str;
    while(!cin.eof())
    {
        cin>>str;
      Tolower(str);
      string ssr="";
      for(int i=0;i<str.size();i++)
      {
        if(str[i]<'a'||str[i]>'z')
            {
                st.insert(ssr);
                ssr="";
            }
        else ssr+=str[i];
      }
      st.insert(ssr);
    }
    set<string>::iterator it;
    for(it=st.begin();it!=st.end();it++)
        {
            if(*it!="")
                cout<<*it<<endl;
        }
    return 0;
}
