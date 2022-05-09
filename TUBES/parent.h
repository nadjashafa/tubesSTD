//
//  parent.h
//  TUBES
//
//  Created by Nadja Shafa Adryana on 05/04/20.
//  Copyright © 2020 Nadja Shafa Adryana. All rights reserved.
//

#ifndef parent_h
#define parent_h
#include <iostream>
#include <cstring>
#include "child.h"


using namespace std;

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child



typedef string infotypePr;
typedef struct elmPr *adrPr;



struct elmPr {
    infotypePr info;
    adrPr next;
    adrPr prev;
    ListCh child;

};

struct ListPr {
    adrPr first;

};

void createListPr(ListPr &L);
adrPr alokasiPr(infotypePr x);
void insertFirstPr(ListPr &L, adrPr P);
void deleteFirstPr(ListPr &L, adrPr &P);
void deleteLastPr(ListPr &L, adrPr &P);
void deleteAfterPr(ListPr &L, adrPr Prec, adrPr &P);
void deletePr(ListPr &L, adrPr P);
void printInfoPr(ListPr L);
adrPr findElmPr(ListPr L, infotypePr x);
void updateList(ListPr &Lp);
adrPr lokasiTerbanyak(ListPr &L);
void deleteList (ListPr &Lp, ListCh &Lc);

#endif /* parent_h */
