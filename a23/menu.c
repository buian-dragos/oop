#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include "Repository.h"
#include "Service.h"

void print_menu()
{
	printf("1.Add product\n");
	printf("2.Delete product\n");
	printf("3.Update product\n");
	printf("4. Display\n");
	printf("0.Exit\n");
}

void menu()
{
	Repository* repo = create_repository(100);
	Service* serv = create_service(repo);

	while (1) {
		print_menu();
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		default:
			break;
		}
	}



}
