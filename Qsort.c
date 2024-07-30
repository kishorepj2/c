#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    FILE *timeData;
    timeData = fopen("time_complexity_data.txt", "w");
    if (timeData == NULL) 
    {
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
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Time taken to sort for n = %d: %.6f seconds\n", n, timeTaken);
        fprintf(timeData, "%d %.6f\n", n, timeTaken);
    }

    fclose(timeData);

    return 0;
}
