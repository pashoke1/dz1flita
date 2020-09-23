#include<stdio.h>
#include <stdlib.h>


struct node{
	int key;
	int value;
	struct node *next;	
};

void show(struct node *head){
	printf("Vash spisok:\n");
	while(head != NULL){
		printf("%d. ", head -> key);
		printf("%d\n", head -> value);
		head = head -> next;
	}	
}

struct node *addition(struct node *head, int val, int key){
	if (head == NULL){
		head = (struct node*)malloc(sizeof(struct node));
		head -> key = key;
		head -> value = val;
		head -> next = NULL;
	}	
	else{
		head->next = addition(head->next, val, key);
	}
	return head;
}

struct node *deletion(struct node *head, int key){
	int k=0;
	if (head == NULL){
		return head;
	}
	if (head->key == key){
		if(head->next == NULL){
			head = NULL;
			return head;
		}
		else{
			head = head -> next;
			k = 1;
		}
	}
	if (k == 1){
		head = deletion(head, key);
	}
	else{
		head -> next = deletion(head -> next, key);
	}
	return head;
}



int main(void){
	int choice = 0;
	int key = 0;
	int val;
	struct node *head;
	head = NULL;
	

	printf( "1. Pokasat'\n");
	printf( "2. Dobavit'\n");
	printf( "3. Udalit'\n");

	while(choice != EOF){
		printf("Viberite opciu:\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
			    show(head);	
			break;
			case 2:
			    printf("Chislo: ");
				  scanf("%d", &val);
				  ++key;
				  head = addition(head, val, key);	
			break;
			case 3:
				printf("Posicia: ");
				scanf("%d", &val);
				head = deletion(head, val);	
			break;

			default:
				printf("Neizvestnaya opciya!\n");	
		}
	}
	return 0;
}
