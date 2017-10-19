
struct P
{
    string s;
    int num;
}p[250];
bool cmp(P a,P b)
{
    if(a.num!=b.num)
        return a.num>b.num;
    else return a.s<b.s;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
        string str;
        int num;
        cin>>str>>num;
        p[i].num=num;
        p[i].s=str;
        }
        sort(p,p+n,cmp);
        for(int i=0;i<n;i++)
        {
            cout<<p[i].s<<" "<<p[i].num<<endl;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            string str;
            cin>>str;
            for(int j=0;j<n;j++)
            {
               if(p[j].s==str)
               {
                   int sec=0;
                   if(j>0&&p[j].num==p[j-1].num)
                   {
                   while(j>0&&p[j].num==p[j-1].num)
                        {j--;sec++;}
                   }
                   cout<<j+1;
                   if(sec>0)
                        cout<<" "<<sec+1;
                   cout<<endl;
                   break;
               }
            }
        }
    }
    return 0;
}
