#include "ShoeShop.h"

int main() {
	ShoeShop* shop = new_ShoeShop(2);
	add_items(shop, 0, 2);
	add_items(shop, 1, 3);
	int tot = count_items(shop);
	if (tot > 0) {
		clear(shop, 0);
		clear(shop, 1);
	}
}