#include <stdio.h>

void printNGE(int arr[], int size) {
    int nextGreater[size];
    int stack[size];
    
    for (int i = 0; i < size; i++) {
        nextGreater[i] = -1;
    }
    
    int top = -1;
    
    for (int i = 0; i < size; i++) {
        while (top >= 0 && arr[i] > arr[stack[top]]) {
            nextGreater[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }
    
    for (int i = 0; i < size; i++) {
        printf("NGE for %d = %d\n", arr[i], nextGreater[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Next Greater Elements:\n");
    printNGE(arr, size);
    
    return 0;
}
