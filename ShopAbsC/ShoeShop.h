#ifndef SHOESHOP_H
#define SHOESHOP_H

#include "Shop.h"

// forward declaration necessary when compiling with gcc, not necessary in g++
typedef struct ShoeShop ShoeShop;

// The specific implementation of shoeshop. It now has data members.
// the functions it shares with the generic Shop struct are in the same order for when we typecast it to Shop
typedef struct ShoeShop {
    void (*deconstruct)(ShoeShop*);
    void (*add_items)  (ShoeShop*, int, int);
    int  (*in_stock)   (ShoeShop*, int);
    int  (*count_items)(ShoeShop*);
    bool (*clear)      (ShoeShop*, int);
    int* shelf;
    int size;
} ShoeShop;

// an initializer for the ShoeShop struct. Necessary to be outside the struct as it populates the struct itself with the necessary functions.
ShoeShop* ss_new(int size);

#endif