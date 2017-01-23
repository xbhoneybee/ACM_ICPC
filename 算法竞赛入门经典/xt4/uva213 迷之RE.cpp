#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//Uva 213
string mima[300];
string dictobin(int number,int bit)
{
    string str="";
    while(number>0)
    {
        if(number%2==0)
            str+="0";
        else str+="1";
        number/=2;
    }
    reverse(str.begin(),str.end());
    str="0000000"+str;
    str=str.substr(str.size()-bit,bit);
    return str;
}
void make_mima()
{
    int ord=0;
    int bit=1;
    for(;bit<8;bit++)
    {
        for(int i=0;i<(1<<bit)-1;i++)
        {
            mima[ord++]=dictobin(i,bit);
        }
    }
}
int wei (string a)
{
    if(a=="001")
        return 1;
    else if(a=="010")
        return 2;
    else if(a=="011")
        return 3;
    else if(a=="100")
        return 4;
    else if(a=="101")
        return 5;
    else if(a=="110")
        return 6;
    else
        return 7;
}
string make_ter(int len)
{
    string ret="";
    for(int i=0;i<len;i++)
        ret+="1";
    return ret;
}
int tl=0;
int getseq(string a)
{
    for(int i=0;i<300&&i<tl;i++)
        if(a==mima[i])
            return i;
    return 0;
}
int main()
{
   //freopen("output.txt","w",stdout);
    string title="",strnum="",stmp;
    make_mima();
    while(getline(cin,stmp))
    {
        if(stmp.size()>0&&(stmp[0]=='0'||stmp[0]=='1'))
            {
                strnum+=stmp;
                int len=strnum.size();
                if(strnum.substr(len-3,3)=="000")
                {
                    tl=title.size();
                    int start=0;
                    string ans="";
                    while(start<len)
                    {
                        string cur=strnum.substr(start,3);
                        start+=3;
                        int bitlen=wei(cur);
                        string termit=make_ter(bitlen);
                        for(;start+bitlen<len;start+=bitlen)
                        {
                            string ssr=strnum.substr(start,bitlen);
                            if(ssr==termit)
                            {
                                start+=bitlen;break;
                            }
                            int seq=getseq(ssr);
                            ans+=title.at(seq);
                        }
                    }
                    cout<<ans<<endl;
                    title="";
                    strnum="";
                }
            }
        else if(stmp.size()>0)
            title=stmp;
        else break;
    }
    return 0;
}

//string 在堆上分布内存，数组开到100010，哪里会RE??