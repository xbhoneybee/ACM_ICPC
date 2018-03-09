#include<bits/stdc++.h>
using namespace std;
//CF3.9
//C
//卡NlogN
//维护2个栈分别以0和1结尾的vector标号，遇到1找0遇到0找1或者新开一个vector
vector<int>ans[200000];
int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    int k=0;
    stack<int>st1,st0;
    
    for(int i=0;i<str.size();i++){
        if(str[i]=='1')
        {
            if(st0.size()==0)
            {
                cout<<-1<<"\n";
                return 0;
            }else {
                ans[st0.top()].push_back(i);
                st1.push(st0.top());
                st0.pop();
            }
        }else{
            if(st1.size()==0)
            {
                ans[k++].push_back(i);
                st0.push(k-1);
            }else {
                ans[st1.top()].push_back(i);
                st0.push(st1.top());
                st1.pop();
            }
        }
    }
    if(st1.size()>0)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<k<<"\n";
    for(int i=0;i<k;i++){
        cout<<ans[i].size();
        for(int j=0;j<ans[i].size();j++){
            cout<<" "<<ans[i][j]+1;
        }
        cout<<"\n";
    }
    return 0;
}
