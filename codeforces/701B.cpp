#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#define inf 100000000.000
using namespace std;

//ac  set 大法好，stl大法好，要用count 和insert
int main()
{
    long long  n,m;
    set <int>setx,sety;
    long long  ans[100005]={0};
    cin>>n>>m;
    ans[0]=n*n-2*n+1;
    //cout<<ans[0]<<endl;
    int x,y;
    cin>>x>>y;
    setx.insert(x);
    sety.insert(y);
    for(int i=1;i<m;i++)
    {

        cin>>x>>y;
        if(setx.count(x)==1&& sety.count(y)==1)
            ans[i]=ans[i-1];
        else if(setx.count(x)==1||sety.count(y)==1){

             if(setx.count(x)==1){
                sety.insert(y);
                ans[i]=ans[i-1]-n+setx.size();
                //cout<<setx.size()<<endl;

             }
             else{
                setx.insert(x);
                ans[i]=ans[i-1]-n+sety.size();
                //cout<<ans[i-1]<<' '<<ans[i]<<endl;
                //cout<<sety.size()<<endl;
             }
        }
        else{
            ans[i]=ans[i-1]-2*n+1+setx.size()+sety.size();
            setx.insert(x);
            sety.insert(y);
        }
    }
    for(int i=0;i<m-1;i++)
        cout<<ans[i]<<' ';
    cout<<ans[m-1]<<endl;
    return 0;
}
