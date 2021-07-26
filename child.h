#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define info(P) P -> info
#define nextC(P) P -> nextC
#define prevC(P) P -> prevC
#define firstC(P) P.firstC
#define lastC(P) P.lastC

using namespace std;

/** DOUBLE **/
/** INSERT FIRST **/
/** DELETE SEARCH **/

typedef struct elmKeyword *addressC;

struct elmKeyword
{
    string info;
    addressC nextC;
    addressC prevC;
};

struct listKeyword
{
    addressC firstC;
    addressC lastC;
};

void createListChild (listKeyword &K);
void createElmChild (addressC &C, string x);
addressC searchKeyword (listKeyword K, string x);
bool isEmpty (listKeyword K);
void insertLast (listKeyword &K, addressC p);
void deleteFirstK (listKeyword &K, addressC &p);
void deleteAfterK (listKeyword &K, addressC prec, addressC &p);

#endif // CHILD_H_INCLUDED
