#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, and left and right pointers */
struct node 
{ 
    int data; 
    node* left; 
    node* right; 
}; 
node *first = NULL;
node* last = NULL; 
void inorder(node* root)
{
    if(!root)
        return;
    inorder(root->left);
    
    if(last)
    {
        last->right = root;
        root->left = last;
    }
    else
        first = root;
    last = root;
    inorder(root->right);
}
node* treeToDoublyList(node* root) 
{
    if(!root)
        return root;
    inorder(root); 
    // first->left = last;
    // last->right = first;
    return first;
}

node* newNode(int data) 
{ 
    node* new_node = new node; 
    new_node->data = data; 
    new_node->left = new_node->right = NULL; 
    return (new_node); 
} 
  
/* Function to print nodes in a given doubly linked list */
void printList(node *node) 
{ 
    while (node!=NULL) 
    { 
        cout << node->data << " "; 
        node = node->right; 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    // Let us create the tree shown in above diagram 
    node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    // Convert to DLL 
    treeToDoublyList(root); 
  
    // Print the converted list 
    printList(first); 
  
    return 0; 
} 