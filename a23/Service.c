#include "Service.h"
#include <stdlib.h>
#include <exception>
#include <string.h>
#include <memory.h>

Service* create_service(Repository* repository)
{
	Service* serv;
	serv->repo = repository;
	return serv;
}

void remove_product(Repository* repo, char* name, char* category)
{
}

void add_product(Service* serv, Product new_prod)
{
	//check if prod exists - it should return old_quantity
	//call update_product(repo, new_prod->name, new_prod->category, old_quantity + new_prod->quantity, new_prod->exp_date);
	
	
	//Product* product_list = malloc(sizeof(Product)* get_size(serv->repo));
	//get_products(serv->repo,product_list);
	if (get_product_index(serv->repo, new_prod.name,new_prod.category) != -1) {
		Product current = get_current_product(serv->repo, get_product_index(serv->repo, new_prod.name,new_prod.category));
		Product updated_product = create_product(new_prod.name, new_prod.category, current.quantity + new_prod.quantity, new_prod.exp_date);
		update_product_repo(serv->repo, updated_product);
	}
			

	add_product_repo(serv->repo, new_prod);


	//free(product_list)
}



void destroy_service(Service* serv)
{
}
