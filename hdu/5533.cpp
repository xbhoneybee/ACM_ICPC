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

using namespace std;


//G

int main()
{
    int T;
    scanf("%d",&T);
    set<pair<int,int> >st;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        st.clear();
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            st.insert(make_pair(x,y));
        }
        bool ok=false;
        if(n!=4)
            goto there;
        for(auto a=st.begin();a!=st.end();a++)
        {
            for(auto b=st.begin();b!=a;b++)
            {
                pair<int,int> pa=*a,pc;
                pair<int,int> pb=*b,pd;
                if(pa.first==pb.first)
                {
                    int det=abs(pa.second-pb.second);
                    pc=make_pair(pa.first+det,pa.second);
                    pd=make_pair(pa.first+det,pb.second);
                    if(st.count(pd)&&st.count(pc))
                    {
                        ok=true;
                        goto there;
                    }
                }
                if(pa.second==pb.second)
                {
                    int det=abs(pa.first-pb.first);
                    pc=make_pair(pa.first,pa.second-det);
                    pd=make_pair(pb.first,pa.second-det);
                    if(st.count(pd)&&st.count(pc))
                    {
                        ok=true;
                        goto there;
                    }
                }
                int detx=abs(pa.first-pb.first);
                int dety=abs(pa.second-pb.second);
                if(pa.first>pb.first)
                        swap(pa,pb);
                if(pa.second<pb.second)
                    {
                        pc=make_pair(pa.first+dety,pa.second-detx);
                        pd=make_pair(pb.first+dety,pb.second-detx);
                        if(st.count(pd)&&st.count(pc))
                        {
                        ok=true;
                        goto there;
                        }
                    }
                    else {
                        pc=make_pair(pa.first+dety,pa.second+detx);
                        pd=make_pair(pb.first+dety,pb.second+detx);
                        if(st.count(pd)&&st.count(pc))
                        {
                        ok=true;
                        goto there;
                        }
                    }
            }
        }
        there :
            ;
        if(ok)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
