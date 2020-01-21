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
}
