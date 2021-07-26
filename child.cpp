#include "child.h"

void createListChild (listKeyword &K) {
    firstC(K) = NULL;
    lastC(K) = NULL;
}

void createElmChild (addressC &C, string x) {
    C = new elmKeyword;
    info(C) = x;
    nextC(C) = NULL;
    prevC(C) = NULL;
}

addressC searchKeyword (listKeyword K, string x) {
    addressC p = firstC(K);
    while (p != NULL && info(p) != x) {
        p = nextC(p);
    }
    return p;
}

bool isEmpty (listKeyword K) {
    return firstC(K) == NULL && lastC(K) == NULL;
}


void insertLast (listKeyword &K, addressC p) {
    if (isEmpty(K)) {
        firstC(K) = p;
        lastC(K) = p;
    } else {
        prevC(p) = lastC(K);
        nextC(lastC(K)) = p;
        lastC(K) = p;
    }
}


void deleteFirstK (listKeyword &K, addressC &p) {
    if (isEmpty(K)) {
        p = NULL;
    } else if (firstC(K) == lastC(K)) {
        p = firstC(K);
        firstC(K) = NULL;
        lastC(K) = NULL;
    } else {
        p = firstC(K);
        firstC(K) = nextC(p);
        nextC(p) = NULL;
        prevC(firstC(K)) = NULL;
    }
}

void deleteAfterK (listKeyword &K, addressC prec, addressC &p) {
    if (isEmpty(K) || nextC(prec) == NULL) {
        p = NULL;
    } else if (nextC(prec) == lastC(K)) {
        p = lastC(K);
        nextC(prec) = NULL;
        prevC(p) = NULL;
        lastC(K) = prec;
    } else {
        p = nextC(prec);
        nextC(prec) = nextC(p);
        prevC(nextC(p)) = prec;
        nextC(p) = NULL;
        prevC(p) = NULL;
    }
}
