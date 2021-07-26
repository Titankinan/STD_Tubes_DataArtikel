#include "relasi.h"

addressR createElmRelasi ()
{
    addressR P = new elmRelasi;
    nextR(P) = NULL;
    nextC(P) = NULL;
    return P;
}

void deleteFirstR (addressP &P)
{
    addressR R;
    if (firstR(P) != NULL)
    {
        R = firstR(P);
        firstR(P) = nextR(firstR(P));
        nextR(R) = NULL;
    }
    info(P).jumKey--;
    //delete R;
}

void deleteThisR (addressP &p, addressR &q) {  /** MENGHAPUS SUATU RELASI q YANG ADA DI PARENT p **/
    addressR r = firstR(p);
    while (nextR(r) != q) {
        r = nextR(r);
    }
    nextR(r) = nextR(q);
    nextR(q) = NULL;
    info(p).jumKey--;
}
