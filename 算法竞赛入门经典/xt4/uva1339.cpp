#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
//uva1339  水题 LRJ已经说明思路
int main()
{
    char s1[102],s2[102];
    while(~scanf("%s %s",s1,s2))
    {
        int flag=1;
        int len1=strlen(s1);
        int len2=strlen(s2);
        int alpha1[30]={0};
        int alpha2[30]={0};
        for(int i=0;i<len1;i++)
            alpha1[s1[i]-'A']++;
        for(int i=0;i<len2;i++)
            alpha2[s2[i]-'A']++;
        sort(alpha1,alpha1+26);
        sort(alpha2,alpha2+26);
        for(int i=0;i<26;i++)
        {
            if(alpha1[i]!=alpha2[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
