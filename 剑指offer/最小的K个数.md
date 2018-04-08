## 题目
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
## solution
O N解法 快排思想的分治，每次只维护其中一半，但是在最坏情况下可能退化为N2复杂度
```
//STL nth_element(start,start+n,end)会将第n大放在第n位，并且保证前n位比第n为小，后面的比第n位大。

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k>input.size())
            return vector<int>();
        nth_element(input.begin(),input.begin()+k,input.end());
        vector<int>vec(input.begin(),input.begin()+k);
        return vec;
    }
};
//自己写

```
