#include<bits/stdc++.h>
#include <iostream>

using namespace std;




int main()
{
    int T;
    cin>>T;
    int a,b;
    while(T--)
    {
        cin>>a>>b;
        cout<<(a+b+max(a,b))<<endl;
    }
    return 0;
}
