#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

int n,m,q;
long long tree[2510][2510];
int lowbit(int i)  
{  
    return i&(-i);  
}  
void add(int l,int r,long long v)  
{  
    for(int i=l;i<=n;i+=lowbit(i))  
        for(int j=r;j<=m;j+=lowbit(j))  
        tree[i][j] += v;  
}  
long long getsum(int l,int r)  
{  
    long long ans = 0;  
    for(int i=l;i;i-=lowbit(i))  
        for(int j=r;j;j-=lowbit(j))  
        ans += tree[i][j];  
    return ans;  
}  
map<pair< pair<int,int>,pair<int,int> >,long long >mp;
int main()
{
    cin>>n>>m>>q;
    long long val=1;
    while(q--)
    {
        int x1,y1,x2,y2,cmd;
        cin>>cmd>>x1>>y1>>x2>>y2;
        long long val=1;
        if(cmd==1)
        {
            val=(rand()<<20|rand());//优秀的hash种子
            mp[make_pair(make_pair(x1,y1),make_pair(x2,y2))]=val;
            add(x1,y2+1,-val);
            add(x2+1,y1,-val);
            add(x1,y1,val);
            add(x2+1,y2+1,val);
        }else if(cmd==2)
        {
            long long tmp=mp[make_pair(make_pair(x1,y1),make_pair(x2,y2))];
            add(x1,y2+1,tmp);
            add(x2+1,y1,tmp);
            add(x1,y1,-tmp);
            add(x2+1,y2+1,-tmp);
        }else {
            if(getsum(x1,y1)==getsum(x2,y2))
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
