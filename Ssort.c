#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    FILE *timeData;
    timeData = fopen("time_complexity_data.txt", "w");
    if (timeData == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int nValues[] = {1000, 2000, 3000, 4000, 5000};
    int numNValues = sizeof(nValues) / sizeof(nValues[0]);

    for (int i = 0; i < numNValues; ++i) 
    {
        int n = nValues[i];
        int arr[n];

        srand(time(NULL));
        for (int j = 0; j < n; ++j) 
        {
            arr[j] = rand() % 1000;
        }

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Time taken to sort for n = %d: %.6f seconds\n", n, timeTaken);
        fprintf(timeData, "%d %.6f\n", n, timeTaken);
    }

    fclose(timeData);

    return 0;
}
