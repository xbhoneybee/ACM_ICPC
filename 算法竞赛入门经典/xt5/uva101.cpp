#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


//Uva 101
int n;
vector<int>vec[30];
void output()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        for(int j=0;j<vec[i].size();j++)
        {
            cout<<" "<<vec[i][j];
        }
        cout<<endl;
    }
}
pair<int,int> find_pos(int ab)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<vec[i].size();j++)
            if(vec[i][j]==ab)
    {
        pair<int,int> p=make_pair(i,j);
        return p;
    }
}
void move_onto(int a,int b)
{
    if(a==b) return ;
    pair<int ,int>posa,posb;
    posa=find_pos(a);
    posb=find_pos(b);
    if(posa.first==posb.first)
        return ;
    for(int j=vec[posa.first].size()-1;j>=0;j--)
    {
        if(vec[posa.first][j]!=a)
        {
            vec[vec[posa.first][j]].push_back(vec[posa.first][j]);
            vec[posa.first].pop_back();
        }else {
            vec[posa.first].pop_back();
            break;
        }
    }
    for(int j=vec[posb.first].size()-1;j>=0;j--)
    {
        if(vec[posb.first][j]!=b)
        {
            vec[vec[posb.first][j]].push_back(vec[posb.first][j]);
            vec[posb.first].pop_back();
        }else {
            vec[posb.first].push_back(a);
            break;
        }
    }
}
void move_over(int a,int b)
{
    if(a==b) return ;
    pair<int ,int>posa,posb;
    posa=find_pos(a);
    posb=find_pos(b);
    if(posa.first==posb.first)
        return ;
    for(int j=vec[posa.first].size()-1;j>=0;j--)
    {
        if(vec[posa.first][j]!=a)
        {
            vec[vec[posa.first][j]].push_back(vec[posa.first][j]);
            vec[posa.first].pop_back();
        }else {
            vec[posa.first].pop_back();
            break;
        }
    }
    vec[posb.first].push_back(a);
}
void pile_onto (int a,int b)
{
    if(a==b) return ;
    pair<int ,int>posa,posb;
    posa=find_pos(a);
    posb=find_pos(b);
    if(posa.first==posb.first)
        return ;
    for(int j=vec[posb.first].size()-1;j>=0;j--)
    {
        if(vec[posb.first][j]!=b)
        {
            vec[vec[posb.first][j]].push_back(vec[posb.first][j]);
            vec[posb.first].pop_back();
        }else {
       for(int j=posa.second;j<vec[posa.first].size();j++)
        vec[posb.first].push_back(vec[posa.first][j]);
        for(int j=vec[posa.first].size()-1;j>=0;j--)
        {
        if(vec[posa.first][j]!=a)
        {
            vec[posa.first].pop_back();
        }else {
            vec[posa.first].pop_back();
            break;
        }
        }
        break;
        }
    }
}
void pile_over(int a,int b)
{
    if(a==b) return ;
    pair<int ,int>posa,posb;
    posa=find_pos(a);
    posb=find_pos(b);
    if(posa.first==posb.first)
        return ;
    for(int j=posa.second;j<vec[posa.first].size();j++)
        {
            vec[posb.first].push_back(vec[posa.first][j]);
        }
    for(int j=vec[posa.first].size()-1;j>=0;j--)
        {
        if(vec[posa.first][j]!=a)
        {
            vec[posa.first].pop_back();
        }else {
            vec[posa.first].pop_back();
            break;
        }
        }
}
int main()
{
   //freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        vec[i].push_back(i);
    getchar();
    string cmd;
    while(cin>>cmd)
    {
        if(cmd=="quit")
        {
            output();
            break;
        }
        int a,b;
        string opt;
        cin>>a>>opt>>b;
        if(cmd[0]=='m')
        {
            if(opt[1]=='n')
                move_onto(a,b);
            else move_over(a,b);

        }
        else {
             if(opt[1]=='n')
                pile_onto(a,b);
            else
                pile_over(a,b);
        }
    }
    return 0;
}