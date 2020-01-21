
#include <stdio.h>
#include <stdlib.h>
float areaOfCircle( float r )
{
	return 3.14*r*r;
}
int main(int argc, char* argv[])
{
	char input[256];
	float r1=0;
	float r2=0;
	if(argc==3)
	{
		r1=atof(argv[1]);
		r2=atof(argv[2]);
	}
	if(r1>=1 && r1<=100 && r2>=1 && r2<=100)
	{
		if(r2<r1)
		{
			float dum=0;
			dum=r1;
			r1=r2;
			r2=dum;
		}
	}
	else
	{

	printf("You will be entering two numbers to specify the range of the radii.\n");
	printf("Both numbers in the range should be within 1 to 100. Enter the minimum radius: \n");
	
	while(1)
	{
		fgets(input, 256, stdin);
		if (sscanf(input, "%f", &r1)==1 && r1>=1 && r1<=100) break;
		printf("Not a valid minimum radius from 1 to 100- try again!\n");
	} 
	printf("Now enter the maximum radius (greater than the minimum): \n");
	while(1)
	{
		fgets(input, 256, stdin);
		if (sscanf(input, "%f", &r2)==1 && r2>=r1 && r2<=100) break;
		printf("Not a validmaximum radius from %f to 100- try again!\n", r1);
	}
	}
	float r;
	for(float i=r1; i<=r2; i++)
	{
		r = i;
		printf("Circle of radius %f has area %f\n", r, areaOfCircle(r) );
	}
} 
