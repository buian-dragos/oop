#pragma once

typedef struct {
	char* name;
	char category[7];
	int quantity;
	int exp_date;
}Product;

Product create_product(char name[], char category[], int quant, int exp_date);
void destroy_product(Product* prod);