#ifndef SHOESHOP_H
#define SHOESHOP_H

#include <stdbool.h>

// class ShoeShop {
// private:
// 	int* shelf;
// 	int size;
// public:
// 	ShoeShop(int);
// 	~ShoeShop();
// 	void add_items(int, int);
// 	int in_stock(int);
// 	int count_items();
// 	bool clear(int);
// };

// these are each corrolaries of the ShoeShop's methods and variables

// this struct contains the private variables
typedef struct st_ShoeShop ShoeShop;

// the constructor
ShoeShop* new_ShoeShop(int);
// the deconstructor
void delete_ShoeShop(ShoeShop*);

// for each of the methods, the relevant shoeshop must be provided as a pointer
void add_items(ShoeShop*, int, int);
int in_stock(ShoeShop*, int);
int count_items(ShoeShop*);
bool clear(ShoeShop*, int);

#endif