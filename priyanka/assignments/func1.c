#include <stdio.h>
#include <string.h>

void sortCharArray(char arr[], int n)
{
    char temp;
	int i,j;
    for (i = 0; i < n-1; i++)
	{
        for (j = 0; j < n-i-1; j++)
		{
            if (arr[j] > arr[j+1])
			{
                // Swap the characters
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

#define SORT_CHAR_ARRAY(arr) sortCharArray(arr, strlen(arr))

int main()
{
    char str[] = "dbca";
    printf("Before sorting: %s\n", str);
    
    SORT_CHAR_ARRAY(str);
    
    printf("After sorting: %s\n", str);
    
    return 0;
}

