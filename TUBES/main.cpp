//
//  main.cpp
//  TUBES
//
//  Created by Nadja Shafa Adryana on 05/04/20.
//  Copyright © 2020 Nadja Shafa Adryana. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "parent.h"
#include "child.h"

void mainMenu(string &menu) {
    cout<<"M   E   N   U \n";
    cout<<"=============\n";
    cout<<"1. SHOW \n";
    cout<<"-------------\n";
    cout<<"2. UPDATE \n";
    cout<<"-------------\n";
    cout<<"3. DELETE \n";
    cout<<"-------------\n";
    cout<<"4. SELESAI \n";
    cout<<"-------------\n";
    cout<<" \n";
    cout<<"Masukkan Pilihan: ";
    cin>> menu;
    cout<< "   \n";
}

int main() {
    ListPr Lp;
    ListCh Lc;
    int pilih;
    string agen;
    string yes;

    
    createListPr(Lp);
    string menu;
    cout<< " -------------------------\n";
    cout<< "|                         |\n";
    cout<< "|         WELCOME         |\n";
    cout<< "|           T O           |\n";
    cout<< "|     N2 TRAVEL AGENCY    |\n";
    cout<< "|                         |\n";
    cout<< " -------------------------\n";
    cout<<" \n";
    mainMenu(menu);
    while(menu != "4") {
        if (menu == "1") {
            cout<<"Pilihan Menu Show: \n";
            cout<<"     1. SHOW ALL \n";
            cout<<"     2. SHOW AGEN / LOKASI \n";
            cout<<"     3. SHOW AGEN DENGAN LOKASI TERBANYAK \n";
            cout<<" \n";
            cout<<"Pilihan Show: ";
            cin>>pilih;
            cout<<" \n";
            
            if (pilih == 1) {
                printInfoPr(Lp);
            } else if (pilih == 2) {
                
                //-------OUTPUT AGEN--------
                adrPr P = first(Lp);
                cout<<"DATA AGEN: \n";
                do {
                    cout<<"- "<<info(P) << " \n";
                    P = next(P);
                } while (P != first(Lp));
                cout<<" \n";
                cout<<" \n";
                
                //-------OUTPUT LOKASI--------
                cout<<"SHOW LOKASI (Y/N)? ";
                cin>>yes;
                cout<<" \n";
                if (yes == "Y" || yes == "y") {
                    cout<<"Pilih Agen Yang Ingin Show Lokasi: ";
                    cin>>agen;
                    cout<< "\n";
                    adrPr Q = findElmPr(Lp, agen);
                    cout<<"Lokasi Pada Agen "<< agen << ": \n";
                    printInfoCh(child(Q));
                
                }
            } else if (pilih == 3) {
                adrPr Q = lokasiTerbanyak(Lp);
                cout<<" \n";
                cout<<"Agen Dengan Lokasi Wisata Terbanyak: "<< info(Q);
                cout<<" \n";
            } else {
                cout<<"Menu Tidak Tersedia";
            }
            
        } else if (menu == "2") {
            updateList(Lp);
        } else if (menu == "3") {
            deleteList(Lp, Lc);
        } else {
            cout<<"Menu Tidak Tersedia\n";

        }
        cout<<" \n";
        mainMenu(menu);
    }



}
