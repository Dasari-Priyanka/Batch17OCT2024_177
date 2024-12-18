#include <stdio.h>

int main()
{
    int N, num;
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    printf("Enter the number of integers (N): ");
    while (1)
	{
        if (scanf("%d", &N) != 1 || N <= 0)
		{
            printf("Please enter a valid positive integer for N: ");
            while (getchar() != '\n');
        }
		else 
            break;
    }

    for (int i = 0; i < N; i++)
	{
        printf("Enter integer %d: ", i + 1);
        while (1) 
		{
            if (scanf("%d", &num) != 1) 
			{
                printf("Invalid input! Please enter an integer: ");
                while (getchar() != '\n');  // Discard invalid input
            }
			else 
                break;
        }

        if (num > 0)
            positiveCount++;
        else if (num < 0) 
            negativeCount++;
        else 
            zeroCount++;
    }

    printf("\nSummary:\n");
    printf("Positive numbers: %d\n", positiveCount);
    printf("Negative numbers: %d\n", negativeCount);
    printf("Zeros: %d\n", zeroCount);

    return 0;
}
