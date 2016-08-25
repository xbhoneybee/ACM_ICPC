#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c))
    {
        if(a==0&&b==0&&c==0)
            return 0;
    int divint=a/b;
    a=a%b;
    int fen[105];
    for(int i=0;i<=c;i++)
    {
        a*=10;
        fen[i]=a/b;
        a%=b;
        if(i==c&&fen[c]>=5)
        fen[c-1]++;
    }
    cout<<divint<<'.';
    for(int i=0;i<c;i++)
        cout<<fen[i];
    cout<<endl;
    }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//由于计算机double只能储存15？17？位小数 而c<=100 ,不能直接算，考虑模拟手算过程。注意最后一位四舍五入。