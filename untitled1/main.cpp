#include <iostream>
using namespace std;
class Cnode {
public:
    char x[8][8];
    int r;
    Cnode* pnext;
};
class CStack {
public:
    Cnode* phead;
    CStack() {
        phead = NULL;
    }
    ~CStack() {
        Cnode* ptrap;
        ptrap = phead;
        while (phead != NULL) {
            phead = ptrap->pnext;
            ptrap->pnext = NULL;
            delete ptrap;
            ptrap = phead;
        }
    }

    void push(Cnode* pnn)
    {
        pnn->pnext = phead;
        phead = pnn;
    }

    Cnode* pop()
    {
        if (phead == NULL)
        {
            return NULL;
        }
        Cnode* pTrav = phead;
        phead = phead->pnext;
        pTrav->pnext = NULL;
        return pTrav;
    }
};
void copy(Cnode* pnn, Cnode* pCurr) {
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            pnn->x[r][c] = pCurr->x[r][c];
        }
    }
    pnn->r = pCurr->r;
    //cout<<"6";
}
Cnode* initialize()
{
    Cnode* pnn = new Cnode;
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            pnn->x[r][c] = ' ';
        }
    }
    pnn->r = 0;
    pnn->pnext = NULL;
    return pnn;
}

void Expand(Cnode* pCurr, CStack& s, int& nn)
{
    Cnode* pnn;

    for (int i = 0; i < 8; i++)
    {
        //   cout<<"5";
        pnn = new Cnode;
        copy(pnn, pCurr);
        pnn->x[pnn->r][i] = 'Q';

        //column
        int ct = 0;
        int f = 0;
        for (int c = 0; c < 8; c++)
        {
            if (pnn->x[pnn->r][c] == 'Q') {
                ct++;
            }
            if (ct == 2)
            {
                f = 1;
            }
        }
        ct = 0;
        //row
        if (f == 0) {
            for (int r = 0; r < 8; r++)
            {
                if (pnn->x[r][i] == 'Q') {
                    ct++;
                }
                if (ct == 2)
                {
                    f = 1;
                }
            }
        }
        ct = 0;
        // left di
        if (f == 0) {
            int mr, mc;
            int temp = (pnn->r) - i;
            if (temp >= 0) {
                mc = 0, mr = temp;
            }
            if (temp < 0) {
                mr = 0, mc = -1 * temp;
            }
            int r = mr, c = mc, ct = 0;
            for (; r < 8 && c < 8; r++, c++)
            {
                if (pnn->x[r][c] == 'Q') {
                    ct++;
                }
                if (ct == 2)
                {
                    f = 1;
                    break;
                }
            }
        }
        ct = 0;
        // right di
        if (f == 0) {
            for (int r = pnn->r - 1, c = i + 1; r >= 0 && c < 8; r--, c++) {
                if (pnn->x[r][c] == 'Q') {
                    f = 1;
                    break;
                }
            }
            // // right di down
            for (int r = pnn->r + 1, c = i - 1; r < 8 && c >= 0; r++, c--) {
                if (pnn->x[r][c] == 'Q') {
                    f = 1;
                    break;
                }
            }
        }
        cout << endl;

        if (f == 0)
        {
            if (pnn->r < 7) {
                pnn->r = (pnn->r) + 1;
                s.push(pnn);
            }
            else {
                Cnode* ptrave = s.phead;
                while (ptrave->pnext != NULL)
                {
                    ptrave = ptrave->pnext;
                }
                ptrave->pnext = pnn;
                pnn->pnext = NULL;
            }
        }
    }
}
void backTrack(CStack& S)
{
    int nn = 0;

    // cout<<"1";
    Cnode* pCurr;
    pCurr = initialize();
    //cout<<"2";
    S.push(pCurr);
    //cout<<"3";
    while (S.phead != NULL)
    {
        //  cout<<"4";
        int flag = 0;
        pCurr = S.pop();
        Expand(pCurr, S, nn);

        Cnode* pTrav = S.phead;
        while (pTrav != NULL)
        {
            if (pTrav->r < 6)
            {
                flag = 1;
                break;
            }
            pTrav = pTrav->pnext;
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main() {
    CStack S;
    backTrack(S);
    int nn = 1;
    Cnode* pTrav = S.phead;
    while (pTrav != NULL)
    {
        cout << nn << endl;
        nn++;
        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                cout << pTrav->x[r][c] << " | ";
            }
            cout << endl;
            cout << "-----------------------------------" << endl;
        }
        cout << endl;
        cout << endl;

        pTrav = pTrav->pnext;
    }
    return 0;
}