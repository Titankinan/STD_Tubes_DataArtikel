#include "multiList.h"

void mainMenu (listArtikel &A, listKeyword &K) {
    int pil = 99;
    system("cls");
    cout << "=======================================" << endl;
    cout << "              MENU UTAMA               " << endl;
    cout << "=======================================\n" << endl;
    cout << "1. Tambah Data Artikel\n";
    cout << "2. Tambah Data Keyword\n";
    cout << "3. Edit Data Artikel\n";
    cout << "4. Hapus Data Artikel\n";
    cout << "5. Hapus Data Keyword\n";
    cout << "6. Lihat Data\n";
/*
    cout << "5. Lihat Semua Data Artikel dan Keyword\n";
    cout << "6. Lihat Data Artikel dengan Keyword yang Sama\n";
    cout << "7. Lihat Keyword dari Suatu Artikel\n";
    cout << "8. Lihat Artikel dengan Bidang Kajian Terbanyak dan Tersedikit\n";
*/
    cout << "9. Keluar\n\n";
    cout << "Pilihan : "; cin >> pil;

    switch (pil) {
        case 1:
            system("cls");
            tambahArtikel(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 2:
            system("cls");
            tambahKeyword(K,A);
            mainMenu(A,K);
            break;
        case 3:
            system("cls");
            editArtikel(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 4:
            system("cls");
            hapusArtikel(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 5:
            system("cls");
            hapusKeyword(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 6:
            system("cls");
            cout << "=======================================" << endl;
            cout << "              LIHAT DATA               " << endl;
            cout << "=======================================" << endl;
            cout << "Menu Utama >> Lihat Data\n\n";
            cout << "1. Lihat Semua Data Artikel dan Keyword\n";
            cout << "2. Lihat Data Artikel dengan Keyword yang Sama\n";
            cout << "3. Lihat Keyword dari Suatu Artikel\n";
            cout << "4. Lihat Artikel dengan Bidang Kajian Terbanyak dan Tersedikit\n";
            cout << "5. Kembali\n\n";
            cout << "Pilihan : "; cin >> pil;

            switch (pil) {
                case 1:
                    system("cls");
                    cout << "========================================" << endl;
                    cout << "             DAFTAR ARTIKEL             " << endl;
                    cout << "========================================" << endl;
                    cout << "Menu Utama >> Lihat Data >> Daftar Artikel\n\n";
                    showAllArtikel(A,K);
                    cin.get();
                    mainMenu(A,K);
                    break;
                case 2:
                    system("cls");
                    showArtikelK(A,K);
                    cin.get();
                    mainMenu(A,K);
                    break;
                case 3:
                    system("cls");
                    showKeywordA(A,K);
                    cin.get();
                    mainMenu(A,K);
                    break;
                case 4:
                    system("cls");
                    showBidangKajian(A,K);
                    cin.get();
                    mainMenu(A,K);
                    break;
                case 5:
                    mainMenu(A,K);
                    break;
                default:
                    mainMenu(A,K);
            }
/*
        case 5:
            system("cls");
            showAllArtikel(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 6:
            system("cls");
            showArtikelK(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 7:
            system("cls");
            showKeywordA(A,K);
            cin.get();
            mainMenu(A,K);
            break;
        case 8:
            system("cls");
            showBidangKajian(A,K);
            cin.get();
            mainMenu(A,K);
            break;
*/
        case 9:
            break;
        default:
            mainMenu(A,K);
    }
}

void tambahArtikel (listArtikel &A, listKeyword &K)
{
    cout << "=======================================" << endl;
    cout << "            TAMBAH ARTIKEL             " << endl;
    cout << "=======================================" << endl;
    cout << "Menu Utama >> Tambah Artikel\n\n";
    addressP artikel;
    createElmParent(artikel);
    cout << "Judul Artikel : "; getline(cin,info(artikel).judul); getline(cin,info(artikel).judul);
    cout << "Penulis       : "; getline(cin,info(artikel).penulis);
    cout << "Publisher     : "; getline(cin,info(artikel).publisher);
    cout << "Tahun         : "; cin >> info(artikel).tahun;
    cout << "Abstrak       : "; getline(cin,info(artikel).abstrak); getline(cin,info(artikel).abstrak);
    relasiKeyword(A,K,artikel);
    cout << "========================================" << endl;
    cout << "       ARTIKEL BERHASIL TERDAFTAR       " << endl;
    insertTerurut(A, artikel);
}


void relasiKeyword (listArtikel &A, listKeyword &K, addressP &artikel)
{
    cout << "=======================================" << endl;
    cout << "      MASUKAN 'done' JIKA SELESAI      " << endl;
    int i = 1;
    string key;
    addressR relasi;
    addressC keyword;
    cout << "Keyword " << i << " : "; getline(cin,key);
    while (key != "done")
    {
        relasi = createElmRelasi();
        keyword = searchKeyword(K, key);
        if (keyword == NULL)
        {
            createElmChild(keyword, key);
            insertLast(K, keyword);
        }
        nextR(relasi) = firstR(artikel);
        firstR(artikel) = relasi;
        nextC(relasi) = keyword;
        i++;
        info(artikel).jumKey++;
        cout << "Keyword " << i << " : "; getline(cin,key);
    }
}


void tambahKeyword (listKeyword &K, listArtikel &A) {
    cout << "=======================================" << endl;
    cout << "            TAMBAH KEYWORD             " << endl;
    cout << "=======================================" << endl;
    cout << "Menu Utama >> Tambah Keyword\n\n";
    string x;
    addressP cari;
    showAllArtikel(A,K);
    if (FirstP(A) != NULL) {
        cout << "Pilih judul artikel yang akan di tambah keywordnya : "; getline(cin,x);
        cari = searchArtikel(A,x);
    }   if (cari != NULL) {
            relasiKeyword(A,K,cari);
            cout << "\nKeyword berhasil ditambah\n";
        } else {
            cout << "\nJudul yang anda masukan tidak terdaftar" << endl;
            cin.get();
        }
}

void editArtikel (listArtikel &A, listKeyword &K) {
    cout << "=======================================" << endl;
    cout << "             EDIT ARTIKEL              " << endl;
    cout << "=======================================" << endl;
    cout << "Menu Utama >> Edit Artikel\n\n";
    string x;
    addressP cari;
    showAllArtikel(A,K);
    if (FirstP(A) != NULL) {
        cout << "Pilih judul artikel yang akan di edit : "; getline(cin,x);
        cari = searchArtikel(A,x);
        if (cari != NULL) {
            system("cls");
            cout << "Judul \t: " << info(cari).judul << endl;
            cout << "Penulis \t: " << info(cari).penulis << endl;
            cout << "Publisher \t: " << info(cari).publisher << endl;
            cout << "Tahun \t: " << info(cari).tahun << endl;
            cout << "Abstrak \t: " << info(cari).abstrak << endl;
            cout << "Keyword \t: ";
            addressR relasi = firstR(cari);
            if (relasi == NULL)
            {
                cout << "TIDAK ADA KEYWORD" << endl;
            }
            else
            {
                while (nextR(relasi) != NULL)
                {
                    cout << info(nextC(relasi)) << ", ";
                    relasi = nextR(relasi);
                }
                cout << info(nextC(relasi)) << endl;
            }
            cout << "========================================" << endl;
            cout << "                  EDIT                  " << endl;
            cout << " MASUKAN '0' JIKA TIDAK INGIN MENGGANTI " << endl;
            string x;
            int y;
            cout << "Judul Artikel : "; getline(cin,x);
            if (x != "0") {
                info(cari).judul = x;
            }
            cout << "Penulis       : "; getline(cin,x);
            if (x != "0") {
                info(cari).penulis = x;
            }
            cout << "Publisher     : "; getline(cin,x);
            if (x != "0") {
                info(cari).publisher = x;
            }
            cout << "Abstrak       : "; getline(cin,x);
            if (x != "0") {
                info(cari).abstrak = x;
            }
            cout << "Tahun         : "; cin >> y;
            if (y != 0) {
                info(cari).tahun = y;
            }
            cout << "\nData Artikel Berhasil di Edit";
            cin.get();
        } else {
            cout << "\nJudul yang anda masukan tidak terdaftar" << endl;
            cin.get();
        }
    }
}

void hapusArtikel (listArtikel &A, listKeyword &K)
{
    showAllArtikel(A,K);
    cout << "========================================" << endl;
    cout << "    PILIH ARTIKEL YANG INGIN DIHAPUS    " << endl;
    cout << "========================================" << endl;
    cout << "Menu Utama >> Hapus Artikel\n\n";
    string judul;
    cout << "Judul Artikel : "; getline(cin,judul);
    addressP dihapus = searchArtikel(A, judul);
    if (dihapus == NULL)
    {
        cout << "========================================" << endl;
        cout << "   ARTIKEL YANG DICARI TIDAK DITEMUKAN  " << endl;
        cout << "========================================" << endl;
    }
    else
    {
        while (firstR(dihapus) != NULL)
        {
            deleteFirstR(dihapus);
        }
        addressP Prec = FirstP(A);
        while (nextP(Prec) != dihapus)
        {
            Prec = nextP(Prec);
        }
        deleteAfterA(A, Prec, dihapus);
        cout << "========================================" << endl;
        cout << "        ARTIKEL BERHASIL DIHAPUS        " << endl;
        cout << "========================================" << endl;
    }
    cin.get();
}


void hapusKeyword (listArtikel &A, listKeyword &K)
{
    showAllKeyword(K);
    cout << "========================================" << endl;
    cout << "    PILIH KEYWORD YANG INGIN DIHAPUS    " << endl;
    cout << "========================================" << endl;
    cout << "Menu Utama >> Hapus Keyword\n\n";
    string cari;
    cout << "Keyword : "; cin >> cari;
    addressC keyword = searchKeyword(K,cari);
    if (keyword == NULL) {
        cout << "========================================" << endl;
        cout << "   KEYWORD YANG DICARI TIDAK DITEMUKAN  " << endl;
        cout << "========================================" << endl;
        cin.get();
    } else {
        addressP artikel = FirstP(A);
        while (nextP(artikel) != FirstP(A)) {
            addressR hapus = searchRelasi(artikel,keyword);
            if (hapus != NULL) {
                if (hapus == firstR(artikel)) {
                    deleteFirstR(artikel);
                } else {
                    deleteThisR(artikel,hapus);
                }
            }
            artikel = nextP(artikel);
        }

        addressR hapus = searchRelasi(artikel,keyword);
        if (hapus != NULL) {
            if (hapus == firstR(artikel)) {
                deleteFirstR(artikel);
            } else {
                deleteThisR(artikel,hapus);
            }
        }

        if (keyword != firstC(K)) {
            addressC prec = firstC(K);
            while (nextC(prec) != keyword) {
                prec = nextC(prec);
            }
            deleteAfterK(K,prec,keyword);
        } else {
            deleteFirstK(K,keyword);
        }
        cout << "========================================" << endl;
        cout << "        KEYWORD BERHASIL DIHAPUS        " << endl;
        cout << "========================================" << endl;
        cin.get();
    }
}

addressR searchRelasi (addressP artikel, addressC keyword) {
    addressR p = firstR(artikel);
    while (p != NULL && nextC(p) != keyword) {
        p = nextR(p);
    }
    return p;
}

void showAllArtikel (listArtikel A, listKeyword K)  /** MENAMPILKAN SELURUH ARTIKEL BESERTA DATA KEYWORD **/
{
    addressP P = FirstP(A);
    if (P != NULL)
    {
        while (P != LastP(A))
        {
            cout << "Judul \t\t: " << info(P).judul << endl;
            cout << "Penulis \t: " << info(P).penulis << endl;
            cout << "Publisher \t: " << info(P).publisher << endl;
            cout << "Tahun \t\t: " << info(P).tahun << endl;
            cout << "Abstrak \t: " << info(P).abstrak << endl;
            cout << "Keyword \t: ";
            addressR relasi = firstR(P);
            if (relasi == NULL)
            {
                cout << "TIDAK ADA KEYWORD" << endl;
            }
            else
            {
                while (nextR(relasi) != NULL)
                {
                    cout << info(nextC(relasi)) << ", ";
                    relasi = nextR(relasi);
                }
                cout << info(nextC(relasi)) << endl;
            }
            cout << "========================================" << endl;
            P = nextP(P);
        }
        cout << "Judul \t\t: " << info(P).judul << endl;
        cout << "Penulis \t: " << info(P).penulis << endl;
        cout << "Publisher \t: " << info(P).publisher << endl;
        cout << "Tahun \t\t: " << info(P).tahun << endl;
        cout << "Abstrak \t: " << info(P).abstrak << endl;
        cout << "Keyword \t: ";
        addressR relasi = firstR(P);
        if (relasi == NULL)
        {
            cout << "TIDAK ADA KEYWORD" << endl;
        }
        else
        {
            while (nextR(relasi) != NULL)
            {
                cout << info(nextC(relasi)) << ", ";
                relasi = nextR(relasi);
            }
            cout << info(nextC(relasi)) << endl;
        }
        cout << "========================================" << endl;
    }
    else
    {
        cout << "            TIDAK ADA ARTIKEL           " << endl;
        cout << "========================================" << endl;
    }
    cin.get();
}


void showArtikelK (listArtikel A, listKeyword K)   /** MENAMPILKAN DATA ARTIKEL YANG MEMILIKI KEYWORD TERTENTU **/
{
    string dicari;
    cout << "=========================================" << endl;
    cout << "  PENCARIAN ARTIKEL BERDASARKAN KEYWORD  " << endl;
    cout << "=========================================" << endl;
    cout << "Menu Utama >> Lihat Data >> Daftar Artikel Berdasarkan Keyword\n\n";
    cout << "=========================================" << endl;
    cout << "Keyword yang dicari : "; cin >> dicari;
    cout << "=========================================" << endl;
    addressC Key = searchKeyword(K, dicari);
    if (Key != NULL)
    {
        addressP P = FirstP(A);
        addressR Q;
        while (nextP(P) != FirstP(A))
        {
            Q = firstR(P);
            while (Q != NULL)
            {
                if (nextC(Q) == Key)
                {
                    cout << "Judul \t: " << info(P).judul << endl;
                    cout << "Penulis \t: " << info(P).penulis << endl;
                    cout << "Publisher \t: " << info(P).publisher << endl;
                    cout << "Tahun \t: " << info(P).tahun << endl;
                    cout << "Abstrak \t: " << info(P).abstrak << endl;
                    cout << "Keyword \t: ";
                    addressR relasi = firstR(P);
                    while (nextR(relasi) != NULL)
                    {
                        cout << info(nextC(relasi)) << ", ";
                        relasi = nextR(relasi);
                    }
                    cout << info(nextC(relasi)) << endl;
                    cout << "========================================" << endl;
                }
                Q = nextR(Q);
            }
            P = nextP(P);
        }
        Q = firstR(P);
        while (Q != NULL)
        {
            if (nextC(Q) == Key)
            {
                cout << "Judul \t: " << info(P).judul << endl;
                cout << "Penulis \t: " << info(P).penulis << endl;
                cout << "Publisher \t: " << info(P).publisher << endl;
                cout << "Tahun \t: " << info(P).tahun << endl;
                cout << "Abstrak \t: " << info(P).abstrak << endl;cout << "==========================================" << endl;
                cout << "Keyword \t: ";
                addressR relasi = firstR(P);
                while (nextR(relasi) != NULL)
                {
                    cout << info(nextC(relasi)) << ", ";
                    relasi = nextR(relasi);
                }
                cout << info(nextC(relasi)) << endl;
                cout << "========================================" << endl;
            }
            Q = nextR(Q);
        }
    }
    else
    {
        cout << "TIDAK ADA ARTIKEL DENGAN KEYWORD TERSEBUT" << endl;
        cout << "=========================================" << endl;
    }
    cin.get();
}


void showKeywordA (listArtikel A, listKeyword K)   /** MENAMPILKAN DATA KEYWORD YANG DIMILIKI ARTIKEL TERTENTU **/
{
    cout << "==========================================" << endl;
    cout << "      PENCARIAN KEYWORD PADA ARTIKEL      " << endl;
    cout << "==========================================" << endl;
    cout << "Menu Utama >> Lihat Data >> Daftar Keyword Suatu Artikel\n\n";
    cout << "==========================================" << endl;
    string judul;
    cout << "Judul Atikel yang dicari : "; getline(cin,judul); getline(cin,judul);
    cout << "==========================================" << endl;
    addressP artikel = searchArtikel(A,judul);
    if (artikel != NULL)
    {
        cout << "Judul \t: " << info(artikel).judul << endl;
        cout << "Penulis \t: " << info(artikel).penulis << endl;
        cout << "Publisher \t: " << info(artikel).publisher << endl;
        cout << "Tahun \t: " << info(artikel).tahun << endl;
        cout << "Abstrak \t: " << info(artikel).abstrak << endl;
        cout << "Keyword \t: ";
        addressR relasi = firstR(artikel);
        if (relasi != NULL)
        {
            while (nextR(relasi) != NULL)
            {
                cout << info(nextC(relasi)) << ", ";
                relasi = nextR(relasi);
            }
            cout << info(nextC(relasi)) << endl;
        }
        else
        {
            cout << "TIDAK ADA KEYWORD" << endl;
        }
        cout << "==========================================" << endl;
    }
    else
    {
        cout << "         ARTIKEL TIDAK DITEMUKAN          " << endl;
        cout << "==========================================" << endl;
    }
    cin.get();
}


void showBidangKajian (listArtikel A, listKeyword K)   /** MENAMPILKAN DATA ARTIKEL YANG MEMILIKI BIDANG KAJIAN TERBANYAK DAN TERSEDIKIT **/
{
    addressP Max = FirstP(A);
    addressP Min = FirstP(A);
    addressP P = FirstP(A);
    while (nextP(P) != FirstP(A))
    {
        if (info(Max).jumKey < info(P).jumKey)
        {
            Max = P;
        }
        if (info(Min).jumKey > info(P).jumKey)
        {
            Min = P;
        }
        P = nextP(P);
    }
    if (info(Max).jumKey < info(P).jumKey)
    {
        Max = P;
    }
    if (info(Min).jumKey > info(P).jumKey)
    {
        Min = P;
    }
    cout << "=========================================" << endl;
    cout << "              BIDANG KAJIAN              " << endl;
    cout << "=========================================" << endl;
    cout << "Menu Utama >> Lihat Data >> Bidang Kajian\n\n";
    cout << "TERBANYAK" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Judul \t: " << info(Max).judul << endl;
    cout << "Penulis \t: " << info(Max).penulis << endl;
    cout << "Publisher \t: " << info(Max).publisher << endl;
    cout << "Tahun \t: " << info(Max).tahun << endl;
    cout << "Abstrak \t: " << info(Max).abstrak << endl;
    cout << "Keyword \t: ";
    addressR relasi = firstR(Max);
    if (relasi != NULL)
    {
        while (nextR(relasi) != NULL)
        {
            cout << info(nextC(relasi)) << ", ";
            relasi = nextR(relasi);
        }
        cout << info(nextC(relasi)) << endl;
    }
    else
    {
        cout << "TIDAK ADA KEYWORD" << endl;
    }
    cout << "==========================================" << endl;

    cout << "TERSEDIKIT" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Judul \t: " << info(Min).judul << endl;
    cout << "Penulis \t: " << info(Min).penulis << endl;
    cout << "Publisher \t: " << info(Min).publisher << endl;
    cout << "Tahun \t: " << info(Min).tahun << endl;
    cout << "Abstrak \t: " << info(Min).abstrak << endl;
    cout << "Keyword \t: ";
    relasi = firstR(Min);
    if (relasi != NULL)
    {
        while (nextR(relasi) != NULL)
        {
            cout << info(nextC(relasi)) << ", ";
            relasi = nextR(relasi);
        }
        cout << info(nextC(relasi)) << endl;
    }
    else
    {
        cout << "TIDAK ADA KEYWORD" << endl;
    }
    cout << "==========================================" << endl;
    cin.get();
}


void showAllKeyword (listKeyword &K)
{
    addressC P = firstC(K);
    int i = 1;
    cout << "======================================" << endl;
    cout << "             LIST KEYWORD             " << endl;
    cout << "======================================" << endl;
    while (P != NULL)
    {
        cout << i << ". " << info(P) << endl;
        P = nextC(P);
        i++;
    }
    cout << "======================================" << endl;
}


/*void deleteArtikel (listArtikel &A) {
    string dicari;
    addressP p, q;
    cout << "======================================" << endl;
    cout << "         PENGHAPUSAN ARTIKEL          " << endl;
    cout << "======================================" << endl;
    cout << "Judul Atikel yang dihapus : "; cin >> dicari;
    cout << "======================================" << endl;
    p = searchArtikel(A,dicari);
    if (p != NULL) {
        q = FirstP(A);
        while (nextP(q) != p) {
            q = nextP(q);
        }
        deleteAfterA(A,q,p);
        cout << "       ARTIKEL BERHASIL DIHAPUS       " << endl;
        cout << "======================================" << endl;
    } else {
        cout << "       ARTIKEL TIDAK DITEMUKAN        " << endl;
        cout << "======================================" << endl;
    }
}*/


/*void deleteKeyword (listKeyword &K) {
    string dicari;
    addressC p, q;
    cout << "======================================" << endl;
    cout << "         PENGHAPUSAN KEYWORD          " << endl;
    cout << "======================================" << endl;
    cout << "Keyword yang dihapus : "; cin >> dicari;
    cout << "======================================" << endl;
    p = searchKeyword(K,dicari);
    if (p != NULL) {
        q = firstC(K);
        while (nextC(q) != p) {
            q = nextC(q);
        }
        deleteAfterK(K,q,p);
        cout << "       KEYWORD BERHASIL DIHAPUS       " << endl;
        cout << "======================================" << endl;
    } else {
        cout << "       KEYWORD TIDAK DITEMUKAN        " << endl;
        cout << "======================================" << endl;
    }
}*/
