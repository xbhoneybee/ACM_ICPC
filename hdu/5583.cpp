#include <bits/stdc++.h>
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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


//K

char str[100005];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        vector<long long>vec;
        int len=strlen(str);
        long long ans=0;
        long long cnt=1;
        for(int i=1;i<len;i++)
        {
            if(str[i]==str[i-1])
            {
                cnt++;
            }else {
                ans+=1LL*cnt*cnt;
                vec.push_back(cnt);
                cnt=1;
            }
        }
        ans+=cnt*cnt;
        vec.push_back(cnt);
        long long primesum=ans;
        long long sum;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]<=1)
            {
                sum=primesum;
                long long tmp=1;
                sum--;
                if(i>0)
                    {
                        tmp+=vec[i-1];
                        sum-=vec[i-1]*1LL*vec[i-1];
                    }
                if(i+1<vec.size())
                    {
                        tmp+=vec[i+1];
                        sum-=vec[i+1]*1LL*vec[i+1];
                    }
                ans=max(ans,sum+tmp*tmp);
            }else {
                sum=primesum;
                if(i>0)
                    {
                        sum-=vec[i-1]*1LL*vec[i-1];
                        sum-=vec[i]*1LL*vec[i];
                        sum+=(vec[i]-1)*1LL*(vec[i]-1);
                        sum+=(vec[i-1]+1)*1LL*(vec[i-1]+1);
                        ans=max(ans,sum);
                    }
                sum=primesum;
                if(i+1<vec.size())
                    {
                        sum-=vec[i+1]*1LL*vec[i+1];
                        sum-=vec[i]*1LL*vec[i];
                        sum+=(vec[i]-1)*1LL*(vec[i]-1);
                        sum+=(vec[i+1]+1)*1LL*(vec[i+1]+1);
                        ans=max(ans,sum);
                    }
            }
        }
        printf("Case #%d: %I64d\n",cas++,ans);
    }
    return 0;
}
