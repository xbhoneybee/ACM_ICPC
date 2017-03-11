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
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;

// queue

int main()
{

    int n;
    while(cin>>n&&n)
    {
        queue <int> q;
        cout<<"Discarded cards:";
        if(n==1)
        {
            cout<<endl;
             cout<<"Remaining card: "<<1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        int qt=q.front();
            cout<<' '<<qt;
            q.pop();
            qt=q.front();
            q.pop();
            q.push(qt);
        while(q.size()>1)
        {
            int qt=q.front();
            cout<<", "<<qt;
            q.pop();
            qt=q.front();
            q.pop();
            q.push(qt);
        }
        cout<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;
    }
    return 0;
}