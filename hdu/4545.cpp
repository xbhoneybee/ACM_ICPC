#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 10000//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

struct Node{
char undo;
char done;
}node[101];
int main()
{
    iosfalse
    int t;
    cin>>t;
    for(int baba=1;baba<=t;baba++)
    {
        string a,b;
        cin>>a>>b;
        int lena=a.size();
        int lenb=b.size();
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>node[i].undo>>node[i].done;
        int i,j;
        for( i=0,j=0;i<lena&&j<lenb;)
        {
            if(a[i]==b[j])
            {
                i++;j++;continue;
            }
            for(int k=0;k<m;k++)
            {
                if(node[k].undo==b[j]&&node[k].done==a[i])
                {
                    i++;j++;
                    break;
                }
                if(k==m-1)
                {
                    j++;
                }
            }
            if(m==0) j++;
        }
        if(i==lena) cout<<"Case #"<<baba<<": "<<"happy"<<endl;
        else cout<<"Case #"<<baba<<": "<<"unhappy"<<endl;
    }
    return 0;
}
