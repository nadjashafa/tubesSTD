//
//  child.h
//  TUBES
//
//  Created by Nadja Shafa Adryana on 08/04/20.
//  Copyright © 2020 Nadja Shafa Adryana. All rights reserved.
//

#ifndef child_h
#define child_h

#include <iostream>

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

typedef string infotypeCh;
typedef struct elmCh *adrCh;

struct elmCh {
    infotypeCh info;
    adrCh next;
    adrCh prev;
};

struct ListCh {
    adrCh first;
    adrCh last;
    
};

void createListCh(ListCh &L);
adrCh alokasiCh(infotypeCh x);
void insertFirstCh(ListCh &L, adrCh P);
void deleteFirstCh(ListCh &L,adrCh &P);
void deleteLastCh(ListCh &L, adrCh &P);
void deleteAfterCh(ListCh &L, adrCh Prec, adrCh &P);
void deleteCh(ListCh &L, adrCh P);
void printInfoCh(ListCh L);
adrCh findElmCh(ListCh L, infotypeCh x);
int hitungCh(ListCh L);

#endif /* child_h */
