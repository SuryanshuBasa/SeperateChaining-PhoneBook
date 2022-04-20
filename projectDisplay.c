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
	int data;
	struct node* link;
};
struct node* root[size];

void initial() {
	int i;
	for(i=0 ; i< size ; i++)
		root[i] == NULL;
}

void append(int ele) {
	int loc;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->link = NULL;
	loc = ele % size;
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
				printf("%d->",p->data);
				p = p->link;
			}
			printf("\n");
		} else
			printf("NULL\n");
	}
}
int main() {
	initial();
	append(3);
	append(2);
	append(9);
	append(6);
	append(11);
	append(13);
	display();
	return 0;
}




