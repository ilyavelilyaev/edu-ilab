#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define POWER_OF_EQUATION 2

double *solve1or2power (double *inp) {
	double *answers = (double *)malloc((POWER_OF_EQUATION + 1) * sizeof(double));
		
	if ((inp[0] == 0) && (inp[1] == 0))
	{
		printf("Not an equation\n");
	} else {
		if (inp[0] == 0)
		{
			answers[0] = 1;
			answers[1] = -inp[2]/inp[1];
		} else {
			double discriminant = inp[1] * inp[1] - 4 * inp[0] * inp [2];
			//printf ("D = %lg\n",discriminant);
			if (discriminant >= 0)
			{
				answers[0] = 2;
				answers[1] = (-inp[1] + sqrt(discriminant)) / (2 * inp[0]);
				answers[2] = (-inp[1] - sqrt(discriminant)) / (2 * inp[0]);
			} else {
				printf("D < 0\n");
			}
		}
	}
	return answers;
}

double *solve (double *inp) {
	double *answers = (double *)malloc((POWER_OF_EQUATION + 1) * sizeof(double));

	if (POWER_OF_EQUATION > 2)
	{
		printf("Function for solving equations with power more than 2 is not implemented\n");
	} else {
		answers = solve1or2power(inp);
	}
	return answers;
}

double *input () {
	printf("Enter factors a, b, c in equation of form ax^2 + bx + c = 0\n");
	double *inp = (double *)malloc((POWER_OF_EQUATION + 1) * sizeof(double));
	int k = 0, a = 0;
	for (int i = 0; i < POWER_OF_EQUATION + 1; i++)
	{
		scanf("%lg", &inp[i]);	
	}
	
	return inp;
}

void output (double *answers) {
	if (answers[0] != 0)
	{
		printf("%lg\n", answers[1]);
		for (int i = 2; i < answers[0] + 1; i++)
		{
			if (answers[i] != answers[i - 1])
			{
				printf("%lg\n", answers[i]);
			}
		
		}
	}
}

double *sort(double *answers) {
	double *answersSorted = (double *)malloc((answers[0] + 1) * sizeof(double));
	
	answersSorted = answers;

	if (answers[0] > 1)
	{
 		for(int x = 1; x < answers[0] + 1; x++)
		{
			for(int y=1; y < answers[0]; y++)
			{
				if(answersSorted[y]>=answersSorted[y+1])
				{
					double temp = answersSorted[y+1];
					answersSorted[y+1] = answersSorted[y];
					answersSorted[y] = temp;
				}
			}
		}
	}
	

	answersSorted[0] = answers[0];
	
	return answersSorted;
}

int repeat() {
	int s = 1;
	int p = -1;
	while ((p != 1) && (p != 2)) {
		printf("Do you want to solve one more equation? \n 1 - YES \n 2 - NO \n");
		scanf("%d", &p);
		if (p == 1)	s = 1; 
		if (p == 2)	s = 0;
	}
	return s;
}

int main() {
	int s = 1;
	while (s) {
		double *inp = (double *)malloc((POWER_OF_EQUATION + 1) * sizeof(double));
		inp = input();
		double *answers = (double *)malloc((POWER_OF_EQUATION + 1) * sizeof(double));
		answers = solve(inp);

		output(sort(answers));
		s = repeat();
	}
	return 0;
}