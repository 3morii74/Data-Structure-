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
void splitList_1(List & mainList, int splitValue,List& l1,List &l2){
    node* current,*attach;
    current =mainList.head;
    while (current!=NULL)
    {
        if(current->info!=splitValue){


                attach = new node;
                attach->info = current->info;
                attach->next = NULL;
              l1.Attach(attach);
        }
        else{
          break;
        }
       current=current->next;
    }
    while (current!=NULL)
    {


            attach = new node;
            attach->info = current->info;
            attach->next = NULL;
        l2.Attach(attach);


        current=current->next;
}
  }

void splitList_2(List& mainList, int splitValue,List& l1,List& l2){
    node* current,*attach;
    current =mainList.head;
    l1.head=mainList.head;
    while(current->next->info !=splitValue ){
        current=current->next;

    }

    l2.head=current->next;
    current->next=NULL;
}


int main() {
    List mainList, l1, l2,l11,l22;
    node *pnn,*trave;
    int n, pos = 0, splitvalue;
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
    cout<<"enter split value"<<endl;
    cin >> splitvalue;
    splitList_1(mainList,splitvalue,l1,l2);
    trave=l1.head;
    while(trave!=l1.tail->next)
    {
        cout<<trave->info<<endl;
        trave=trave->next;

    }
    cout<<"===================="<<endl;
    trave=l2.head;
    while(trave!=l2.tail->next)
    {
        cout<<trave->info<<endl;
        trave=trave->next;

    }
    splitList_2(mainList,splitvalue, l11, l22);
    cout<<"===================="<<endl;
    trave=l11.head;
    while(trave!=NULL)
    {
        cout<<trave->info<<endl;
        trave=trave->next;

    }
    cout<<"===================="<<endl;
    trave=l22.head;
    while(trave!=NULL)
    {
        cout<<trave->info<<endl;
        trave=trave->next;

    }
    return 0;
}