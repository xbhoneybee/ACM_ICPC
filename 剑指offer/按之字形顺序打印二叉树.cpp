## 题目
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
## solution
2个栈维护
```
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    stack<TreeNode* >left_st,right_st;
    int cnt=0;
    vector<vector<int> >ans;
    void PrintL()
    {
        vector<int>tmp;
        ans.push_back(tmp);
        while(left_st.size()>0)
        {
            TreeNode* pRoot=left_st.top();
            left_st.pop();
            ans[cnt].push_back(pRoot->val);
            if(pRoot->left!=NULL)
            right_st.push(pRoot->left);
            if(pRoot->right!=NULL)
            right_st.push(pRoot->right);
        }
        cnt++;
    }
    void PrintR()
    {
        vector<int>tmp;
        ans.push_back(tmp);
        while(right_st.size()>0)
        {
            TreeNode* pRoot=right_st.top();
            right_st.pop();
            ans[cnt].push_back(pRoot->val);
            if(pRoot->right!=NULL)
            left_st.push(pRoot->right);
            if(pRoot->left!=NULL)
            left_st.push(pRoot->left);
        }
        cnt++;
    }
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
    if(pRoot!=NULL){
        left_st.push(pRoot);
    while(true){
        if(cnt&1){
            if(right_st.size()==0)
                break;
            PrintR();
        }else {
            if(left_st.size()==0)
                break;
            PrintL();
        }
    }
    }
        return ans;
    }
};
```
