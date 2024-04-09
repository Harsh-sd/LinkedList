
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// we can alse use pointer  function in this we have to return prevptr , otherwise concept is same
// node *reverse(node *&head)
//{
//     node *prevptr = NULL;
//     node *currptr = head;
//     node *nextptr;
//    while (currptr != NULL)
//    {
//        nextptr = currptr->next;
//        currptr->next = prevptr;
//
//       prevptr = currptr;
//       currptr = nextptr;
//   }
//   return prevptr;
//}
// using three iterators we can reverse the linked list
void reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
}
int main()
{
    node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    insertattail(head, 6);
    display(head);
    reverse(head);
    display(head);
    // node *newhead = reverse(head);
    // display(newhead);

    return 0;
}