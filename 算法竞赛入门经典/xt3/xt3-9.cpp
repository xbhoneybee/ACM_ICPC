#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char s[100005],t[100005];
    while(scanf("%s %s",s,t)!=EOF){
        int ns=strlen(s),nt=strlen(t);
        int is=0;
        for(int it=0;it<nt;)
        {
            if(s[is]!=t[it])
                it++;
            else {
                is++;it++;
            }
        }
        if(is==ns)
            printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
//uva10340