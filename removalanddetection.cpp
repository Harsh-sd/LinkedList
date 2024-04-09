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
//detcting the presence of cycle
//based on floyd's algorithm
bool detectcycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
//making of cycle
void makecycle(node *&head, int pos)
{
    //this [pointer will traverse to last]
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    //this pointer will take us to position from where cycle will start
    node *createloop = head;
    for (int i = 0; i < pos; i++)
    {
        createloop = createloop->next;
    }
    //then joining the pointers
    tail->next = createloop;
}
//removal of cycle from the singly linked list
void removecycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    //first we have to find the cycle
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast);
    //both will traverse step by step single
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    makecycle(head, 3);
    // display(head);
    if (detectcycle(head))
    {
        cout << "Cycle exists in the linked list." << endl;
    }
    else
    {
        cout << "No cycle exists in the linked list." << endl;
    }
    removecycle(head);
    display(head);
    return 0;
}