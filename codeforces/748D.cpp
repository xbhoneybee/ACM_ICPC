#include <iostream>
#include<stdio.h>
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
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int state[100005];//0 unused -1 no use
int n,k;
string getstring ( const int n )
{
std::stringstream newstr;
newstr<<n;
return newstr.str();
}
int getint ( string s )
{
return atoi(s.c_str());
}
int cmp(string a,string b)
{
    string sa=a.substr(0,n);
    string sb=b.substr(0,n);
    if(sa!=sb)
    {
        return sa<sb;
    }else {
    int aa=getint(a.substr(n+1,a.size()));
    int bb=getint(b.substr(n+1,b.size()));
    return aa<bb;
    }
}
int ispalin(vector<string> &v,string goal)
{
    int sizes=v.size();
    int l=0,r=sizes-1;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(v[mid].substr(0,n)<goal)
            l=mid+1;
        else r=mid;
    }
    if(v[l].substr(0,n)==goal)
        return l;
    else return -1;
}
int main()  ///贪心,wa piont string sort is based on dictionary order
{
    cin>>k>>n;
    vector<string>vec;
    vector<int> more;//store only one palindrome
    vector<pair<int,int> >ppair;//store more than one palindrome
    for(int i=0;i<k;i++)
    {
        string tmp,vvv;
        int val;
        cin>>tmp>>val;
        vvv=getstring(val);
        vec.push_back(tmp+" "+vvv);
    }
    sort(vec.begin(),vec.end(),cmp);
    long long ans=0;
    for(int i=0;i<k;i++)
    {
        if(state[i]==-1)
            continue;
        string tmp=vec[i].substr(0,n);
        string rtmp="";
        for(int j=n-1;j>=0;j--)
        {
            rtmp+=tmp[j];
        }
        if(rtmp==tmp)
        {
            int m;
            for(m=i+1;m<k;m++)
            {
                if(tmp==vec[m].substr(0,n))
                    continue;
                else{
                    break;
                }
            }
            //处理i到m-1 这些相同的回文串;
            if(m-1>i){
            long long addtoans=0;
            for(int f=m-1;f>=i;f--)
            {
            int ftmp;
            ftmp=getint(vec[f].substr(n+1,vec[f].size()));
            if(ftmp<0)
            {
                if((m-1-f)&1)
                {
                int pretmp=getint(vec[f+1].substr(n+1,vec[f+1].size()));
                addtoans-=pretmp;
                if(pretmp+ftmp<=0)
                more.push_back(pretmp);
                else {
                pair<int,int> pir=make_pair(pretmp+ftmp,pretmp);
                ppair.push_back(pir);
                //之后从ppair中选second最大加入ans，其它pair的first加入ans;
                    }
                }
                break;
            }
            else if(ftmp==0)
            {
                break;
            }else {
                addtoans+=ftmp;
                }
            }
            int bbig=getint(vec[i].substr(n+1,vec[i].size()));
            if(bbig>0&&!((m-1-i)&1))
            {
                addtoans-=bbig;
                more.push_back(bbig);
            }
            ans+=addtoans;
            }else {
            int ad=getint(vec[i].substr(n+1,vec[i].size()));
            if(ad>0)
            more.push_back(ad);
            }
        i=m-1;
        }else{
            //二分查找rtmp是否存在
            int p=ispalin(vec,rtmp);
            if(p==-1)
            {
                state[i]=-1;
            }else if(state[p]==-1)
            {
                ;
            }
            else {
                //找出正序和反序的串的个数
                //记得用一个后面的标记一个-1；
                //正串起始i j逆串起始p q;
                int j=0,q=0;
                for( j=i;j<k;j++)
                    if(vec[j].substr(0,n)==vec[i].substr(0,n))
                    {state[j]=-1;continue;}
                    else break;
                j--;
                for( q=p;q<k;q++)
                    if(vec[q].substr(0,n)==vec[p].substr(0,n))
                    {state[q]=-1;continue;}
                    else break;
                q--;
                if(q-p>=j-i)
                {
                    for(int m=j;m>=i;m--)
                    {
                        int h1=getint(vec[m].substr(n+1,vec[m].size()));
                        int h2=getint(vec[q-(j-m)].substr(n+1,vec[q-(j-m)].size()));
                        if(h1+h2>0)
                            {
                                ans+=(h1+h2);
                            }
                        else break;
                    }
                }else {
                    for(int m=q;m>=p;m--)
                    {
                        int h1=getint(vec[m].substr(n+1,vec[m].size()));
                        int h2=getint(vec[j-(q-m)].substr(n+1,vec[j-(q-m)].size()));
                        if(h1+h2>0)
                            {
                                ans+=(h1+h2);
                            }
                        else break;
                    }
                }
                i=j;
            }
        }
    }
    int pos=0;
    for(int i=0;i<ppair.size();i++)
    {
        if(ppair[pos].second+ppair[i].first<ppair[pos].first+ppair[i].second)
            pos=i;
    }
    int moremax=0;
    int pairsec=0;
    sort(more.begin(),more.end());
    if(more.size()>0&&ppair.size()>0){
    moremax=more.at(more.size()-1);
    pairsec=ppair[pos].second;
    ans+=max(ppair[pos].first+moremax,pairsec);
    for(int i=0;i<ppair.size();i++)
    {
        if(i==pos)
            ;
        else ans+=ppair[i].first;
    }
    }else if(more.size()==0)
    {
        for(int i=0;i<ppair.size();i++)
        {
        if(i==pos)
            ans+=ppair[i].second;
        else ans+=ppair[i].first;
        }
    }else if(more.size()>0){
        moremax=more.at(more.size()-1);
        ans+=moremax;
    }
    cout<<ans<<endl;
    return 0;
}
