#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct node
{
	int data;
	struct node *link;
}node;
node *start1=NULL,*start2=NULL;
node* to_linked_list(char *number,node *start,int flag)
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
	return start;
}
node* merge(node *head1,node *head2)
{
    if (head1==NULL)
        return head2;
    else if (head2==NULL)
        return head1;
    if (head1->data < head2->data)
	{
        head1->link=merge(head1->link, head2);
        return head1;
	}
    else
	{
        head2->link=merge(head2->link, head1);
        return head2;
	}
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
		printf("\t%d\n",temp->data);

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
	node *temp1;
	char *number1,*number2,ch;
	int size=0,flag=0,select;
	number1=(char*)malloc(sizeof(char)*1);
	printf("\nEnter your number\n");
	while ((ch = getchar()) != '\n')
	{
			number1=(char*)realloc(number1,size+1);
			number1[size]=ch;
			if ((size>0)&&!(number1[size]>number1[size-1]))//only increasing order sanity check
			{
				printf("INVALID INPUT");
				getch();
				return 0;
			}

			size++;
	}
	number1[size]='\0';
	size=0;
	number2=(char*)malloc(sizeof(char)*1);
	printf("\nEnter your second number\n");
	while ((ch = getchar()) != '\n')
	{
			number2=(char*)realloc(number2,size+1);
			number2[size]=ch;
			if ((size>0)&&!(number2[size]>number2[size-1]))//only increasing order sanity check
			{
				printf("INVALID INPUT");
				getch();
				return 0;
			}

			size++;
	}
	number2[size]='\0';
	flag=input(number1,flag);
    start1=to_linked_list(number1,start1,flag);
	flag=input(number2,flag);
    start2=to_linked_list(number2,start2,flag);
	temp1=merge(start1,start2);
	display(temp1);
	getch();
	return 0;
}