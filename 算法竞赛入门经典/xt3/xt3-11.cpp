#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
//wa了好久  我好菜啊TAT
char s1[105],s2[105];
int n1[210],n2[210];//开2倍长 防止数组越界
int main()
{
    while(~scanf("%s %s",s1,s2))
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        memset(n1,0,sizeof n1);
        memset(n2,0,sizeof n2);
        for(int i=0;i<len1;i++)
            n1[i]=s1[i]-'0';     //用int数组比较可以比较某字符串结尾后面与另一字符串的值
        for(int i=0;i<len2;i++)
            n2[i]=s2[i]-'0';
        int i=0,j=0;
        int ans=max(len1,len2);
        for( i=0;i<len1;i++)
            {
                for( j=0;j<len2;j++)
                {
                    if(n1[i+j]+n2[j]>3)
                        break;
                }
                if(j==len2) break;
            }
        ans=i+len2;//wa 点 分别以s1 and s2 作为匹配串

        for( i=0;i<len2;i++)
            {
                for( j=0;j<len1;j++)
                {
                    if(n1[j]+n2[i+j]>3)
                        break;
                }
                if(j==len1) break;
            }
        ans=min(i+len1,ans);
        ans=max(max(len1,len2),ans);
        printf("%d\n",ans);
    }
    return 0;
}
//copy 
