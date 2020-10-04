// Rearrange a linked list in such a way that all odd position nodes are together and all even positions node are together

// Time Complexity: O(N)
// Space Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
	int val;
	ListNode* next;

	ListNode(int x)
	{
		val = x;
		next = NULL;
	}
};
ListNode* newNode(ListNode* head, int x)
{
	ListNode* temp = new ListNode(x);
	if(!head)
		return temp;
	ListNode* ptr = head;
	while(ptr && ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
	return head;
}
ListNode* oddEvenList(ListNode* head) 
{
    if(!head || !head->next)
        return head;
    ListNode *next, *even = head->next, *prevPtr = NULL;
    ListNode* ptr = head;
    int counter = 1;
    while(ptr)
    {
        if(counter%2)
            prevPtr = ptr;
        ListNode* next = ptr->next;
        if(!next)
            break;
            ptr->next = next->next;
        ptr = next;
        counter++;
    }
    prevPtr->next = even;
    return head;
}
void traverse(ListNode* head)
{
	while(head)
	{
		cout << head->val <<  ' ';
		head = head->next;
	}
}
int main()
{
	int n;
	ListNode* head = NULL;
	while(cin >> n)
	{
		if(n<=0)
			break;
		head = newNode(head, n);
	}
	head = oddEvenList(head);
	traverse(head);
	return 0;
}