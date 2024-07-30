#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Time taken to sort for n = %d: %.6f seconds\n", n, timeTaken);
        fprintf(timeData, "%d %.6f\n", n, timeTaken);
    }

    fclose(timeData);

    return 0;
}
