#include <bits/stdc++.h>
using namespace std;
struct point{
	int a,b;
};
vector<int> G[1005];
int color[1005];
bool bipartite(int u){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(color[v]==color[u])return false;
		if(!color[v]){
			color[v]=3-color[u];
			if(!bipartite(v))return false;
		}
	}return true;
}
int n,m,cnt;
bool ok[1005];
// 判断图是不是二分图 
bool solve(){
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++)
		if(G[i].size()>0){
			color[i]=1;			
			return bipartite(i);
		}
	return false;	
}
point p[10005];
int main(){
	int size1,size2,tem;
	while(~scanf("%d%d%d%d",&n,&m,&size1,&size2)){
		cnt=0;
		memset(ok,0,sizeof(ok));
		for(int i=0;i<=n;i++)G[i].clear();
		set<int> good;
		set<int> bad;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&p[i].a,&p[i].b);
			ok[p[i].a]=ok[p[i].b]=1;
		}
		for(int i=1;i<=size1;i++)
			scanf("%d",&tem),good.insert(tem),ok[tem]=1;
		for(int i=1;i<=size2;i++)
			scanf("%d",&tem),bad.insert(tem),ok[tem]=1;
		for(int i=1;i<=n;i++){
			if(!ok[i]){
				printf("NO\n");
				goto nex;
			}
		}
		for(int i=1;i<=m;i++){
			if(good.count(p[i].a)){
				if(good.count(p[i].b)==0)
					bad.insert(p[i].b);
				else{
					printf("NO\n");
					goto nex;
				}
			}else if(bad.count(p[i].a)){
				if(bad.count(p[i].b)==0)
					good.insert(p[i].b);
				else{
					printf("NO\n");
					goto nex;
				}
			}else if(good.count(p[i].b)){
				bad.insert(p[i].a);
			}else if(bad.count(p[i].b)){
				good.insert(p[i].a);
			}else{
				cnt++;
				G[p[i].a].push_back(p[i].b);
				G[p[i].b].push_back(p[i].a);
			}
		}	
		if(cnt!=0&&!solve()){
			printf("NO\n");
		}else printf("YES\n");
		nex:
			;
	}
	return 0;
}
