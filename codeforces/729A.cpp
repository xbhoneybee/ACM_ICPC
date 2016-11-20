#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1000000009
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
//CF20161120
//A
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[200]={0};
    int pre=0;
    int st=1;
    for(int i=0;i<n;)
    {
        if(pre==0)
        {
            if(i+2<n&&s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
            {
                a[i]=st;a[i+1]=st;a[i+2]=st;
                pre=1;i+=3;
            }
            else i++;
        }
        else if(pre==1)
        {
            if(i+1<n&&s[i]=='g'&&s[i+1]=='o')
            {
                a[i]=st;a[i+1]=st;
                i+=2;
            }else{
            if(i+2<n&&s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
            {
                st++;
                a[i]=st;a[i+1]=st;a[i+2]=st;
                pre=1;i+=3;
            }
            else i++,pre=0;
            }
        }
    }
    for(int i=0;i<n;)
    {
        if(a[i]!=0)
            {
                int tmp=a[i];
                cout<<"***";
                while(i<n&&a[i]==tmp)
                    i++;
            }
        else cout<<s[i++];
    }
    cout<<endl;
    return 0;
}
