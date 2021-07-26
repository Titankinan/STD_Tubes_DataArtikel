#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "parent.h"
#include "child.h"

#define nextR(P) P -> nextR
#define nextC(P) P -> nextC

using namespace std;

/** SINGLE **/
/** INSERT LAST **/

typedef struct elmRelasi *addressR;

typedef struct elmArtikel *addressP;

struct elmRelasi
{
    addressR nextR;
    addressC nextC;
};

addressR createElmRelasi ();
void deleteFirstR (addressP &P);
void deleteThisR (addressP &p, addressR &q);  /** MENGHAPUS SUATU RELASI q YANG ADA DI PARENT p **/

#endif // RELASI_H_INCLUDED
