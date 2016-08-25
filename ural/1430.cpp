#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;
// 这里不要直接交换a,b if a<b swap(a,b) then x,y need swap

int main() {
    int a, b, n, mx = 0, x = 0, y = 0;
    cin>>a>>b>>n;
    if(a > b) {
        int top = min(n/a, b);
        for(int i = 0;i <= top; i++) {
            int cur = (n-a*i)/b*b + a*i;
            if(cur > mx) {
                mx = cur;x = i; y = (n-a*i)/b;
            }
        }
    }
    else {
        int top = min(n/b, a);
        for(int i = 0;i <= top; i++) {
            int cur = (n-b*i)/a*a + b*i;
            if(cur > mx) {
                mx = cur;x = (n-b*i)/a; y = i;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}


详解：假设a > b，只需要暴力枚举x判断即可，上限top为min(n/a, b)，复杂度是O(sqrt(n))的。

证明很简单，如果x > b则可以写成 a(x + b) + by = ax + ab + by = ax + b(a+y)，
这里的x < b，即这种情况肯定是枚举到了的，所以上限设为min(n/a, b)。

