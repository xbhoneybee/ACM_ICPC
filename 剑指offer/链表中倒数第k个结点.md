# 题目描述
输入一个链表，输出该链表中倒数第k个结点。
## solution
考察鲁棒性，思考全面。
```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode *fir=pListHead,*sec=pListHead;
        if(k==0)
            return NULL;
        if(pListHead==NULL)
            return NULL;
        while(k>0)
        {
            if(fir==NULL)
                return NULL;
            k--;
            fir=fir->next;
        }
        while(fir!=NULL)
        {
            fir=fir->next;
            sec=sec->next;
        }
        return sec;
    }
};
```
