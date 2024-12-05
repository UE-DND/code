#include <stdio.h>
#include <stdlib.h>
struct node
{
	char no[12];
	char name[12];
	struct node *next;
};
//尾插法创建带头节点的链表
void creat1(struct node *head)
{
	struct node *tail=NULL;
	struct node *p=NULL;
	tail=head;
	while(1)
	{
		printf("creat node ? Y or N");
		fflush(stdin);
		if(getchar()=='N')
			break;
		p = (struct node *)calloc(1,sizeof(struct node));
		if(p==NULL)
			return;
		printf("input no\n");
		fflush(stdin);
		scanf("%s",p->no);
		printf("input name\n");
		fflush(stdin);
		scanf("%s",p->name);
		tail->next=p;
		tail=p;
	}
}
//头插法创建带头节点的链表
void creat2(struct node *head)
{
	struct node *p=NULL;
	while(1)
	{
		printf("creat node ? Y or N");
		fflush(stdin);
		if(getchar()=='N')
			break;
		p = (struct node *)calloc(1,sizeof(struct node));
		if(p==NULL)
			return;
		printf("input no\n");
		fflush(stdin);
		scanf("%s",p->no);
		printf("input name\n");
		fflush(stdin);
		scanf("%s",p->name);
		p->next=head->next;
		head->next=p;
	}
}

void printList(struct node *head)
{
	struct node *p=NULL;
	for(p=head->next;p!=NULL;p=p->next)
		printf("no:%s\tname:%s\n",p->no,p->name);
}

int modify(struct node *head,char *no)
{
	struct node *p=NULL;
	char name[12];
	for(p=head->next;p!=NULL;p=p->next)
		if(strcmp(p->no,no)==0)
		{
			printf("input new name\n");
			gets(name);

			strcpy(p->name,name);
			printf("update success!\n");
			return 1;
		}
	return 0;
}

void main()
{
	struct node *head=NULL;
	struct node *p=NULL;

	head = (struct node *)calloc(1,sizeof(struct node));
	
	creat2(head);
	printList(head);	
}