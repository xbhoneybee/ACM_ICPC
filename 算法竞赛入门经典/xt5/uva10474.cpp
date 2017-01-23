#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


//Uva 10474
int main()
{
   //freopen("output.txt","w",stdout);
    int n,k;
    int t=1;
    while(cin>>n>>k)
    {

        if(n==0&&k==0)
            break;
        cout<<"CASE# "<<t++<<":"<<endl;
        int tmp;
        vector<int>vec;
        for(int i=0;i<n;i++)
            {
                cin>>tmp;
                vec.push_back(tmp);
            }
        sort(vec.begin(),vec.end());
        for(int i=0;i<k;i++)
        {
            cin>>tmp;
            int ans=lower_bound(vec.begin(),vec.end(),tmp)-vec.begin();
            if(vec[ans]!=tmp)
                cout<<tmp<<" not found"<<endl;
            else cout<<tmp<<" found at "<<ans+1<<endl;
        }

    }
    return 0;
}
