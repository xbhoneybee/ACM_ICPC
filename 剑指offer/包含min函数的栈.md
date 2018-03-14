# 题目
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
## solution
再加一个栈保存最小值同步
```
class Solution {
private :
stack<int>st,minst;
public:
    void push(int value) {
        if(st.size()==0)
            minst.push(value);
        else if(minst.top()<value){
            minst.push(minst.top());
        }else minst.push(value);
        st.push(value);
    }
    void pop() {
       st.pop();
       minst.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return minst.top();
    }
};
```
