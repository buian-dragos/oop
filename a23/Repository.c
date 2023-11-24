#include "Repository.h"
#include "Product.h"
#include <stdlib.h>

Repository* create_repository(int max_size)
{
	Repository* repo = malloc(sizeof(Repository));
	if (repo == NULL)
		return NULL;
	repo->size = 0;
	repo->products = malloc(sizeof(Product) * max_size);
	repo->max_size = max_size;
	return repo;
}

void add_product_repo(Repository* repo, Product prod)
{
	repo->products[repo->size] = prod;
	repo->size++;
}

void update_product_repo(Repository* repo, Product prod)
{
}

void remove_product_repo(Repository* repo, int index)
{
	for (index; index < repo->size; index++) {
		repo->products[index] = repo->products[index + 1];
	}
}


void destroy_repo(Repository* repo)
{
	if (repo == NULL)
		return;

	for (int i = 0; i < repo->size; i++) {

	}

	free(repo->products);
	free(repo);

}

int get_size(Repository* repo)
{
	return repo->size;
}

Product get_current_product(Repository* repo, int index)
{
	//need validation for index
	if (repo == NULL)
		return;
	return repo->products[index];
}

void get_products(Repository* repo, Product* product_list)
{
	//deprecated
	for (int i = 0; i < repo->size; i++) {
		product_list[i] = repo->products[i];
	}
}

int get_product_index(Repository* repo, char* name, char* category)
{
	
	Product current;
	for (int i = 0; i < repo->size; i++) {
		current = get_current_product(repo, i);
		if ((strcmp(current.name, name) == 0) && (strcmp(current.category, category) == 0)) {
			return i;
		}
	}
	return -1;
}


