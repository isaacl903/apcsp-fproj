#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
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
float calcMedian(float nums[])
{
	sortNums(nums, 0, 9);
	float median=(nums[4]+nums[5])/2.0;
	return median;
}
void printNums(float nums[])
{
        for(int i=0; i<10; i++)
        {
                printf("%.2f ", nums[i]);
        }
        printf("\n");
}
float calcMode(float nums[])
{
	return 1.0;
}
float calcStandardDeviation(float nums[], float mean)
{
	float out;
	for(int i=0; i<10; i++)
	{
		out=out+(nums[i]-mean)*(nums[i]-mean);
	}
	out=out/10;
	return out;
}
