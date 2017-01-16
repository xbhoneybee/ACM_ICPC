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

//C
int c[200005];
int d[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d %d",&tmp,&d[i]);
        c[i]=c[i-1]+tmp;
    }
    int infi=1;
    int x1=-1e8,x2=1e8;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==2)
            infi=0;
        if(d[i]==1)
        {
            x2=min(x2,c[i-1]);
        }else{
            x1=max(x1,c[i-1]);
        }
    }
    if(infi==1){
        cout<<"Infinity"<<endl;
    }else
    {
        if(x2==1e8)
        {
            int ans=1899-x1+c[n];
            cout<<ans<<endl;
        }
        else
        {
         if(1900-x2>1899-x1)
        cout<<"Impossible"<<endl;
        else
            cout<<1899-x1+c[n]<<endl;
        }
    }

    return 0;
}
