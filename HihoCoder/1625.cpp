#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
#define Pair pair<int,int>
using namespace std;

int Next[100005];
void getNext(string son)
{
    int j,k;
    j=0;k=-1;
    Next[0]=-1;
    int lens=son.size();
    while(j<lens)
    {
        if(k==-1||son[j]==son[k])
            Next[++j]=++k;
        else k=Next[k];
    }
}
int KMP(string &m,string &son)
{
    getNext(son);
    int i=0,j=0;
    int lenm=m.size();
    int lens=son.size();
    while(i<lenm&&j<lens)
    {
        if(j==-1||m[i]==son[j])
            {i++;j++;}
        else j=Next[j];
    }
    if(j==lens)
        return i;
    else return -1;

}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        string stra,strb;
        cin>>stra>>strb;
        int lenb=strb.size();
        string ssa;
        while(ssa.size()<lenb*2)
            ssa+=stra;
        int ans=KMP(ssa,strb);
        if(ans>0)
        {
            int lena=stra.size();
            if(ans%lena==0)
            ans=ans/lena;
            else ans=ans/lena+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
