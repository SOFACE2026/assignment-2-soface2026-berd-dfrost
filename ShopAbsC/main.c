// #include "ShoeShop.h"
#include "ShoeShop.h"

// Shop is a struct type with function pointers that are listed in a certain order.
// ShoeShop has similar function pointers in the same certain order
// ShoeShop is a specific implementation of the generic Shop. Shop provides generic functions, ShoeShop provides functions specific to a ShoeShop

int main() {
    // shoeshop now contains specific 'methods' in it that point to actual functions
	ShoeShop* shoeshop = ss_new(2);
    // shop is a generic typecast of our shoeshop. this means we can write the 'add_items()' method from Shop, but in actuality we're using 'add_items()' from ShoeShop.
    // this makes our code largely ignorant of whether it's a ShoeShop or a ToyStore, if we had implemented a similar struct for a ToyStore.
    Shop* shop = (Shop*)shoeshop;

	shop->add_items(shop, 0, 2); // here, c believes were using Shop's 'add_items()', when we're actually using the more specific 'add_items()' from ShoeShop.
	shop->add_items(shop, 1, 3);
	int tot = shop->count_items(shop);
	if (tot > 0) {
		shop->clear(shop, 0);
		shop->clear(shop, 1);
	}
}