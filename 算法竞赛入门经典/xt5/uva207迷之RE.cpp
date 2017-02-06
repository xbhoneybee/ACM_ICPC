//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#define ll long long
#define LL long long
#define inf 1
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//uva 207
string getstring ( const int n )
{
    std::stringstream newstr;
    newstr<<n;
    return newstr.str();
}
struct Player
{
string name;
int place;
int rd[5];
int total;
bool isdq1,isdq2;
double money;
Player()
{
    name="";
    place=-1;
    rd[0]=rd[1]=rd[2]=rd[3]=-1;
    total=0;
    isdq1=false;isdq2=false;
    money=0;
}
};
int getint ( string s )
{
    return atoi(s.c_str());
}
int cmd1(Player p1,Player p2)
{
    if(p1.isdq1==true&&p2.isdq1==true)
    {
        return p1.name<p2.name;
    }else if(p1.isdq1==true)
    {
        return 0;
    }
    else if(p2.isdq1==true)
    {
        return 1;
    }
    else {
        if( p1.rd[0]+p1.rd[1]!=p2.rd[0]+p2.rd[1])
            return p1.rd[0]+p1.rd[1]<p2.rd[0]+p2.rd[1];
        else return p1.name<p2.name;
    }
}
int cmd2(Player p1,Player p2)
{
    if(p1.isdq2==true&&p2.isdq2==true)
    {
        int p1turn=0,p2turn=0;
        int t1=0,t2=0;
        for(int i=0;i<4;i++)
        {
            if(p1.rd[i]!=-1)
                p1turn++;
            t1+=p1.rd[i];
            if(p2.rd[i]!=-1)
                p2turn++;
            t2+=p2.rd[i];
        }
        if(p1turn==p2turn)
        {
            if(t1==t2)
            return p1.name<p2.name;
            else return t1<t2;
        }else return p1turn>p2turn;
    }else if(p1.isdq2==true)
    {
        return 0;
    }
    else if(p2.isdq2==true)
    {
        return 1;
    }
    else {
        if(p1.total==p2.total)
        return p1.name<p2.name;
        else return p1.total<p2.total;
    }
}
int main()
{
    freopen("output.txt","w",stdout);
    int cases;
    cin>>cases;
    while(cases--)
    {
        printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
        printf("-----------------------------------------------------------------------\n");
        double PRIZE,per[71]={0};
        cin>>PRIZE;
        for(int i=0;i<70;i++)
            cin>>per[i];
        int PEOPLE;
        cin>>PEOPLE;
        Player player[150];
        for(int i=0;i<PEOPLE;i++)
        {
            string name;
            int times=0;
            cin>>name;
            player[i].name=name;
            while(cin>>name)
            {
                if(name!="DQ")
                {
                    player[i].rd[times++]=getint(name);
                }
                else
                {
                    if(times<2)
                    player[i].isdq1=true;
                    else player[i].isdq2=true;
                    break;
                }
                if(times==4)
                    {
                    player[i].total=player[i].rd[0]+player[i].rd[1]+player[i].rd[2]+player[i].rd[3];
                    break;
                    }
            }
        }
        sort(player,player+PEOPLE,cmd1);//晋级
        int cutnumber=70;
        while(player[69].rd[0]+player[69].rd[1]==player[cutnumber].rd[0]+player[cutnumber].rd[1])
            cutnumber++;
        sort(player,player+cutnumber,cmd2);//总排名
        int pce=1,binlie=0;
        for(int i=0;i<cutnumber;i++)//排名
        {
            if(player[i].total<player[i+1].total)
                {
                    pce+=binlie;
                    player[i].place=pce++;
                    binlie=0;
                }
            else
            {
                player[i].place=pce;
                binlie++;
            }
        }
        int monord=0;
        for(int i=0;i<cutnumber;i++)//分钱
        {
            if(player[i].place!=player[i+1].place)
                {
                    if(player[i].isdq2==false&&player[i].place<=70&&player[i].name.at(player[i].name.size()-1)!='*')
                        player[i].money=PRIZE*per[monord++];
                }
            else if(player[i].place<=70){
                int j,ave=0;
                for(int j=i+1;j<cutnumber;j++)
                    if(player[j].place!=player[j+1].place)
                        break;
                for(int k=i;k<=j;k++)
                    if(player[k].name[player[k].name.size()-1]!='*')
                        ave++;
                double summon=0;
                for(int k=0;k<ave;k++)
                {
                    summon+=PRIZE*per[player[i].place+k-1];
                }
                double avemon=summon/ave;
                for(int k=i;k<=j;k++)
                    if(player[k].name[player[k].name.size()-1]!='*')
                        player[k].money=avemon;
                monord+=ave;
                i=j;
            }
        }
        for(int i=0;i<cutnumber;i++)//输出
        {
            cout<<player[i].name;
            string kkk(21-player[i].name.size(),' ');
            cout<<kkk;
            cout<<player[i].place;
            if(i&&(player[i-1].place==player[i].place||player[i+1].place==player[i].place)&&player[i].name[player[i].name.size()-1]!='*')
                {
                    string p= getstring(player[i].place);
                    string kkkk(9- p.size(),' ');
                    cout<<"T"<<kkkk;
                }
            else{
                string p= getstring(player[i].place);
                string kkkk(10- p.size(),' ');
                cout<<kkkk;
                for(int ha=0;ha<4;ha++)
                {
                    if(player[i].rd[ha]!=-1)
                    {
                        string p=getstring(player[i].rd[ha]);
                        cout<<p<<string(5-p.size(),' ');

                    }else
                    cout<<string(5,' ');
                }
                if(player[i].total!=0)
                {
                    cout<<player[i].total;
                    string p=getstring(player[i].total);
                    cout<<string(10-p.size(),' ');
                    printf("$%.2f",player[i].money);
                    int mmony=player[i].money;
                    p=getstring(mmony);
                    cout<<string(7-p.size(),' ');
                    cout<<endl;
                }else {
                cout<<"DQ                  "<<endl;
                }
            }
        }

        printf("\n");
    }
    return 0;
}
//看来和第四章的那题一样的RE原因，不懂。