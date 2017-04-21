#include <bits/stdc++.h>
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

//cf ed19 C stack

int num[30];
int deal[30];
stack<char>st;
int main()
{
    string s;
    string u="";
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        num[s[i]-'a']++;
    }
    int cnt=0;
    while(num[cnt]==0)
        cnt++;
    for(int i=0;i<s.size();i++)
        {
            char tmp=s[i];
            if(tmp-'a'==cnt)
                {
                    u+=tmp;
                    deal[cnt]++;
                    if(deal[cnt]==num[cnt])
                    {
                        cnt++;
                        while((num[cnt]==0||num[cnt]==deal[cnt])&&cnt<26)
                            cnt++;
                        while(!st.empty()&&st.top()-'a'<=cnt)
                        {
                            u+=st.top();
                            st.pop();
                        }
                    }
                }
            else{
                st.push(tmp);
                deal[tmp-'a']++;
            }
        }
    while(!st.empty())
    {
        u+=st.top();
        st.pop();
    }
    cout<<u<<endl;
    return 0;
}
