#include<bits/stdc++.h>
#include <iostream>
using namespace std;
double a[100];
double calc(double a1,double a2,double a3){
    if(a1+a2<=a3||a1+a3<=a2||a2+a3<=a1)return 0;
    double p=(a1+a2+a3)/2;
    return sqrt(p*(p-a1)*(p-a2)*(p-a3));
}
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            a[i+n]=a[i];
        }
        double res=0;
        int num=n/3;
        for(int i=0;i<3;i++){
            double tem=0;
            for(int k=0;k<num;k++){
                tem+=calc(a[i+k*3],a[i+1+k*3],a[i+2+k*3]);
            }
            res=max(res,tem);
        }
        printf("%.2f\n",res);
    }


    return 0;
}
