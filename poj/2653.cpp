#include <iostream>
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
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

/// 判断大小
const double eps=1e-8;
int cmp(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
///点-向量
const double pi=acos(-1.0);
inline double sqr(double x){
    return x*x;
}
struct point{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    void input(){
    scanf("%lf %lf",&x,&y);
    }
    friend point operator +(const point &a,const point &b){
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator -(const point &a,const point &b){
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator ==(const point &a,const point &b){
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator *(const double &a,const point &b){//将向量b放大a倍
        return point(a*b.x,a*b.y);
    }
    friend point operator *(const point &a,const double &b){//将向量a放大b倍
        return point(a.x*b,a.y*b);
    }
    friend point operator /(const point &a,const double &b){//将向量a放大b倍
        return point(a.x/b,a.y/b);
    }
    double norm(){//求向量模长
        return sqrt(sqr(x)+sqr(y));
    }
};
double det(const point &a,const point &b){//叉积
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a,const point &b){//点积
    return a.x*b.x+a.y*b.y;
}
double dist(const point &a,const point &b){//距离
    return (a-b).norm();
}
point rotate_point(const point &p,double A){//op 绕原点逆时针转A(弧度)
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}
///线段
struct line{
    int id;
    point a,b;//线段a->b
    line(){}
    line(point x,point y):a(x),b(y){}
};
line point_make_line(const point a,const point b){//2点确定1条直线
    return line (a,b);
}
double dis_point_segment(const point p,const point s,const point t){
    if(cmp(dot(p-s,t-s))<0) return (p-s).norm();//点p到线段st的距离(不是直线)
    if(cmp(dot(p-s,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));//p到直线st距离,利用面积计算.
}
void PointProjLine(const point p,const point s,const point t,point &cp){
    double r=dot((t-s),(p-s))/dot(t-s,t-s); //求p到st的垂足，保存在cp中
    cp=s+r*(t-s);
}
bool PointOnSegment(point p,point s,point t){
    return cmp(det(p-s,t-s))==0&&cmp(dot(p-s,p-t))<=0;
}
bool parallel(line a,line b){
    return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(line a,line b,point &res){//求2直线交点
    if(parallel(a,b)) return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);//待证明公式.
    if((res-a.a).norm()<(a.a-a.b).norm()&&(res-b.a).norm()<(b.a-b.b).norm()
       &&(res-a.b).norm()<(a.a-a.b).norm()&&(res-b.b).norm()<(b.a-b.b).norm())
    return true;
    else return false;
}
line move_d(line a,const double &len){//将直线a沿法向量方向平移距离len
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate_point(d,pi/2);//默认向量法向量逆时针转90°
    return line(a.a+d*len,a.b+d*len);
}
line lines[100005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        printf("Top sticks:");
        double x1,y1,x2,y2;
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            point p1(x1,y1);point p2(x2,y2);
            lines[i]=line(p1,p2);
        }
        vector<int> ans;
        ans.push_back(n);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                point res;
                if(line_make_point(lines[i],lines[j],res)==true)
                    break;
                if(j==n-1)
                    ans.push_back(i+1);
            }
        }
        int sizes=ans.size();
        for(int i=sizes-1;i>0;i--)
            printf(" %d,",ans[i]);
        printf(" %d.\n",ans[0]);
    }
    return 0;
}
