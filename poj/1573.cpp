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
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
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
//poj 1573
int n,m,wte;
char mpc[15][15];
int mpi[15][15];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int inmp(int x,int y){
    if(x<0||x>=n||y<0||y>=m)
        return 0;
    return 1;
}
void mov(int &x,int &y)
{
    switch(mpc[x][y]){
    case 'W':y+=dy[1];break;
    case 'E':y+=dy[0];break;
    case 'N':x+=dx[2];break;
    case 'S':x+=dx[3];break;
    }
}
int main()
{
    while(scanf("%d %d %d",&n,&m,&wte)){
        if(n==0&&m==0&&wte==0)
            break;
        memset(mpc,0,sizeof mpc);
        memset(mpi,-1,sizeof mpi);
        for(int i=0;i<n;i++)
            scanf("%s",mpc[i]);
        int x=0,y=wte-1;
        int steps=0,output=0;
        mpi[x][y]=steps;
        while(true){
            steps++;
            mov(x,y);
            if(inmp(x,y))
             {
                if(mpi[x][y]==-1)
                    mpi[x][y]=steps;
                else {
                    output=mpi[x][y];
                    break;
                }
             }else {
                output=-1;
                break;
             }
        }
        if(output==-1)
            printf("%d step(s) to exit\n",steps);
        else {
            printf("%d step(s) before a loop of %d step(s)\n",output,steps-output);
        }
    }
    return 0;
}
/*TRICK
 *2 2 1
 *SW
 *EN
 *0 step(s) before a loop of 4 step(s)
 */
