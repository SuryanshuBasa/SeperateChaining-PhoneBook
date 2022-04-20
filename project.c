#define size 10
//#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//using namespace std;

struct node {
	char name[20];
	int phone;
	int id;
	struct node* link;
};

struct node* root[size];

void initial() {
	int i;
	for(i=0 ; i< size ; i++)
		root[i] == NULL;
}

void details(struct node* temp) {
	printf("Name: ");
	scanf("%s",temp->name);
	printf("Phone NUm: ");
	scanf("%d",&temp->phone);
	printf("Id: ");
	scanf("%d",&temp->id);
}
void append() {
	int loc;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	details(temp);
	temp->link = NULL;
	loc = (temp->name[0]) % size;
	if(root[loc] == NULL)
		root[loc] = temp;
	else {
		struct node* p;
		p = root[loc];
		while(p->link != NULL)
			p = p->link;
		p->link = temp;
	}
}
void display() {
	int i;
	struct node* p;
	for(i=0 ; i< size ; i++) {
		if(root[i] != NULL) {
			p = root[i];
			while(p != NULL) {
				printf("|%s||%d||%d|->",p->name,p->phone,p->id);
				p = p->link;
			}
			printf("\n");
		} else
			printf("NULL\n");
	}
}

void search() {
	int n,i,loc;
	struct node* p;
	char name[20];
	printf("Enter Name: ");
	scanf("%s",name);
	loc = name[0] % size;
	p = root[loc];
	while(strcmp(p->name,name))
		p = p->link;
	printf("|%s||%d||%d|\n",p->name,p->phone,p->id);	
}
void deletion()
{
	int loc,i;
	struct node* p,*q;
	char name[20];
	printf("Enter name to delete: ");
	scanf("%s",name);
	loc = name[0] % 10;
	p = root[loc];
	while(strcmp(name,p->link->name))
		p = p->link;
	q = p->link;
	p->link = NULL;
	free(q);	
}
int main() {
	int i,n;
	printf("No of Entries: ");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		append();
	display();
	printf("\n\n");
	search();
	deletion();
	display();
	return 0;
}




