```
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int>B;
        vector<int>sml,in,bg;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<L)
                B.push_back(-1),sml.push_back(i);
            else if(A[i]>R)
                B.push_back(1),bg.push_back(i);
            else B.push_back(0),in.push_back(i);
        }
        int ans=0;
        for(int i=0;i<B.size();i++)
        {
            if(B[i]==1)
                continue;
            else if(B[i]==-1)
            {
                int posin=lower_bound(in.begin(),in.end(),i)-in.begin();
                int posbg=lower_bound(bg.begin(),bg.end(),i)-bg.begin();
                if(posbg==bg.size())
                {
                    if(posin<in.size())
                    {
                        //add small 后面还有一堆in无big
                        ans+=B.size()-in[posin];
                    }else continue;
                }
                else if(posin==in.size()||in[posin]>bg[posbg])
                    continue;
                else {
                    //small先in 后big
                    ans+=bg[posbg]-in[posin];
                }
            }else{
                //处理in的情况
                int posbg=lower_bound(bg.begin(),bg.end(),i)-bg.begin();
                if(posbg==bg.size()){
                     ans+=B.size()-i;
                }else {
                    ans+=bg[posbg]-i;
                }
            }
        }
        return ans;
    }
};
```
