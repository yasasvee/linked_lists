#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
node *start=NULL,*tail=NULL;
void to_linked_list(char *number,int flag)
{
	node *newnode=NULL;
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
		newnode->right=NULL;
		newnode->left=NULL;
		if(start==NULL)
		{
			start=newnode;
			tail=start;
		}
		else
		{
			tail->right=newnode;
			newnode->left=tail;
			tail=newnode;
		}
		pos++;
	}
}
void find_middle(node *head,node *tail)
{
	if(head==tail)
	{
		printf("\nThe middle element is= %d:",tail->data);
		return;
	}
	while((head->right!=tail->left)&&(head!=tail->left))
	{
		head=head->right;
		tail=tail->left;
	}
	printf("\nThe middle element is= %d:",tail->left->data);
}

void display(node *start)
{
	node *temp;
	temp=start;
	while(temp->right!=NULL)
	{
		printf("\t%d",temp->data);
		temp=temp->right;
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
	find_middle(start,tail);
	display(start);
	getch();
	return 0;
}