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

int MinimumRepresentation(char *str) { //最小表示法
    int i,j,l,m=strlen(str);
    i=0;
    j=1;
    while(i<m && j<m) {
        for(l=0; l<m; l++)
            if(str[(i+l)%m]!=str[(j+l)%m]) break;
        if(l>m) break;
        if(str[(i+l)%m] > str[(j+l)%m])
            i=i+l+1;
        else
            j=j+l+1;
        if(i==j) j=i+1;
    }
    if(i<j) return i;
    return j;
}
char str[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        printf("%d\n",MinimumRepresentation(str)+1);
    }
    return 0;
}
