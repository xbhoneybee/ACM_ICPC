#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e18
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
//比赛最后一小时写排序算法，最后10min改来改去，结果去重没考虑完全wa，不能直接与之前的比较。
//听说还有trie的写法，之后学习一个。
struct S
{
    string pres;
    string subs;
    string str;
    vector<string> vec;
   void init()
    {
        pres.clear();
        subs.clear();
        str.clear();
        vec.clear();
    }
};
S book[50];
int cmp(S a, S b)
{

    int len=min(a.vec.size(),b.vec.size());
    for(int i=0;i<len;i++)
    {
        if(a.vec.at(i)!=b.vec.at(i))
            return a.vec.at(i)<b.vec.at(i);
    }
    if(a.vec.size()!=b.vec.size())
    return (a.vec.size()>b.vec.size());
    else
        return a.subs<b.subs;

}
void getans(int sum)
{
    int flag=0;
    int nots=0;
    sort(book,book+sum+1,cmp);
    for(int i=0;i<=sum;i++ )
    {
        if(i+1<=sum&&book[i].str==book[i+1].str)
            {
                continue;
            }
        if(flag==0)
        {
        for(int fir=0;fir<book[i].vec.size();fir++)
            {
                for(int ttt=0;ttt<fir;ttt++) cout<<"    ";
                cout<<book[i].vec.at(fir)<<endl;
            }
            for(int ttt=0;ttt<book[i].vec.size();ttt++) cout<<"    ";
            cout<<book[i].subs<<endl;
            flag=1;
            nots=i;
        }
        else
        {
            int dif;
            for(dif=0;dif<book[i].vec.size();dif++)
            {
                if(book[i].vec[dif]!=book[nots].vec[dif])
                    {
                        break;
                    }
            }
            for(;dif<book[i].vec.size();dif++)
                {
                    for(int ttt=0;ttt<dif;ttt++) cout<<"    ";
                    cout<<book[i].vec[dif]<<endl;
                }
            for(int ttt=0;ttt<book[i].vec.size();ttt++) cout<<"    ";
            cout<<book[i].subs<<endl;
            nots=i;
        }
    }
}
int main()
{
    int i=0;
    int it=1;
    int space=0;
    while(!cin.eof())
    {
        getline(cin,book[i].str);
        if(book[i].str=="0")
        {
            cout<<"Case "<<it<<":"<<endl;
            for(int w=0;w<space;w++) cout<<endl;
            getans(i-1);
            i=0;
            space=0;
            it++;
            for(int tp=0;tp<50;tp++)
                book[tp].init();
            continue;
        }
        else if(book[i].str=="")
        {
            space=1;
        }
        else
        {
            int len=book[i].str.size();
            int j;
            for( j=len-1;j>=0;j--)
            {
                if(book[i].str[j]=='/')
                    {
                        book[i].pres=book[i].str.substr(0,j+1);
                        book[i].subs=book[i].str.substr(j+1,len-j-1);
                        break;
                    }
            }
            if(j==-1) {book[i].subs=book[i].str;}
            int ppr=0;
            for(int k=0;k<=j;k++)
            {
                if(book[i].pres.at(k)=='/')
                {
                    string st=book[i].pres.substr(ppr,k-ppr);
                    book[i].vec.push_back(st);
                    ppr=k+1;
                }
            }
         i++;
        }
    }
    return 0;
}
