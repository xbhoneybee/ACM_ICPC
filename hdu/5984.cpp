#include<bits/stdc++.h>
#include <iostream>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

int main(){
//    iosfalse
    int T;
    cin>>T;
    double l,d;
    for(int t=1;t<=T;t++){
        cin>>l>>d;
        l/=d;
        if(l<=1){
            cout<<"0.000000"<<endl;
        }else{
            printf("%.6f\n",1+log(l)/log(exp(1)));
        }
    }
    return 0;
}
