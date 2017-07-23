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

const double PI=acos(-1.0);
class point{
public :
int x,y;
point(int a,int b)
{
    x=a;y=b;
}
double len()
{
    return sqrt(x*x+y*y);
}
};
double dot(point a,point b){
    return a.x*b.x+a.y*b.y;
}
int iscontain(double gx,double gy,int ax,int ay,int bx,int by,int cx,int cy)
{
    point p1(ax-gx,ay-gy);
    point p2(bx-gx,by-gy);
    point p3(cx-gx,cy-gy);
    double len1=p1.len();
    double len2=p2.len();
    double len3=p3.len();

    double sum=acos((dot(p1,p2)/(len1*len2)))+acos((dot(p1,p3)/(len1*len3)))+acos((dot(p3,p2)/(len3*len2)));

    if(fabs(sum-2*PI)<1e-5)
        return 1;
    else
        return 0;
}
int main()
{
    iosfalse
    int T=0;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int x[10],y[10];
        for(int i=1;i<=6;i++)
            cin>>x[i]>>y[i];
        bool inter=false;
        for(int i=1;i<=3;i++)
        {
            for(int j=4;j<=6;j++)
            {
                if(x[i]==x[j]&&y[i]==y[j])
                    inter=true;
            }
        }
        if(inter)
        {
            cout<<"intersect"<<endl;
        }else{
        int AinB=0,BinA=0;
        AinB+=iscontain(x[1],y[1],x[4],y[4],x[5],y[5],x[6],y[6]);
        AinB+=iscontain(x[2],y[2],x[4],y[4],x[5],y[5],x[6],y[6]);
        AinB+=iscontain(x[3],y[3],x[4],y[4],x[5],y[5],x[6],y[6]);
        BinA+=iscontain(x[4],y[4],x[1],y[1],x[2],y[2],x[3],y[3]);
        BinA+=iscontain(x[5],y[5],x[1],y[1],x[2],y[2],x[3],y[3]);
        BinA+=iscontain(x[6],y[6],x[1],y[1],x[2],y[2],x[3],y[3]);
        if(AinB==0&&BinA==0)
            cout<<"disjoint"<<endl;
        else if((AinB==3&&BinA==0)||(AinB==0&&BinA==3))
            cout<<"contain"<<endl;
        else cout<<"intersect"<<endl;
        }
    }
    return 0;
}
