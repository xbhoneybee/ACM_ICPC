#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//Uva133
int vis[30];
int main()
{
    //freopen("output.txt","w",stdout);
    int n,k,m;
    while(scanf("%d %d %d",&n,&k,&m)!=EOF){
            if(n==0)
            break;
    memset(vis,0,sizeof vis);
    int t=0,i=0,j=1;
    int outa=0,outb=0;
    while(t<n)
    {
        int tmpi=0;
        while(tmpi<k)
        {
            if(vis[i+1]==0)
            {
                tmpi++;
                if(tmpi==k)
                  {
                    outa=i+1;
                    break;
                  }
            }
            i++;
            i%=n;
        }
        int tmpj=0;
        while(tmpj<m)
        {
            int jj=j-1+n;
            if(jj>n) jj%=n;
            if(vis[jj]==0)
            {
                tmpj++;
                if(tmpj==m)
                {
                  outb=jj;
                    break;
                }
            }
            j--;
            j=(j+n)%n;
        }
        if(outa!=outb)
        {
            printf("%3d",outa),t++,vis[outa]=1;
            if(outb!=0)//point
            printf("%3d",outb),t++,vis[outb]=1;
        }
        else{
            printf("%3d",outa),t++,vis[outa]=1;
        }
        if(t>=n)
        printf("\n");
        else printf(",");
    }
    }
    return 0;
}