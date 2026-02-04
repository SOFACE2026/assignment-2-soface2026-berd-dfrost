#ifndef SHOP_H
#define SHOP_H

#include <stdbool.h>

// forward declaration necessary when compiling with gcc, not necessary in g++
typedef struct Shop Shop;

// Shop with pointers to functions.
// These will be populated with pointers to a certain implementation's functions.
typedef struct Shop {
    void (*deconstruct)(Shop*);
    void (*add_items)  (Shop*, int, int);
    int  (*in_stock)   (Shop*, int);
    int  (*count_items)(Shop*);
    bool (*clear)      (Shop*, int);
} Shop;

#endif