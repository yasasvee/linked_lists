#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct node
{
	int data;
	struct node *link;
}node;
node *start=NULL;
void to_linked_list(char *number,int flag)
{
	struct node *temp=NULL,*newnode=NULL;
	int pos=0;
	while(number[pos])
	{
		newnode=(node*)malloc(sizeof(node));
		if(flag==1)
		{
		newnode->data=0-(number[pos]-'0');
		flag=0;
		}
		else
			newnode->data=(number[pos]-'0');
		newnode->link=NULL;
		if(start==NULL)
		{
			start=newnode;
			temp=start;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
		}
		pos++;
	}
}
void display(node *start)
{
	node *temp=NULL;
	temp=start;
	if(start==NULL)
	{
		printf("\nLIST EMPTY\n");
		exit(0);
	}
	while(temp->link!=NULL)
	{
		printf("\t%d",temp->data);
		temp=temp->link;
	}
		printf("\t%d",temp->data);

}
void del(node *head)
{
	int select,num,flag=0;
	node *temp,*newnode;
	do{
	printf("Enter the value to be deleted");
	scanf("%d",&num);
	temp=head;
	if(head==NULL)
	{
		printf("\nLIST EMPTY\n");
		exit(0);

	}
	if(head->data==num)
	{
		head=head->link;
		flag=1;
	}
	while((temp->link!=NULL)&&(flag!=1))
	{
		if(temp->link->data==num)
		{
			temp->link=temp->link->link;
			flag=1;
		}
		temp=temp->link;
	}
	if(!(flag))
		printf("\nValue not found\n");
	printf("\nmodified list is");
	display(head);
	printf("\nEnter 1 to delete and 0 to exit\n");
	scanf("%d",&select);
	flag=0;
	}while(select);

}

int input(char *number,int flag)
{
	while((number[0]=='-')||(number[0]=='0'))
	{
		if((number[0]=='-')&&(number[1]!='0'))
		{
			flag=1;
			number++;
		}
		else if(number[0]=='0')
		{
			number++;
		}
	}
	return flag;
}
int main(void)
{
	char *number,ch;
	int size=0,flag=0,select;
	number=(char*)malloc(sizeof(char)*1);
	printf("\nEnter your number\n");
	while ((ch = getchar()) != '\n')
	{
			number=(char*)realloc(number,size+1);
			number[size]=ch;
			size++;
	}
	number[size]='\0';
	flag=input(number,flag);
    to_linked_list(number,flag);
	del(start);
	printf("\nYour final list is\n");
	display(start);
	getch();
	return 0;
}