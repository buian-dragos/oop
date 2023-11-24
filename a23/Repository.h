#pragma once

#include "Product.h"

typedef struct{
	Product* products;
	int size;
	int max_size;
}Repository;

Repository* create_repository(int max_size);
void add_product_repo(Repository* repo, Product prod);
void update_product_repo(Repository* repo, Product prod);
void remove_product_repo(Repository* repo, int index);


void destroy_repo(Repository* repo);

int get_size(Repository* repo);
Product get_current_product(Repository* repo, int index);
void get_products(Repository* repo, Product* product_list);
int get_product_index(Repository* repo, char* name, char* category);
