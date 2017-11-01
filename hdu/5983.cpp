#include<bits/stdc++.h>
#include <iostream>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

int face[30];
int n;
int main()
{
    iosfalse
    cin>>n;
    while(n--)
    {
        for(int i=1;i<=24;i++)
            cin>>face[i];
        bool ok=false;

        for(int i=0;i<6;i++)
        {
            if(face[4*i+1]==face[4*i+2]&&face[4*i+1]==face[4*i+3]
               &&face[4*i+1]==face[4*i+4])
                {
                    if(i==5)
                        ok=true;
                }
            else break;
        }
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }
        ///6
        if(face[1]==face[2]&&face[1]==face[3]&&face[1]==face[4]
           &&face[9]==face[10]&&face[9]==face[11]&&face[9]==face[12]
           &&face[13]==face[14]&&face[13]==face[18]&&face[13]==face[20]
           &&face[15]==face[16]&&face[15]==face[22]&&face[15]==face[24]
           &&face[17]==face[19]&&face[17]==face[5]&&face[17]==face[6]
           &&face[7]==face[8]&&face[7]==face[21]&&face[7]==face[23])
            ok=true;
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }
        ///1
         if(face[13]==face[14]&&face[13]==face[15]&&face[13]==face[16]
           &&face[5]==face[6]&&face[5]==face[7]&&face[5]==face[8]
           &&face[1]==face[2]&&face[1]==face[23]&&face[1]==face[24]
           &&face[21]==face[22]&&face[21]==face[9]&&face[21]==face[10]
           &&face[11]==face[12]&&face[11]==face[19]&&face[11]==face[20]
           &&face[17]==face[18]&&face[17]==face[3]&&face[17]==face[4])
            ok=true;
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }
         ///2
         if(face[13]==face[14]&&face[13]==face[15]&&face[13]==face[16]
           &&face[5]==face[6]&&face[5]==face[7]&&face[5]==face[8]
           &&face[1]==face[2]&&face[1]==face[19]&&face[1]==face[20]
           &&face[21]==face[22]&&face[21]==face[3]&&face[21]==face[4]
           &&face[11]==face[12]&&face[11]==face[23]&&face[11]==face[24]
           &&face[17]==face[18]&&face[17]==face[9]&&face[17]==face[10])
            ok=true;
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }
        ///5
        if(face[1]==face[2]&&face[1]==face[3]&&face[1]==face[4]
           &&face[9]==face[10]&&face[9]==face[11]&&face[9]==face[12]
           &&face[13]==face[14]&&face[13]==face[21]&&face[13]==face[23]
           &&face[15]==face[16]&&face[15]==face[17]&&face[15]==face[19]
           &&face[22]==face[24]&&face[22]==face[5]&&face[22]==face[6]
           &&face[7]==face[8]&&face[7]==face[18]&&face[7]==face[20])
            ok=true;
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }
        ///3
        if(face[1]==face[3]&&face[1]==face[6]&&face[1]==face[8]
           &&face[9]==face[14]&&face[9]==face[11]&&face[9]==face[16]
           &&face[13]==face[15]&&face[13]==face[2]&&face[13]==face[4]
           &&face[17]==face[18]&&face[19]==face[17]&&face[17]==face[20]
           &&face[22]==face[24]&&face[22]==face[21]&&face[22]==face[23]
           &&face[7]==face[5]&&face[7]==face[10]&&face[7]==face[12])
            ok=true;
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }

        ///4
        if(face[1]==face[3]&&face[1]==face[16]&&face[1]==face[14]
           &&face[9]==face[11]&&face[9]==face[6]&&face[9]==face[8]
           &&face[13]==face[15]&&face[13]==face[12]&&face[13]==face[10]
           &&face[17]==face[18]&&face[19]==face[17]&&face[17]==face[20]
           &&face[22]==face[24]&&face[22]==face[21]&&face[22]==face[23]
           &&face[7]==face[5]&&face[7]==face[2]&&face[7]==face[4])
            ok=true;
        if(ok)
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
