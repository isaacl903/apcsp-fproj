#include <stdio.h>

void arrayAdd(int arr[], int s, int n)
{
	for (int i=0; i<s; i++)
	{
		arr[i]+=n;
	}
}

int main()
{
	int arr[100];
	for (int i=0; i<100; i++)
	{
		arr[i]=i*i;
	}
	printf("3rd element of index 2 is %d\n", arr[2]);
	arrayAdd(arr, 100, 8);
	printf("3rd element of index 2 after adding 8 to every element is %d\n", arr[2]);

}
