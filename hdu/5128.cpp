#include<bits/stdc++.h>
#include <iostream>
using namespace std;

bool mp[205][205];
vector<pair<int,int> >vec;

struct Rec{
int p[4];
int S;
};
vector<Rec>RRRec;
bool cmp(int a,int b)
{
    if(vec[a].first!=vec[b].first)
        return vec[a].first<vec[b].first;
    else return vec[a].second<vec[b].second;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n&&n)
    {
        vec.clear();
        RRRec.clear();
        memset(mp,false,sizeof mp);
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            mp[x][y]=true;
            vec.push_back(make_pair(x,y));
        }
        for(int a=0;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                for(int c=b+1;c<n;c++)
                {
                    for(int d=c+1;d<n;d++)
                    {
                        Rec rec;
                        rec.p[0]=a;
                        rec.p[1]=b;
                        rec.p[2]=c;
                        rec.p[3]=d;
                        sort(rec.p,rec.p+4,cmp);
                        if(vec[rec.p[0]].first==vec[rec.p[1]].first&&vec[rec.p[2]].first==vec[rec.p[3]].first
                           &&vec[rec.p[0]].second==vec[rec.p[2]].second&&vec[rec.p[1]].second==vec[rec.p[3]].second)
                            {
                                rec.S=(vec[rec.p[1]].second-vec[rec.p[0]].second)*
                                (vec[rec.p[2]].first-vec[rec.p[0]].first);
                                RRRec.push_back(rec);
                            }
                    }
                }
            }
        }
        int ans=0;
        int m=RRRec.size();
        for(int a=0;a<m;a++)
        {
            for(int b=a+1;b<m;b++)
            {
                bool ok=true;
                for(int k=0;k<4;k++)
                {
                    if(vec[RRRec[b].p[k]].first<=vec[RRRec[a].p[3]].first
                       &&vec[RRRec[b].p[k]].first>=vec[RRRec[a].p[1]].first
                       &&vec[RRRec[b].p[k]].second<=vec[RRRec[a].p[3]].second
                       &&vec[RRRec[b].p[k]].second>=vec[RRRec[a].p[2]].second)
                        ok=false;
                }
                for(int k=0;k<4;k++)
                {
                    if(vec[RRRec[a].p[k]].first<=vec[RRRec[b].p[3]].first
                       &&vec[RRRec[a].p[k]].first>=vec[RRRec[b].p[1]].first
                       &&vec[RRRec[a].p[k]].second<=vec[RRRec[b].p[3]].second
                       &&vec[RRRec[a].p[k]].second>=vec[RRRec[b].p[2]].second)
                        ok=false;
                }
                if(ok)
                    ans=max(ans,RRRec[a].S+RRRec[b].S);

                ok=true;
                for(int k=0;k<4;k++)
                {
                    if(vec[RRRec[b].p[k]].first<vec[RRRec[a].p[3]].first
                       &&vec[RRRec[b].p[k]].first>vec[RRRec[a].p[1]].first
                       &&vec[RRRec[b].p[k]].second<vec[RRRec[a].p[3]].second
                       &&vec[RRRec[b].p[k]].second>vec[RRRec[a].p[2]].second)
                       ;
                    else ok=false;
                }
                if(ok)
                     ans=max(ans,max(RRRec[a].S,RRRec[b].S));
                ok=true;
                for(int k=0;k<4;k++)
                {
                    if(vec[RRRec[a].p[k]].first<vec[RRRec[b].p[3]].first
                       &&vec[RRRec[a].p[k]].first>vec[RRRec[b].p[1]].first
                       &&vec[RRRec[a].p[k]].second<vec[RRRec[b].p[3]].second
                       &&vec[RRRec[a].p[k]].second>vec[RRRec[b].p[2]].second)
                       ;
                    else ok=false;
                }
                if(ok)
                     ans=max(ans,max(RRRec[a].S,RRRec[b].S));

            }
        }
        if(ans==0)
            cout<<"imp"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
