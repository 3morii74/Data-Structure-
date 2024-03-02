#include <iostream>
using namespace std;
class node {
public:
    int info;
    node* next;
};
class List
{
public:
    node* head;
    node* tail;

    List()
    {
        head = NULL;
    }
    void Attach(node* pnn) {
        if (head == NULL)
        {
            head = pnn;
            tail = pnn;
        }
        else
        {
            tail->next = pnn;
            tail = pnn;
        }
    }
    ~List() {
        node* pTrave = head;
        while (head != NULL) {
            head = pTrave->next;
            pTrave->next = NULL;
            delete pTrave;
            pTrave = head;
        }


    }

};

void ReverseList(List& mainList)
{
    node* current ,* last,*after;
    current=mainList.head;
    last=NULL;
    after=NULL;
    mainList.tail=mainList.head;
    while(current!=NULL)
    {
        after=current->next;
        current->next=last;
        last=current;
        current=after;
    }
    mainList.head=last;
    node* trave=mainList.head;
    while(trave!=NULL)
    {
        cout<<trave->info<<"-";
        trave=trave->next;
    }

}


void ReverseList2(List& mainList,List& l1)
{
    node* current=mainList.head,*current2,*after;
    current2 = new node;
    current2->info=current->info;
    l1.head=current2;
    current2->next = NULL;
    after=current2;
    l1.tail=current;
    current=current->next;
    while (current!=NULL)
    {
        current2 = new node;
        current2->info=current->info;
        l1.head=current2;
        current2->next=after;
        after=current2;
        current=current->next;
    }
    node* trave=l1.head;
    while(trave!=NULL)
    {
        cout<<trave->info<<"-";
        trave=trave->next;
    }
}
int main() {
    List mainList,l1;
    node *pnn;
    int n;
    cout << "enter number of nodes";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        pnn = new node[i];
        cout << "enter value of node";
        cin >> pnn->info;
        pnn->next = NULL;
        mainList.Attach(pnn);
    }
    ReverseList2(mainList,l1);
cout<<endl;
   ReverseList(mainList);

    return 0;
}
