#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s=="#") break;
        int len=s.size();
        int ans=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!=' ')
            ans+=(i+1)*(s[i]-'A'+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
