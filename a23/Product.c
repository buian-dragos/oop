#include "Product.h"
#include <string.h>
#include <stdlib.h>

Product create_product(char name[], char category[], int quant, int exp_date)
{
	Product prod;
	
	prod.name = malloc(sizeof(char) * (strlen(name) + 1));	
	if (prod.name == NULL)
		return prod;

	strcpy(prod.name, name);
	strcpy(prod.category, category);
	prod.quantity = quant;
	prod.exp_date = exp_date;
	
	return prod;
}

void destroy_product(Product* prod)
{
	free(prod->name);
}
