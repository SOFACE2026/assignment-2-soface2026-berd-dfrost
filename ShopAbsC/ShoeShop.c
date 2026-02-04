#include <stdlib.h>
#include "ShoeShop.h"

// these are the methods available to anyone that wants to use the functions from Shop
// they can be used without knowledge of ShoeShop's specific internal workings, namely that it has shelves and a size

// the bodies of these functions are adapted from the classes to accomodate needing to be passed the ShoeShop that's to be modified.

void ss_delete(ShoeShop* shop) {
	free(shop->shelf);
    free(shop);
}

void ss_add_items(ShoeShop* shop, int row, int num) {
	shop->shelf[row] += num;
}

int ss_in_stock(ShoeShop* shop, int row) {
	return shop->shelf[row] > 0;
}

int ss_count_items(ShoeShop* shop) {
	int tot = 0;
	for (int k = 0; k < shop->size; k++) {
		tot += shop->shelf[k];
	}
	return tot;
}

bool ss_clear(ShoeShop* shop, int row) {
	bool rem = shop->shelf[row] > 0;
	shop->shelf[row] = 0;
	return rem;
}

// this is where the functions get put in.
// when we typecast a ShoeShop to a Shop, these are what the actual functions we'll be calling are.
ShoeShop* ss_new(int size) {
    ShoeShop* newshop = (ShoeShop*)malloc(sizeof(ShoeShop));
	newshop->size = size;
	newshop->shelf = (int*)calloc(size, sizeof(int));
    newshop->deconstruct = ss_delete;
    newshop->add_items   = ss_add_items;
    newshop->in_stock    = ss_in_stock;
    newshop->count_items = ss_count_items;
    newshop->clear       = ss_clear;
    return newshop;
}