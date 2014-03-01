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
void circular_linked_list(node *start)
{
	node *temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=start;
}
void display(node *start)
{
	node *temp=NULL;
	temp=start;
	while(temp->link!=start)
	{
		printf("\t%d",temp->data);
		temp=temp->link;
	}
		printf("\t%d",temp->data);

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
			if ((size>0)&&!(number[size]>number[size-1]))//only increasing order sanity check
			{
				printf("INVALID INPUT");
				getch();
				return 0;
			}

			size++;
	}
	number[size]='\0';
	flag=input(number,flag);
    to_linked_list(number,flag);
	circular_linked_list(start);
	display(start);
	getch();
	return 0;
}