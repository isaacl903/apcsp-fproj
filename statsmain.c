#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stats.h"
#include <math.h>
int main(int argc, char* argv[])
{
        float nums[10];
        if(argc==11)
        {
                for(int i=0; i<10; i++)
                {
                        nums[i]=atof(argv[i+1]);
                }
        }
        float mean=calcMean(nums);
        printf("The mean is %.2f\n", mean);
        float median=calcMedian(nums);
        printf("The median is %.2f\n", median);
        printNums(nums);
	float mode=calcMode(nums);
	printf("The mode is %.2f\n", mode);
	float standardDeviation=calcStandardDeviation(nums, mean);
	printf("The standard deviation is %.2f\n", standardDeviation);
}


