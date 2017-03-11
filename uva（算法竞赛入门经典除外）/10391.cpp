#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;

//N 用set存储所有的单词，对于每个单词，遍历所有可能子单词组合，
//然后判断在set中是否都已经存储，若是则输出该单词。
//算法复杂度为O(n*lgn*|S|)，其中|S|表示单词最大长度。

int main()
{
    ios::sync_with_stdio(false);
    set<string> sets,setans;
    string s;
    while (!cin.eof())
    {
        cin>>s;
            sets.insert(s);
    }
    set<string>::iterator ip;
    for(ip=sets.begin();ip!=sets.end();ip++)
    {
        s=*ip;
        int len=s.size();
        for(int i=1;i<len;i++)
        {
            string s1=s.substr(0,i);
            string s2=s.substr(i,len-i);
            if(sets.count(s1)==1&&sets.count(s2)==1)
                {
                    setans.insert(s);
                }
        }
    }
    for(ip=setans.begin();ip!=setans.end();ip++)
        cout<<*ip<<endl;
    return 0;
}
