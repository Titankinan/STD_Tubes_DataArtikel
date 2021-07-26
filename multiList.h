#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include "parent.h"
#include "child.h"
#include "relasi.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void mainMenu (listArtikel &A, listKeyword &K);
void tambahArtikel (listArtikel &A, listKeyword &K);
void relasiKeyword (listArtikel &A, listKeyword &K, addressP &artikel);
void tambahKeyword (listKeyword &K, listArtikel &A);
void editArtikel (listArtikel &A, listKeyword &K);
void hapusArtikel (listArtikel &A, listKeyword &K);
void hapusKeyword (listArtikel &A, listKeyword &K);
void showAllArtikel (listArtikel A, listKeyword K);     /** MENAMPILKAN SELURUH ARTIKEL BESERTA DATA KEYWORD **/
void showArtikelK (listArtikel A, listKeyword K);       /** MENAMPILKAN DATA ARTIKEL YANG MEMILIKI KEYWORD TERTENTU **/
void showKeywordA (listArtikel A, listKeyword K);       /** MENAMPILKAN DATA KEYWORD YANG DIMILIKA ARTIKEL TERTENTU **/
void showBidangKajian (listArtikel A, listKeyword K);   /** MENAMPILKAN DATA ARTIKEL YANG MEMILIKI BIDANG KAJIAN TERBANYAK DAN TERSEDIKIT **/
void showAllKeyword (listKeyword &K);
addressR searchRelasi (addressP artikel, addressC keyword);
//void deleteArtikel (listArtikel &A);                    /** MENGHAPUS DATA ARTIKEL DENGAN JUDUL TERTENTU **/
//void deleteKeyword (listKeyword &K);                    /** MENGHAPUS SUATU KEYWORD **/

#endif // MULTILIST_H_INCLUDED

