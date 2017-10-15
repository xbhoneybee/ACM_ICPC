#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

//C

int main()
{
    iosfalse
    int q;
    cin>>q;
    while(q--)
    {
        long long n;
        cin>>n;
        if(n==1||n==2||n==3||n==11)
        {
            cout<<-1<<endl;
            continue;
        }
        int num=0;
        num=n/4;
        int sy=n-n/4*4;
        if(sy==0||sy==2)
            cout<<num<<endl;
        else{
            if(sy==1)
            {
                if(num-1>0)
                cout<<num-1<<endl;
                else cout<<-1<<endl;
            }
            else {
                if(num>=3)
                cout<<num-1<<endl;
                else
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}
