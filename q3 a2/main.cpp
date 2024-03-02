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
int main() {
    List List;
    node *pnn,*ptrave,*ctsh;
    int n, pos = 0, val;
    cout << "enter number of nodes";
    cin >> n;
    cout << endl;
    int ct = 0;
    for (int i = 0; i < n; i++) {
        pnn = new node[i];
        cout << "enter value of node";
        cin >> pnn->info;
        pnn->next = NULL;
        List.Attach(pnn);
    }
    cin >> val;

    ptrave=List.head;
    ctsh=List.head;
    while(ct<val){
        ctsh=ctsh->next;
        ct++;
    }
    int ct2=0;
    while(ct2<3) {
        int z = ptrave->info;
        ptrave->info = ctsh->info;
        ctsh->info = z;
       ptrave=ptrave->next;
       ctsh=ctsh->next;
ct2++;
    }

    ptrave=List.head;
    while(ptrave!=NULL)
    {
        cout<<ptrave->info<<endl;
        ptrave=ptrave->next;
    }

}
