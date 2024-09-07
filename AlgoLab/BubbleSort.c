#include<stdio.h>
#include<sys/time.h>
#include <cstdlib>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n; 
    }
}

int main(){
    struct timeval start, end;
    int datasizes[]={100,500,1000,5000,10000,25000,50000,100000};
    int temp;
    //int datasizes[]={100};

    FILE *file = fopen("plotBubbledata.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    int numSizes = sizeof(datasizes) / sizeof(datasizes[0]);

    for (int i = 0; i < numSizes; i++)
    {
    int size = datasizes[i];
       int *arr = (int*)malloc(size * sizeof(int));
        if (arr == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            return 1;
        }

        generateRandomArray(arr, size);
        // printf("Before sort:\n");
        // for (int k = 0; k < size; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\n");
        gettimeofday(&start, NULL);
     for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (arr[k] > arr[k + 1]) {
                    temp = arr[k];
                    arr[k] = arr[k + 1];
                    arr[k + 1] = temp;
                }
            }
        }
        gettimeofday(&end, NULL);

        // printf("After sort:\n");
        // for (int k = 0; k < size; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\n");

        // gettimeofday(&start, NULL);
        // bubble_sort(arr,n);
        long seconds = (end.tv_sec - start.tv_sec);
        long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

        fprintf(file, "%d %ld\n", size, micros);
        free(arr);

        printf("\nThe elapsed time is %d seconds and %d micros\n", seconds, micros);

    }


    
    fclose(file);
     int result = system("gnuplot plotBubbleSort.gnu");

    if (result == -1) {
        perror("Error running gnuplot");
    } else {
        printf("Plot generated successfully!\n");
    }

    return 0;
    return 0;
}