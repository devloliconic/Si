#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
} Node;

Node *Add(Node *Top, int d){
	Node *new_el = (Node*)malloc(sizeof(Node));
	new_el->data = d;
	new_el->next = Top;
	return new_el;
}


void show(Node *Top){
	while(Top){
		if(Top->next){
			printf("%d ",Top->data);
		}
		else{
			printf("%d\n",Top->data);
		}
		Top = Top->next;
	}
}

void Delete_similar(Node *Top){
	Node *help_item, *next_element, *element_for_chek, *p = Top;
	while(p != NULL){
		next_element = p->next;
		while((next_element != NULL) && (next_element->data == p->data)){
			next_element = next_element->next;
		}
		if(next_element != p->next){
			element_for_chek = p->next;
			while(element_for_chek != next_element){
				help_item = element_for_chek;
				element_for_chek = element_for_chek->next;
				free(help_item);
			}
			p->next = next_element; 
			p = next_element;
		}
		else{
			p = p->next;
		}
	}
}



int main(int argc, char *argv[]) {
	system("chcp 1251");
	FILE *f;
	f = fopen("datafor.txt","r");
	if (!f){
		printf("‘айл не найден.\n");
		return 0;
	}
	else{
		printf("ќк...\n");
	}
	int i;
	int digit_in_mass;
	Node *LIFO = NULL;
	while(!feof(f)){
		if(fscanf(f,"%d", &digit_in_mass)!=1){
			break;
		}
		LIFO = Add(LIFO,digit_in_mass);
	}
	show(LIFO);
	Delete_similar(LIFO);
	show(LIFO);
	return 0;
}
