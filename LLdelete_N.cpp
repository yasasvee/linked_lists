#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct node
{
	int data;
	struct node *link;
}node;
node *start=NULL,*temp=NULL;
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
int del_n(node *start,int num,int temp)
{
	if (start->link==NULL)
	{
		return temp+1;		
	}
	temp=del_n(start->link,num,temp);
	if(num==temp-1)
	{
	start->link=NULL;
	return temp+1;
	}
	else
		return temp+1;
}
void display(node *start)
{
	node *temp=NULL;
	temp=start;
	if(start==NULL)
	{
		printf("\nEMPTY LIST");
		return;
	}	
	while(temp->link!=NULL)
	{
		printf("\t%d",temp->data);
		temp=temp->link;
	}
		printf("\t%d",temp->data);

}
int main(void)
{
	char *number,ch;
	int size=0,flag=0,num,temp=1;
	number=(char*)malloc(sizeof(char)*1);
	printf("\nEnter your number\n");
	while ((ch = getchar()) != '\n')
	{
			number=(char*)realloc(number,size+1);
			number[size]=ch;
			size++;
	}
	number[size]='\0';
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
    to_linked_list(number,flag);
	printf("\nEnter the number of elements to be deleted from last\n");
	scanf("%d",&num);
	temp=del_n(start,num,temp);//if number of elements to be deleted is more than the actual size of list, deleting all.
	if((temp==num+1)||(temp==num))
	{
		start=NULL;
	}
	display(start);
	getch();
	return 0;
}