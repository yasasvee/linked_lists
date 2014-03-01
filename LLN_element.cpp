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
int find_n(node *start,int num,int temp)
{
	if (start->link==NULL)
	{
		if(num==temp)
			printf("\nElement found : %d",start->data);
		return (temp+1);		
	}
	temp=find_n(start->link,num,temp);
	if(temp==num)
	{
		printf("\nElement found : %d",start->data);
		return temp-1;
	}
	else
		return temp+1;
}
void display(node *start)
{
	node *temp=NULL;
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
	printf("\nEnter the pos of element to be found from last\n");
	scanf("%d",&num);
	find_n(start,num,temp);

	//display(start);
	getch();
	return 0;
}