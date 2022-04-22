#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void sortingOperation(int numbers[])
{
	int i,j,number;
	for(i=1;i<10;i++)
	{
		number=numbers[i];
		for(j=i-1;j>=0&&number<numbers[j];j--)
		{
			numbers[j+1]=numbers[j];
		}
		numbers[j+1]=number;
	}
	for(i=0;i<10;i++)
	{
		printf("%d",numbers[i]);
		printf("\n");		
	}
}
int main(int argc, char** argv) 
{
	int numbers[]={5,158,3,53,45,1,97,41,13,32};
    sortingOperation(numbers);
	return 0;
}

