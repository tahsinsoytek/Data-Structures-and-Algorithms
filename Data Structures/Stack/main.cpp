#include <iostream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Node
{
	public:
	Node* next;
	int data;
	Node()
	{
		next=NULL;
	}
};
class Stack
{
	public:
		Stack()
		{
			head=NULL;
			ptrTop=NULL;
			top=-1;
		}
		bool IsEmpty()
		{
			return top==-1;
		}
		int Top()
		{
		    return top;
		}
		void Push(int x)
		{
			Node* newNode=new Node();
			newNode->data=x;
			if(IsEmpty())
			{
				head=new Node();
				head->next=newNode;
				ptrTop=newNode;
			}
			else
			{
				ptrTop->next=newNode;
				ptrTop=newNode;
			}
			top++;
		}
		int Pop()
		{
			int x=ptrTop->data;
	        if(IsEmpty())
			{
				printf("Stack is empty");
			}
			else
			{
				Node* CurrNode=head;
				while(CurrNode->next!=ptrTop)
				{
					CurrNode=CurrNode->next;
				}
				CurrNode->next=NULL;
				ptrTop=CurrNode;
				top--;
			}
			return x;
		}
		void DisplayStack()
		{
		    if(IsEmpty())
			{
				printf("Stack is empty\n");
			}
			else
			{
				printf("*/STACK*/\n");
				Node* CurrNode=head->next;
				while(CurrNode)
				{
					printf("%d\n",CurrNode->data);
					CurrNode=CurrNode->next;
				}
			}
		}
    private:
		int top;
		Node* ptrTop;
		Node* head;	
};
int main(int argc, char** argv) 
{
	int i,x;
	srand(time(0));
	Stack* s=new Stack();
	printf("How many numbers do you want do add?\n");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		s->Push(rand()%40);
	}
	printf("Value of Top:%d\n",s->Top());
	s->DisplayStack();
    printf("%d\n",s->Pop());
    s->DisplayStack();
    for(i=0;i<x-1;i++)
	{
		s->Pop();
	}
	s->DisplayStack();
	for(i=0;i<x+5;i++)
	{
		s->Push(rand()%90);
	}
	s->DisplayStack();
	
	
	
	
	
	
	
	
	
	return 0;
}
