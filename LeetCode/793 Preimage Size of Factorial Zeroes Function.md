很明显就是N！有多少个5有多少个0。

有5均是5的倍数5,10,15,20,25(2个5)所以N前面有1+1+1+1+2....个5,那么这一串加起来是多少（K），就有5个数阶乘0的个数可以为K。

比赛做时一直想着K怎么拆分成这一串加起来，不能拆分就return 0，可以return 5;结果最后没发现规律，

赛后看discuss其他人的数学解释还没看懂。但是明显这一题二分查找可解，当时没想到二分，其实二分最大边界N=K*5就能满足N！至少有K个5。

binary search
```
class Solution {
public:
    int preimageSizeFZF(int K) {
       
        long long low=0,high=K;
        high*=5;
        long long X=-1;
        while(low<=high){
            long long mid=(low+high)>>1;
            int num=getFive(mid);
            if(num<K)
                low=mid+1;
            else if(num>K)
                high=mid-1;
            else {
                X=mid;
                break;
            }
        }
        if(X==-1)
            return 0;
        else return 5;
    }
private:
    //m!中素数p的幂次为m/p+m/(p*p)+m/(p*p*p)+....
    int getFive(long long m){
        int ret=0;
        long long p=5;
        while(m>=p)
        {        
            ret+=m/p;
            p*=5;
        }
        return ret;
    }
};
```
