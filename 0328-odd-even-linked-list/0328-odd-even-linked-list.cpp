/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
    ListNode* odd=head;
    ListNode* even=head->next;
    ListNode* evenHead=even;
    while(odd->next!=NULL && even->next!=NULL)   //condition becoz even is at last or ahead of odd.
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;      //becoz you already attach to next
        even=even->next;
    }
    odd->next=evenHead;
    return head;
    }
};