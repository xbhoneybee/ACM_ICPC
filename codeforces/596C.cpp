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
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//  cin 和scanf不要混用！！！
//找到 满足 y-x=w[i]   序列，     判断是否满足条件

struct P {
    int val; //y-x
    int x;
    int y;
    int pos; //将来输出顺序
}po[100005];
struct W{
int wval;  //w[i]
int wpos;  //i
}w[100005];
int cmp0( P a,P b) //cmp0 || cmp1  随便用一个
{
    if(a.val!=b.val) return a.val<b.val;
    else  if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int cmp1( P a,P b)
{
    if(a.val!=b.val) return a.val<b.val;
    else  if(a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}
int cmp2( W a,W b)
{
    if(a.wval!=b.wval) return a.wval<b.wval;
    else   return a.wpos<b.wpos;
}
int cmp3(P a,P b)
{
    return a.pos<b.pos;
}
int main()
{
    iosfalse
    int n;
    cin>>n;
        for(int i=0;i<n;i++)
           {
               int s,t;
               cin>>s>>t;
               po[i].x=s;
               po[i].y=t;
               po[i].val=t-s;
               po[i].pos=i;
           }
           sort(po,po+n,cmp1);
        for(int i=0;i<n;i++)
            {
                int temp;
                cin>>temp;
                w[i].wpos=i;
                w[i].wval=temp;
            }
            sort(w,w+n,cmp2);
        //找到满足序列  先按y-x排序 和w 排序如果遍历一遍有不同则一定不行
        for(int i=0;i<n;i++)
        {
            if(po[i].val==w[i].wval)
            {
            po[i].pos=w[i].wpos;//最后以pos升序输出x,y
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        //如果都相同，为了满足美丽序列 对于相同w[i] 以i升序 相同point y-x 以cmp0 或cmp1 的次序升序
        //这时 相同y-x 满足美丽序列 不同的不能一定满足美丽序列
        //判断是否满足美丽序列
        sort(po,po+n,cmp3);
          for(int i=0;i<n-1;i++)
        {
            if(po[i].x<po[i+1].x||po[i].y<po[i+1].y)  //美丽序列条件的逆否
                continue;
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<po[i].x<<' '<<po[i].y<<endl;

    return 0;
}