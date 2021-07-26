#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include "relasi.h"

#define info(P) P -> info
#define FirstP(P) P.FirstP
#define LastP(P) P.LastP
#define firstR(P) P -> firstR
#define nextP(P) P -> nextP

using namespace std;

/** SINGLE CIRCULAR **/
/** INSERT TERURUT (TAHUN) **/
/** DELETE SEARCH **/

struct infotype
{
    string judul;
    string penulis;
    string publisher;
    int tahun;
    string abstrak;
    int jumKey;
};

typedef struct elmArtikel *addressP;

typedef struct elmRelasi *addressR;

struct elmArtikel
{
    infotype info;
    addressR firstR;
    addressP nextP;
};

struct listArtikel
{
    addressP FirstP;
    addressP LastP;
};

void createListParent (listArtikel &A);
void createElmParent (addressP &P);
bool isEmpty (listArtikel A);
addressP searchArtikel (listArtikel A, string judul);
void insertAfter (listArtikel &A,addressP Prec, addressP &P);
void insertTerurut(listArtikel &A, addressP &P);
void deleteFirstA (listArtikel &A, addressP &P);
void deleteAfterA (listArtikel &A, addressP &Prec, addressP &P);

#endif // PARENT_H_INCLUDED
