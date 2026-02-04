#include "ShoeShop.h"
#include <stdlib.h>

// these are each corrolaries of the ShoeShop's methods and variables

// this struct contains the private variables
struct st_ShoeShop {
    int* shelf;
    int size;
};

// the constructor
ShoeShop* new_ShoeShop(int size) {
    ShoeShop* newshop = malloc(sizeof(ShoeShop));
    newshop->size = size;
    newshop->shelf = calloc(size, sizeof(int));
    return newshop;
}

// the deconstructor
void delete_ShoeShop(ShoeShop* oldshop) {
    free(oldshop->shelf);
    free(oldshop);
}

// for each of the methods, the relevant shoeshop must be provided as a pointer
// the contents of each are adapted from the class methods, largely replacing "this->some_value" into "(ShoeShop* shop)->some_value"

void add_items(ShoeShop* shop, int row, int num) {
	shop->shelf[row] += num;
}

int in_stock(ShoeShop* shop, int row) {
	return shop->shelf[row] > 0;
}

int count_items(ShoeShop* shop) {
	int tot = 0;
	for (int k = 0; k < shop->size; k++) {
		tot += shop->shelf[k];
	}
	return tot;
}

bool clear(ShoeShop* shop, int row) {
	bool rem = shop->shelf[row] > 0;
	shop->shelf[row] = 0;
	return rem;
}