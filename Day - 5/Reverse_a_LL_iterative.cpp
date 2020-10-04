#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode* insert(ListNode* head, int x)
{
    ListNode* temp = new ListNode();
    if(head)
    {
        ListNode* it = head;
        while(it->next)
            it = it->next;    

        it->next = temp;
        temp->val = x;
        temp->next = NULL;
        return head;
    }
    else
    {
        temp->val = x;
        temp->next = NULL;
        return temp;
    }
}
ListNode* reverseList(ListNode* head) 
{
    if(!head || !head->next)
        return head;
    ListNode *curr = head;
    ListNode *prev = NULL, *nxt = NULL;
    while(curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;
}
int main()
{
    int n, x;
    cin >> n;
    ListNode* head = NULL;
    while(n--)
    {
        cin >> x;
        head = insert(head, x);
    }
    head = reverseList(head);
    ListNode* it = head;
    while(it)
    {
        cout << it->val << ' ';
        it = it->next;
    }
    return 0;
}