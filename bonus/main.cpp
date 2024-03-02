#include <iostream>
using namespace std;



class CNode {
public:
    int X[2][6];
    char History[200];
    char pos [7];
    CNode* pNext;
};


class CList
{
public:
    CNode* pHead;
    CNode* pTail;

    CList()
    {
        pHead = NULL;
        pTail = NULL;
    }

    void Attach(CNode* pnn)
    {
        if (pHead == NULL)
        {
            pHead = pnn;
            pTail = pnn;
        }
        else
        {
            pTail->pNext = pnn;
            pTail = pnn;
        }
    }

    ~CList()
    {
        CNode* pTrav = pHead;
        while (pHead != NULL)
        {
            pHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = pHead;
        }
    }
};

class CStack {

public:
    CNode* pHead;


    CStack() {

        pHead = NULL;

    }

    ~CStack()
    {
        CNode* pTrav;
        pTrav = pHead;
        while (pHead != NULL)
        {
            pHead = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = pHead;
        }

    }

    void Push(CNode* pnn)
    {
        pnn->pNext = pHead;
        pHead = pnn;
    }

    CNode* Pop()
    {
        if (pHead == NULL)
        {
            return NULL;
        }

        CNode* pTrav = pHead;
        pHead = pHead->pNext;
        pTrav->pNext = NULL;
        return pTrav;
    }

};

CNode* Initialize()
{
    CNode* pnn = new CNode;

    for (int c = 0; c < 6; c++)
    {
        pnn->X[0][c] = 1;
        pnn->X[1][c] = 0;

    }
    for (int z = 0; z < 200; z++)
    {
        pnn->History[z] = '\0';
    }
    pnn->pos[0] = 'A';
    pnn->pos[1] = 'B';
    pnn->pos[2] = 'C';
    pnn->pos[3] = 'D';
    pnn->pos[4] = 'E';
    pnn->pos[5] = 'F';
    pnn->pos[6] = '\0';

    pnn->pNext = NULL;

    return pnn;
}

int isVisited(CNode* pnn, CList& Lv)
{
    CNode* pTrav = Lv.pHead;
    int ct = 0, R = 0;

    while (pTrav != NULL)
    {
        ct = 0;

        for (int i = 0; i < 6; i++)
        {
            if ((pTrav->X[0][i] == pnn->X[0][i]) && (pTrav->X[1][i] == pnn->X[1][i]))
            {
                ct++;

                if (ct == 6)
                {
                    R = 1;
                    break;
                }
            }
        }
        pTrav = pTrav->pNext;

        if (R == 1)
        {
            break;
        }
    }

    return R;

}

int Check(CNode* pnn, CList& Lv) {

    int b = 0;
     int max=0,max2=0,c;

    for(int r=0;r<2;r++)
    {
        max=0,max2=0;

            if (pnn->X[r][0]==1){
                max+=1000;
            }
            if (pnn->X[r][1]==1){
                max+=700;
            }
            if (pnn->X[r][2]==1){
                max+=300;
            }

            if (pnn->X[r][3]==1){
                max2+=1000;
            }
            if (pnn->X[r][4]==1){
                max2+=700;
            }
            if (pnn->X[r][5]==1){
                max2+=300;
            }
        if(max2>max)
        {
            if (max==0){
                b=0;
            }
            else{
                b=1;
                break;
            }

        }
        else{
            b=0;
        }
    }

    return b;
}


void Expand(CNode* pCurr, CStack& S, CList& Lv) {

    CNode *pnn;
    int R, z = 0, bad = 0;
    for (int ii = 0; ii < 3; ii++) {


    for (int i = 0; i < 6; i++) {

        pnn = new CNode;

        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 6; c++) {
                pnn->X[r][c] = pCurr->X[r][c];
            }
        }

        for (z = 0; z < 200; z++) {
            pnn->History[z] = pCurr->History[z];
        }
        for (z = 0; z < 8; z++) {
            pnn->pos[z] = pCurr->pos[z];
        }

        pnn->pNext = pCurr->pNext;


        if (pnn->X[0][ii] == 1) {
            pnn->X[0][ii] = 0;
            pnn->X[1][ii] = 1;

            for (z = 0; pnn->History[z] != '\0'; z++) {
            }
            pnn->History[z] = pnn->pos[ii];
            if ((i-ii)!=0){
                int tempI;
                tempI=i-ii;
                if (tempI<0)
                {
                    tempI=ii-i;
                }
                pnn->X[0][i] = 0;
                pnn->X[1][i] = 1;

                for (z = 0; pnn->History[z] != '\0'; z++) {
                }
                pnn->History[z] =  pnn->pos[i];
            }


        } else {


            pnn->X[0][ii] = 1;
            pnn->X[1][ii] = 0;

            for (z = 0; pnn->History[z] != '\0'; z++) {
            }
            pnn->History[z] =  pnn->pos[ii];
            if ((i-ii)!=0){
                int tempI;
                tempI=i-ii;
                if (tempI<0)
                {
                    tempI=ii-i;
                }
                pnn->X[0][i] = 1;
                pnn->X[1][i] = 0;

                for (z = 0; pnn->History[z] != '\0'; z++) {
                }
                pnn->History[z] =  pnn->pos[i];
            }


        }


        R = isVisited(pnn, Lv);

        if (R == 0) {

            CNode *pCopy;
            pCopy = new CNode;

            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 6; c++) {
                    pCopy->X[r][c] = pnn->X[r][c];
                }
            }

            for (z = 0; z < 200; z++) {
                pCopy->History[z] = pnn->History[z];
            }
            for (z = 0; z < 8; z++) {
                pCopy->pos[z] = pnn->pos[z];
            }
            pCopy->pNext = NULL;

            Lv.Attach(pCopy);

            bad = Check(pnn, Lv);

            if (bad == 0) {
                S.Push(pnn);
            } else {
                delete pnn;
            }
        } else {
            delete pnn;
        }
    }
}

}

void BackTrack(CStack& S, CList& Lv) {
    CNode* pCurr;
    int check = 0;

    pCurr = Initialize();
    S.Push(pCurr);

    while (S.pHead != NULL) {
        check = 0;

        for (int c = 0; c < 6; c++) {
            if (pCurr->X[0][c] == 0 && pCurr->X[1][c] == 1) {
                check++;
            }
        }


        if (check == 6) {
            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 6; c++) {
                    cout << pCurr->X[r][c] << " | ";
                }
                cout << endl << "---------------" << endl;
            }


            for (int i = 0; pCurr->History[i] != '\0'; i++) {
                cout << pCurr->History[i] << " , ";
            }
            cout << endl<<endl;

            break;
        }
        else
        {
            pCurr = S.Pop();
            Expand(pCurr, S, Lv);
        }




        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 6; c++) {
                cout << pCurr->X[r][c] << " | ";
            }
            cout << endl << "---------------" << endl;
        }


        for (int i = 0; pCurr->History[i]!='\0'; i++)
        {
            cout << pCurr->History[i] << " , ";
        }
        cout << endl<<endl;
    }
}


int main()
{
    CStack S;
    CList Lv;

    BackTrack(S, Lv);

}