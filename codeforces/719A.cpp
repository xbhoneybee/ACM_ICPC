#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e5
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//codeforces 9.23
//A

int a[100];
int main()
{
    int n;
    cin>>n;
    int state=-1;//0down 1 up
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(n==1&&(a[0]!=0&&a[0]!=15)) {
            cout<<"-1"<<endl;
            return 0;
        }
        else if(n==1&&a[0]==0)
        {
            cout<<"UP"<<endl;
            return 0;
        }else if(n==1&&a[0]==0)
        {
            cout<<"DOWN"<<endl;
            return 0;
        }
        if(i)
        {
            if(a[i]>a[i-1])
                state=1;
            else state=0;
        }
    }
    if(a[n-1]==0) state=1;
    if(a[n-1]==15) state=0;
    if(state==1)
        cout<<"UP"<<endl;
    else cout<<"DOWN"<<endl;
    return 0;
}
