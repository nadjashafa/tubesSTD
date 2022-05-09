//
//  parent.cpp
//  TUBES
//
//  Created by Nadja Shafa Adryana on 06/04/20.
//  Copyright © 2020 Nadja Shafa Adryana. All rights reserved.
//

#include "parent.h"
#include "child.h"

void createListPr(ListPr &L) {
    first(L) = NULL;
}


adrPr alokasiPr(infotypePr x) {
    
    adrPr P = new elmPr;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    createListCh(child(P));

    return P;

}

//CIRCULLAR DLL
void insertFirstPr(ListPr &L, adrPr P) {

    if (first(L) == NULL) {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(P)) = P;
        prev(first(L)) = P;
        first(L) = P;
    }

}


//CIRCULLAR DLL
void deleteFirstPr(ListPr &L, adrPr &P) {
    if (next(first(L)) == first(L)){
        P = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        P = first(L);
        adrPr Q = prev(P);
        first(L) = next(P);
        prev(first(L)) = Q;
        next(Q) = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLastPr(ListPr &L, adrPr &P){
    if (next(first(L)) == first(L)) {
        P = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        P = prev(first(L));
        adrPr Q = prev(P);
        next(Q) = first(L);
        prev(first(L)) = Q;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfterPr(ListPr &L, adrPr Prec, adrPr &P) {
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

void deletePr(ListPr &L, adrPr P){
    if (first(L) == NULL){ // kalo kosong
        cout<<"empty\n";
    } else if (next(first(L)) == first(L)){ //kalo cuma 1
        deleteFirstPr(L, P);
    } else {
        if (P == first(L)) {
            deleteFirstPr(L, P);
        } else if (next(P) == first(L)) {
            deleteLastPr(L, P);
        } else {
            adrPr Prec = first(L);
            while (next(Prec) != P){
                Prec = next(Prec);
            }
            deleteAfterPr(L, Prec, P);
        }
    }
}

//CIRCULLAR DLL
void printInfoPr(ListPr L) {
 
    if (first(L) == NULL) { //kalo kosong
        cout<<"empty \n";
        cout<<" \n";
    } else {
        adrPr P = first(L);
        do {                // pake do while biar yg paling akhir ke cek juga
            cout<<"AGEN: "; // kl pake while do ribet krn circullar
            cout<< info(P) << " \n";
            cout<<"LOKASI: \n";
            printInfoCh(child(P));
            cout<<" \n";
            P = next(P);
        } while(P != first(L));
        cout << "\n";
    }
}


//NYARI AGEN
adrPr findElmPr(ListPr L, infotypePr x) {
    adrPr P = first(L);
    if (info(P) != x) { //ngecek dulu kl misalnya infonya == x langsung return P
        do {
            P = next(P);
            if (info(P) == x) {
                return P;
            }
        } while (P != first(L) && info(P) != x);
        P = NULL;       // kl udh semua di cek gaada ya P nya jd NULL gt
    }
    return P;           // langsung return P di sini
}

//MENU UPDATE
void updateList(ListPr &Lp) {
    int pilih;
    string agenBaru;
    string agen;
    string lokasiBaru;
    adrPr Q;
    


    cout<<"PILIHAN UPDATE: \n";
    cout<<"     1. Data Agen \n";
    cout<<"     2. Data Lokasi \n";
    cout<<"  \n";
    cout<<"Masukkan Pilihan Update: ";
    cin>>pilih;
    cout<<" \n";

    if (pilih == 1) {
        cout<<"Masukkan Nama Agen Baru: ";
        cin>>agenBaru;
        cout<<" \n";
        insertFirstPr(Lp, alokasiPr(agenBaru));
    } else if (pilih == 2) {
        cout<< "Agen Yang Tersedia: \n";
        
        //cout semua agen dulu biar keliatan kan enak gt ntar milihnya
        adrPr P = first(Lp);
        do {
            cout<< "- " << info(P) << " \n";
            P = next(P);
        } while (P != first(Lp));
        
        cout<<"\n";
        cout<< "Pilih Agen: " ;
        cin>>agen;
        cout<< "\n";
        
        Q = findElmPr(Lp, agen);
        
        cout<< "Masukkan Lokasi Baru: ";
        cin>> lokasiBaru;
        insertFirstCh(child(Q), alokasiCh(lokasiBaru));
        //child(Q) karena Q nunjuk elemen yg mau di insert child
    } else {
        cout<<"Menu Tidak Tersedia";
    }
}

adrPr lokasiTerbanyak(ListPr &L) {
    if (first(L) == NULL) {
        return NULL;
    }
    adrPr P = first(L);
    adrPr Q = first(L);
    int max = 0;
    do {
        int i = hitungCh(child(P));
        if (max < i) {
            max = i;
            Q = P;
        }
        P = next(P);
    } while (P != first(L));
    
    return Q;
}




void deleteList (ListPr &Lp, ListCh &Lc){
    int pilih;
    string agen;
    string lokasi;

    cout<<"PILIHAN DELETE: \n";
    cout<<"     1. Data Agen \n";
    cout<<"     2. Data Lokasi \n";
    cout<<"  \n";
    cout<<"Ketik No. Pilihan: ";
    cin>>pilih;

    if (pilih == 1){
        cout<<"\n";
        adrPr P = first(Lp);
        cout<<"DATA AGEN: \n";
        do {
            cout<<"- "<<info(P) << " \n";
            P = next(P);
        } while (P != first(Lp));
        cout<<" \n";
        cout<< "Masukkan Nama Agen: " ;
        cin>>agen;
        cout<< "\n";
        adrPr Q = findElmPr(Lp, agen);
        deletePr(Lp, Q);
        
        
    } else if (pilih == 2){
        cout<<"\n";
        //SHOW DATA AGEN YANG TERSEDIA
        adrPr P = first(Lp);
        cout<<"DATA AGEN: \n";
        do {
            cout<<"- "<<info(P) << " \n";
            P = next(P);
        } while (P != first(Lp));
        
        
        cout<<" \n";
        cout<< "Masukkan Nama Agen: " ;
        cin>>agen;
        cout<< "\n";
        adrPr Q = findElmPr(Lp, agen);
        
        cout<<"Lokasi Pada Agen "<<agen<<" : \n";
        printInfoCh(child(Q));
        cout<<" \n";
        
        cout<< "Masukkan Lokasi Yang Ingin Di Delete: ";
        cin>> lokasi;
        adrCh R = findElmCh(child(Q), lokasi);
        deleteCh(child(Q), R);
        
        
    }


}
