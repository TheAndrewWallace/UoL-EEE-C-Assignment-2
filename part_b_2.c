#include <stdio.h>

/*Functions used in program*/
float mean(float nums, int end);
float minus1(float currentnum, float avg_x);
float kurtosis(float totalfinal, float last);
float calckurtosis(float totalfinal, float totalfinal2);

/*Main function*/
void main(void)
{
	int i, last = 10, j;
	float your_nums[10];
	float a, avg_x, total = 0, currentnum, finx, final, final2, totalfinal = 0.0, totalfinal2 = 0, complete1, complete2, kurtosisfinal = 0.0;
	
	/*Part 1*/
	for(i=0; i < 10; i++)
	{
		printf("Enter number (or negative to end): ");
		scanf("%f", &a);
		if(a <= 0)
		{
			last = i;
			i = 10;
		}
		fflush(stdin);
		*(your_nums + i) = a;
	}
	
	/*Part 2*/
	for(i=0; i < last; i++)
	{
		total = total + *(your_nums + i);
	}

	
	/*Part 3*/
	
	for(i=0; i<last; i++)
	{
		avg_x = mean(total, last);
	}

	
	/*Part 4*/
	for(i=0; i<last; i++)
	{
		currentnum = *(your_nums+i);
		finx = minus1(currentnum, avg_x);
		final = 0.0;
		final2 = 0.0;
		
		totalfinal = totalfinal + finx*finx*finx*finx;
		
		totalfinal2 = totalfinal2 + finx*finx;
	}
	
	
	/*part 5*/
	complete1 = kurtosis(totalfinal, last);
	complete2 = kurtosis(totalfinal2, last);
	
	/*Part 6*/
	kurtosisfinal = calckurtosis(complete1, complete2);
	
	/*Part 7*/
	for(i=0; i<last; i++)
	{
		printf("\nThe value of %d = %f", i + 1, *(your_nums + i));
	}
	
	printf("\n-----------\nFinal result: %f", kurtosisfinal);
}

float mean(float nums, int end)
{
	float result, div;
	div = end;
	result = 1 / div;
	result = result * nums;
	return result;
}

float minus1(float currentnum, float avg_x)
{
	float result = 0;
	result = currentnum - avg_x;
	return result;
}

float kurtosis(float totalfinal, float end)
{
	float result, div;
	div = end;
	result = 1 / div;
	result = result * totalfinal;
	return result;
}

float calckurtosis(float totalfinal, float totalfinal2)
{
	float result, result1;
	result1 = totalfinal2 * totalfinal2;
	result = totalfinal / result1;
	return result;
}
