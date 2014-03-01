#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct node
{
	int data;
	struct node *link;
}node;
node *start=NULL,*temp=NULL,*newnode=NULL;
void to_linked_list(char *number,int flag)
{
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
void find_median(node *head)
{
	int count=0;
	node *p1=head,*p2=head;
	while((p2->link!=NULL)&&(p2->link->link!=NULL))
	{
		p1=p1->link;
		p2=p2->link->link;
		count++;
	}
	if(p2->link==NULL)
		printf("the median is : %d\n",p1->data);
	else
		printf("the median is : %d\n",(p1->data+p1->link->data)/2);
}
void display(node *start)
{
	temp=start;
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
	int size=0,flag=0;
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
	find_median(start);
	display(start);
	getch();
	return 0;
}