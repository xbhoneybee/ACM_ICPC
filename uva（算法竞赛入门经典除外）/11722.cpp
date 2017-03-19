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
//uva 11722

int main()
{
    freopen("output.txt","w",stdout);
    int t,it=1,t1,t2,s1,s2,w;
    cin>>t;
    while(t--)
    {
        cin>>t1>>t2>>s1>>s2>>w;
        double ans=0,pre=0,ret=0;
        for(int i=t1;i<=t2;i++)
        {
            int down=max(s1,i-w);
            int up=min(s2,i+w);
            ret=0;
            if(up>down)
            {
                ret=up-down;
            }
            if(i>t1)ans+=(ret+pre)/2.;
            pre=ret;
        }
        printf("Case #%d: %.8f\n",it++,ans/((t2-t1)*(s2-s1)*1.));
    }
    return 0;
}
//sb 不知道哪错了
/*
int main()
{

    freopen("output.txt","w",stdout);
    int t=500,it=1;
    srand(time(NULL));
    //scanf("%d",&t);
    while(t--)
    {
        double t1,t2,s1,s2,w;
        t1=rand()%600;
        int det=rand()%300;
        t2=det+t1;
        s1=rand()%600;
        s2=s1+det;
        w=rand()%90+1;
        //scanf("%d %d %d %d %d",&t1,&t2,&s1,&s2,&w);
        cin>>t1>>t2>>s1>>s2>>w;
        if(t2-t1<=s2-s1)
        {
            swap(t1,s1);
            swap(t2,s2);
        }
        double S1,S2=(s2-s1)*(t2-t1);
        if((t2+w<=s1)||(t1-w>=s2))
            S1=0;
        else if((t2+w>=s1)&&(t2-w<=s1))
        {
            if(t2+w<=s2)
                S1=(t2+w-s1)*(t2+w-s1)/2.;
            else if(t1+w<=s1)
                S1=(2*t2-s1-s2+2*w)*(s2-s1)/2.;      //
            else if(t1+w<=s2)
                S1=S2-(s2-w-t1)*(s2-w-t1)/2.;
            else S1=S2;
        }else if((t1+w>=s2)&&(t1-w<=s2)){
            if(t1-w>=s1)
                S1=(s2+w-t1)*(s2+w-t1)/2.;
            else if(t2-w>=s2)
                S1=(2*t2-s1-s2-2*w)*(s2-s1)/2.; //
            else if(t2-w>=s1)
                S1=S2-(t2-w-s1)*(t2-w-s1)/2.;
            else S1=S2;
        }else {
            if((t2-w<=s2)&&(t2+w<=s2))
                S1=(t2+w-s1)*(t2+w-s1)/2.-(t2-w-s1)*(t2-w-s1)/2.;
            else if((t2-w<=s2)&&(t1+w<=s1))
                S1=(2*t2-s1-s2+2*w)*(s2-s1)/2.-(t2-w-s1)*(t2-w-s1)/2;//
            else if((t2-w<=s2)&&(t1+w>=s1)&&(t2-w>=s1)&&(t1+w<=s2))
                S1=S2-(t2-w-s1)*(t2-w-s1)/2.-(s2-t1-w)*(s2-t1-w)/2.;
            else if((t1-w<=s1)&&(t1+w<=s1))
                S1=(s2-s1)*(2*w);
            else if((t1-w<=s1)&&(t1+w>=s1))
                S1=(2*t2-s1-s2-2*w)*(s2-s1)/2.-(s2-t1-w)*(s2-t1-w)/2.;//
            else S1=(s2-t1+w)*(s2-t1+w)/2.-(s2-t1-w)*(s2-t1-w)/2.;
        }
        double ans=S1*1.0/S2;
        if(ans>1)ans=1;
        if(ans<0)ans=0;
        printf("Case #%d: %.8f\n",it++,ans);
        //cout<<t1<<" "<<t2<<" "<<s1<<" "<<s2<<" "<<w<<endl;
    }
    return 0;
}*/
