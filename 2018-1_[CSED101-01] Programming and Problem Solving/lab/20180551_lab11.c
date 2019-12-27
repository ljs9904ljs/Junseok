#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct song {
	char title[30];
	char artist[10];
	int time[2];
	int quality;
}SONG;

typedef struct node {
	SONG data;
	struct node *next;
}NODE;

typedef struct list {
	int count;
	NODE *head;
	NODE *tail;
}LIST;

void print_song(SONG p);
void insert_node(LIST *plist);
void print_list(LIST *plist);
void add_song(SONG *p);
void select(LIST *plist);

int main()
{
	char cmd[10];
	LIST myList = { 0,NULL,NULL };
	while (1)
	{
		printf(">> ");
		scanf("%s", cmd);
		getchar();
		if (strcmp("add", cmd) == 0) {
			insert_node(&myList); 
			printf("\n");
		}
		else if (strcmp("print", cmd) == 0) {
			print_list(&myList);
			printf("\n");
		}
		else if (strcmp("select", cmd) == 0) {
			select(&myList);
			printf("\n");
		}
		else if (strcmp("quit", cmd) == 0) {
			printf("\n");
			break;
		}
	}
	return 0;
}
void insert_node(LIST *plist)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->next = NULL;
	add_song(&temp->data);
	if (plist->head == NULL)
	{
		plist->count++;
		plist->head = temp;
		plist->tail = temp;
	}
	else
	{
		plist->tail->next = temp;
	}
	plist->count++;
	plist->tail = temp;
}
void print_list(LIST *plist)
{
	NODE *temp;
	int a = 1;
	for (temp = plist->head; temp; temp = temp->next)
	{
		printf("No. %d", a);
		print_song(temp->data);
		a++;
	}
}
void add_song(SONG *p)
{
	printf("TITLE: ");
	gets(p->title);
	printf("ARTIST: ");
	gets(p->artist);
	printf("TIME: ");
	scanf("%d %d", &p->time[0], &p->time[1]);
	printf("QUALITY: ");
	scanf("%d", &p->quality);
}
void print_song(SONG p)
{
	printf("\nTITLE : %s", p.title);
	printf("\nARTIST : %s", p.artist);
	printf("\nTIME : %dmin %dsec", p.time[0], p.time[1]);
	printf("\nQUALTIY : %dkbps", p.quality);
	printf("\n\n");


}
void select(LIST *plist)
{
	NODE *temp;
	int i = 1;
	int selection;
	printf("Input track number: ");
	scanf("%d", &selection);
	printf("\n");
	for (temp = plist->head; temp; temp = temp->next)
	{
		if (i == selection)
		{
			printf("No. %d\n", selection);
			print_song(temp->data);
		}
		i++;
	}
}

