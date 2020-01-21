#include <stdio.h>
#include <stdlib.h>

float calcMean(float nums[])
{
	float sum=0;
	float len=10;
	for(int i=0; i<len; i++)
	{
		sum=sum+nums[i];
	}
	sum=sum/len;
	return sum;
}
void merge(float nums[], int l, int m, int r)
{
	int lefti=0;
	int righti=0;
	int maini=l;
	int leftlen=m-l+1;
	int rightlen=r-m;
	float leftNums[leftlen];
	float rightNums[rightlen];
	for(int i=0; i<leftlen; i++)
	{
		leftNums[i]=nums[l+i];
	}
	for(int i=0; i<rightlen; i++)
	{
		rightNums[i]=nums[m+1+i];
	}
	while(lefti<leftlen && righti<rightlen)
	{
		if(leftNums[lefti]<=rightNums[righti])
		{
			nums[maini]=leftNums[lefti];
			lefti++;
			maini++;
		}
		else
		{
			nums[maini]=rightNums[righti];
                        righti++;
                        maini++;
		}

	}
	while(lefti<leftlen)
	{
                        nums[maini]=leftNums[lefti];
                        lefti++;
                        maini++;
	}
	while(righti<rightlen)
	{
                        nums[maini]=rightNums[righti];
                        righti++;
                        maini++;
	}
}
void sortNums(float nums[], int l, int r)
{
	int m=l+(r-l)/2;
	if(l<r)
	{
		sortNums(nums, l, m);
		sortNums(nums, m+1, r);
		merge(nums, l, m, r); 
	}
}
void printNums(float nums[])
{
        for(int i=0; i<10; i++)
        {
                printf("%.2f ", nums[i]);
        }
        printf("\n");
}
int main(int argc, char* argv[])
{
        char input[256];
        float nums[10];
        if(argc==11)
        {
		for(int i=0; i<10; i++)
		{
			nums[i]=atof(argv[i+1]);
		}
        }
	float mean=calcMean(nums);
	printf("The mean is %f\n", mean);
	sortNums(nums, 0, 10);
	printNums(nums);
}
