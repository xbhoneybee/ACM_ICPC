#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<2*n-1;j++)
    {
        if(i<=j&&i+j<=2*n-2)
            cout<<'#';
        else
            cout<<' ';
        if(j==2*n-2)
            cout<<endl;
    }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
