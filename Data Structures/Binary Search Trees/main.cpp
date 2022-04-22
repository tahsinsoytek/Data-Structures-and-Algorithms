#include <iostream>
#include <ctime>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class BinaryNode
{
	public:
		int data;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode()
		{
			left=NULL;
			right=NULL;
		}
};
class BinaryTree
{
	public:
		BinaryTree()
		{
			root=NULL;
		}
		BinaryNode* getRoot()
		{
			return root;
		}
		bool IsEmpty()
		{
			return root==NULL;
		}
		void Insert(int x)
		{
			BinaryNode* newNode=new BinaryNode();
			newNode->data=x;
			if(IsEmpty())
			{
				root=newNode;
			}
			else
			{
				BinaryNode* CurrNode=root;
				while(CurrNode)
				{
					if(x>CurrNode->data&&CurrNode->right)
					{
						CurrNode=CurrNode->right;
					}
					else if(x<CurrNode->data&&CurrNode->left)
					{
						CurrNode=CurrNode->left;
					}
					else
					{
						if(x>CurrNode->data)
						{
							CurrNode->right=newNode;
							CurrNode=CurrNode->right->right;
						}
						else
						{
							CurrNode->left=newNode;
							CurrNode=CurrNode->left->left;
						}
					}
				}
			}
		}
		void Delete(int x)
		{
			BinaryNode* FindNode=find(x);
			BinaryNode* CurrNode=root;;
			if(IsEmpty())
			{
				printf("Tree is empty\n");
				return;
			}
			if(FindNode->right&&FindNode->left)
			{
				bool b=true;
				BinaryNode* PrevNode=FindNode;
				CurrNode=FindNode->right;
				while(CurrNode->left)
				{
					PrevNode=CurrNode;
					CurrNode=CurrNode->left;
					b=false;
				}
				if(b)
				{
					PrevNode->right=CurrNode->right;
					PrevNode->data=CurrNode->data;
					delete CurrNode;
				}
				else
				{
					PrevNode->left=CurrNode->right;
					FindNode->data=CurrNode->data;
					delete CurrNode;
				}
			}
			else if(FindNode->right||FindNode->left)
			{
				while(CurrNode->right!=FindNode&&CurrNode->left!=FindNode)
				{
					if(x>CurrNode->data)
					{
						CurrNode=CurrNode->right;
					}
					else if(x<CurrNode->data)
					{
						CurrNode=CurrNode->left;
					}
					else
					{
						if(FindNode->right)
						{
							root=CurrNode->right;
							delete CurrNode;
							return;
						}
						else
						{
							root=CurrNode->left;
							delete CurrNode;
							return;
						}
					}
				}
				if(CurrNode->right==FindNode)
				{
					if(FindNode->right)
					{
						CurrNode->right=FindNode->right;
						delete FindNode;
					}
					else
					{
						CurrNode->right=FindNode->left;
						delete FindNode;
					}
				}
				else
				{
					if(FindNode->left)
					{
						CurrNode->left=FindNode->left;
						delete FindNode;
					}
					else
					{
						CurrNode->left=FindNode->right;
						delete FindNode;
					}
				}
				
			}
			else if(FindNode!=NULL)
			{
				while(CurrNode->right!=FindNode&&CurrNode->left!=FindNode)
				{
					if(x>CurrNode->data)
					{
						CurrNode=CurrNode->right;
					}
					else
					{
						CurrNode=CurrNode->left;
					}
				}
				if(CurrNode->right==FindNode)
				{
					CurrNode->right=NULL;
					delete FindNode;
				}
				else
				{
					CurrNode->left=NULL;
					delete FindNode;
				}
			}
			else
			{
				printf("The data you want to delete is not in the tree...\n");
			}
			
		}
		BinaryNode* find(int x)
		{
			BinaryNode* CurrNode=root;
			while(CurrNode)
			{
				if(x==CurrNode->data)
				{
					return CurrNode;
				}
				else
				{
					if(x>CurrNode->data)
					{
						CurrNode=CurrNode->right;
					}
					else
					{
						CurrNode=CurrNode->left;
					}
				}
			}
			return CurrNode;
		}
		BinaryNode* findMin()
		{
			BinaryNode* CurrNode=root;
			while(CurrNode->left)
			{
				CurrNode=CurrNode->left;
			}
			return CurrNode;
		}
		BinaryNode* findMax()
		{
			BinaryNode* CurrNode=root;
			while(CurrNode->right)
			{
				CurrNode=CurrNode->right;
			}
			return CurrNode;
		}
		void DisplayTree(BinaryNode* CurrNode)
		{
			if(IsEmpty())
			{
				printf("Tree is empty\n");
				return;
			}
			if(CurrNode->left)
			{
				DisplayTree(CurrNode->left);
			}
			printf("%d\n",CurrNode->data);
			if(CurrNode->right)
			{
				DisplayTree(CurrNode->right);
			}
		}
	private:
		BinaryNode* root;								
};

int main(int argc, char** argv) 
{
	srand(time(0));
	BinaryTree* bst=new BinaryTree();
	int i,x;
	for(i=0;i<10;i++)
	{
		x=(rand()%30)+1;
		if(bst->find(x))
		{
			printf("The number to be added is on the tree,so a new number is generated");
			printf("(%d)\n",x);
			i--;
		}
		else
		{
			bst->Insert(x);
			printf("%d\n",x);
		}
	}
	printf("Displaying...\n");
	bst->DisplayTree(bst->getRoot());
	if(bst->findMax()==bst->find(bst->getRoot()->data))
	{
		printf("Equal\n");//Root is maximum value on the tree
	}
	bst->Delete(bst->getRoot()->data);
	bst->Delete(bst->findMin()->data);
	printf("Displaying...\n");
	bst->DisplayTree(bst->getRoot());
	
	return 0;
}
