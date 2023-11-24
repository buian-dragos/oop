#pragma once
#include "Repository.h"

typedef struct {
	Repository* repo;
}Service;

Service* create_service(Repository* repo);
void remove_product(Repository* repo, char* name, char* category);
void add_product(Repository* repo, Product new_prod);
void destroy_service(Service* serv);
