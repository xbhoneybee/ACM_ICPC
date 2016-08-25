#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int r[3003],u[3003],s[3003];
//r recycle u used s sequence
int main()
{
	int n,m,t;
	while (cin >> n >> m) {
		t = n;
		memset(r, 0, sizeof(r));
		memset(u, 0, sizeof(u));
		int count = 0;
		r[count ++] = n/m;   //r[0] 整数部分;
		n = n%m;             //n为余数部分；    
		while (!u[n] && n) { //循环条件：余数未出现过并且余数不为零
			u[n] = count;    //u存储余数是否出现过及出现的次序
			s[count] = n;    //s存储第count个余数是什么
			r[count ++] = 10*n/m; //r存储小数部分结果，每一个int为一次除法的商
			n = 10*n%m;     //n换为新的余数
		}
		printf("%d/%d = %d",t,m,r[0]);
		printf(".");
		for (int i = 1 ; i < count && i <= 50 ; ++ i) {
			if (n && s[i] == n) printf("(");
			//通过余数寻找循环节起点
			//n==0表示整除
			printf("%d",r[i]);
		}
		if (!n) printf("(0"); //若整除,则循环节为0
		if (count > 50) printf("...");//只打印前50位
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);
		//count-u[n] u[n]为最终余数n出现的第一次sequence
	}
	return 0;
}
//uva202 经典 小数循环节
//电脑模拟手算，出现余数相同时循环结束。
//copy