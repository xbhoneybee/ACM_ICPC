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
#define inf 1e18
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//codeforeces
//A
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int k=0;
    int num=0;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
            num++;
        else
        {
            if(num!=0)
            {
                vec.push_back(num);
                k++;
                num=0;
            }
        }
    }
    if(num!=0)
    {
        vec.push_back(num);
        k++;
    }
    cout<<k<<endl;
    for(int i=0;i<vec.size();i++)
        {
            cout<<vec[i];
            if(i<vec.size()-1)
                cout<<" ";
        }
    if(vec.size()!=0) cout<<endl;
    return 0;
}
