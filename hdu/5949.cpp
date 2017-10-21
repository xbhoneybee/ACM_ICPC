#include<bits/stdc++.h>
#include <iostream>

using namespace std;



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        int sum=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='H')
                sum+=1;
            if(str[i]=='O')
                sum+=16;
            if(str[i]=='C')
                sum+=12;
        }
        cout<<sum<<endl;
    }
    return 0;
}
