//
//  child.cpp
//  TUBES
//
//  Created by Nadja Shafa Adryana on 08/04/20.
//  Copyright © 2020 Nadja Shafa Adryana. All rights reserved.
//

#include <stdio.h>
#include "child.h"
#include "parent.h"

void createListCh(ListCh &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adrCh alokasiCh(infotypeCh x) {
    adrCh P = new elmCh;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;

}


void insertFirstCh(ListCh &L, adrCh P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}


void deleteFirstCh(ListCh &L, adrCh &P){
    if (first(L) == NULL){
        cout << "empty\n";
    } else if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(first(L));
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLastCh(ListCh &L, adrCh &P){
    if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
    } else {
        P = first(L);
        while (next(P) != NULL) {
            P = next(P);
        }
        next(prev(P)) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfterCh(ListCh &L, adrCh Prec, adrCh &P) {
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}


void deleteCh(ListCh &L, adrCh P){
    if (first(L) == NULL){
        cout<<"empty\n";
    } else if (next(first(L)) == NULL){
        deleteFirstCh(L, P);
    } else {
        if (P == first(L)) {
            deleteFirstCh(L, P);
        } else if (next(P) == NULL) {
            deleteLastCh(L, P);
        } else {
            adrCh Prec = first(L);
            while (next(Prec) != P){
                Prec = next(Prec);
            }
            deleteAfterCh(L, Prec, P);
        }
    }
}

void printInfoCh(ListCh L){
    adrCh P = first(L);
    while(P != NULL){
        cout<<"- "<<info(P)<< " \n";
        P = next(P);
    }
    cout<<" \n";
    
}

adrCh findElmCh(ListCh L, infotypeCh x){
    adrCh P = first(L);
    while ((P != NULL) && (info(P) != x)) {
        P = next(P);
    }
    if (info(P) == x){
        return P;
    } else {
        return NULL;
    }
}




int hitungCh(ListCh L) {
    int i = 0;
    adrCh P = first(L);
    do {
        i = i + 1;
        P = next(P);
    } while (P != NULL);
    
    return i;
}


