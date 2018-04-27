/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum=0;
        int toNext=0;
        ListNode* pHead=new ListNode(0);
        ListNode* cur=pHead;
        while(l1!=NULL||l2!=NULL)
        {
            
            int temp1=0;
            int temp2=0;
            if(l1!=NULL)
            {
                temp1=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                temp2=l2->val;
                l2=l2->next;
            }
            sum=temp1+temp2+toNext;           
            toNext=sum/10;
            sum=sum%10;
            cur->next=new ListNode(sum);
            cur=cur->next;
        }
        if(toNext!=0)
        {
            cur->next=new ListNode(toNext);
            
        }
        return pHead->next;
        
    }
};