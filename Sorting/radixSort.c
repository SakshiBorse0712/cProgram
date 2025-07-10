#include <stdio.h>

#define SIZE 10

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int size, int place) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, size, place);
    }
}

int main() {
    int arr[SIZE];
    
    printf("Enter 10 integers: \n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, SIZE);

    printf("Sorted array: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
