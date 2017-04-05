//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

int main()
{
    string a;
    cin>>a;
    int num=0;
    while(a[num]=='0')
        num++;
    a=a.substr(num);
    num=0;
    for(int i=0;i<a.size();i++)
        num+=a[i]-'0';
    if(num%3==0)
        cout<<a<<endl;
    else {
        int minuss=num%3;
        bool finded=false;
        string ans=a;
        int del=0;
        map<int,string>mp;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if((ans[i]-'0')%3==minuss)
            {
                if(i==0&&ans.size()==1)
                {
                    cout<<-1<<endl;
                    return 0;
                }else if(i==0){
                    if(ans[i+1]!='0')
                    {
                        ans=ans.substr(1);
                        cout<<ans<<endl;
                        return 0;
                    }else{
                        del=2;
                        i=i+2;
                        while(i<ans.size()&&ans[i++]=='0')
                            del++;
                        if(del>=ans.size())
                            {
                                cout<<0<<endl;return 0;
                            }
                        else mp[del]=ans.substr(del);
                        break;
                    }
                }else{
                    ans=ans.substr(0,i)+ans.substr(i+1);
                    while(ans[0]=='0'&&ans.size()>1)
                        ans=ans.substr(1);
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
        del=0;
        int pos1=-1,pos2=-1;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if((ans[i]-'0')%3!=0&&(ans[i]-'0')%3!=minuss&&del==0)
            {
                del++;
                pos1=i;
            }else if((ans[i]-'0')%3!=0&&(ans[i]-'0')%3!=minuss&&del==1)
            {
               if(i==0&&ans[i+1]=='0')
               {
                    del=3;
                    i=i+2;
                    while(i<ans.size()&&ans[i++]=='0')
                        del++;
                    if(del>=ans.size())
                        {
                            mp[del-1]="0";
                        }
                    else if(del>=pos1)
                    {
                        mp[del]=ans.substr(pos1+1);
                    }else{
                        mp[del]=ans.substr(del-1,pos1-del+1)+ans.substr(pos1+1);
                    }
                    break;
               }else{
                    ans=ans.substr(0,i)+ans.substr(i+1,pos1-i-1)+ans.substr(pos1+1);
                    while(ans[0]=='0'&&ans.size()>1)
                        ans=ans.substr(1);
                    if(ans=="")
                        ans="-1";
                    cout<<ans<<endl;
                    return 0;
               }
            }
        }
        if(mp.size()==0)
            cout<<-1<<endl;
        else {
            for(int i=2;;i++)
            {
                if(mp.count(i))
                {
                    ans=mp[i];
                    while(ans[0]=='0'&&ans.size()>1)
                        ans=ans.substr(1);
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
