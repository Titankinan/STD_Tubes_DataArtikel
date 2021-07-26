#include "parent.h"

void createListParent(listArtikel &A) {
    FirstP(A) = NULL;
    LastP(A) = NULL;
}

void createElmParent (addressP &P) {
    P = new elmArtikel;
    info(P).jumKey = 0;
    firstR(P) = NULL;
    nextP(P) = NULL;
}

bool isEmpty (listArtikel A) {
    return FirstP(A) == NULL && LastP(A) == NULL;
}

addressP searchArtikel (listArtikel A, string judul)
{
    addressP P = FirstP(A);
    if (FirstP(A) != NULL)
    {
        while ((nextP(P) != FirstP(A)) && (info(P).judul != judul))
        {
            P = nextP(P);
        }
        if (info(P).judul != judul)
        {
            P = NULL;
        }
    }
    else
    {
        P  = NULL;
    }
    return P;
}

void insertAfter (listArtikel &A,addressP Prec, addressP &P)
{
    if (Prec != NULL)
    {
        if (Prec == LastP(A))
        {
            nextP(Prec) = P;
            nextP(P) = FirstP(A);
            LastP(A) = P;
        }
        else
        {
            nextP(P) = nextP(Prec);
            nextP(Prec) = P;
        }
    }
}

void insertTerurut(listArtikel &A, addressP &P)
{
    if (FirstP(A) == NULL)
    {
        FirstP(A) = P;
        nextP(P) = P;
        LastP(A) = P;
    }
    else
    {
        addressP Q = FirstP(A);
        while ((Q != LastP(A)) && (info(P).tahun > info(Q).tahun))
        {
            Q = nextP(Q);
        }
        if (info(P).tahun < info(FirstP(A)).tahun)
        {
            nextP(P) = FirstP(A);
            FirstP(A) = P;
            nextP(LastP(A)) = P;
        }
        else if (info(P).tahun < info(Q).tahun)
        {
            addressP R = FirstP(A);
            while (nextP(R) != Q)
            {
                R = nextP(R);
            }
            insertAfter(A, R, P);
        }
        else
        {
            insertAfter(A, Q, P);
        }
    }
}
void deleteFirstA (listArtikel &A, addressP &P)
{
    addressP Q;
    if (!isEmpty(A))
    {
        if (FirstP(A)  == NULL)
        {
            P = NULL;
        }
        else if (FirstP(A) == nextP(FirstP(A)))
        {
            P = FirstP(A);
            nextP(P) = NULL;
            FirstP(A) = NULL;
        }
        else
        {
            Q = LastP(A);
            P = FirstP(A);
            FirstP(A) = nextP(FirstP(A));
            nextP(Q) = FirstP(A);
            nextP(P) = NULL;
        }
    }
    else
    {
        P = NULL;
    }

}
void deleteAfterA (listArtikel &A, addressP &Prec, addressP &P)
{
    if (!isEmpty(A))
    {
        if (FirstP(A) == LastP(A))
        {
            P = FirstP(A);
            FirstP(A) = NULL;
            LastP(A) = NULL;
        }
        else if (nextP(Prec) == LastP(A))
        {
            P = nextP(Prec);
            LastP(A) = Prec;
            nextP(Prec) = FirstP(A);
            nextP(P) = NULL;
        }
        else if (nextP(Prec) == FirstP(A))
        {
            nextP(Prec) = nextP(P);
            FirstP(A) = nextP(P);
            nextP(LastP(A)) == FirstP(A);
            nextP(P) = NULL;
        }
        else
        {
            P = nextP(Prec);
            nextP(Prec) = nextP(P);
            nextP(P) = NULL;
        }
    }
    else
    {
        P = NULL;
    }
}
