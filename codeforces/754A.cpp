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
    int n;
    int a[105]={0};
    cin>>n;
    int sum=0;
    int k=0;
    for(int i=1;i<=n;i++)
       {
        cin>>a[i];
        if(a[i]!=0)
            k++;
        sum+=a[i];
       }
    if(sum==0)
    {
        if(k==0)
            {cout<<"NO"<<endl;return 0;}
        else
            cout<<"YES"<<endl;
            cout<<2<<endl;
        for(int i=0;i<n;i++)
            if(a[i]!=0)
            {
                cout<<1<<" "<<i<<endl;
                cout<<i+1<<" "<<n<<endl;
                break;
            }
    }else{
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
    }
}