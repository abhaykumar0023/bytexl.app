#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void findNextGreater(char number[]) {
    int len = strlen(number);

    int i;
    for (i = len - 2; i >= 0; i--) {
        if (number[i] < number[i + 1]) {
            break;
        }
    }

    if (i == -1) {
        printf("No greater number with the same set of digits exists.\n");
        return;
    }

    int j;
    for (j = len - 1; j > i; j--) {
        if (number[j] > number[i]) {
            break;
        }
    }

    swap(&number[i], &number[j]);

    int left = i + 1;
    int right = len - 1;
    while (left < right) {
        swap(&number[left], &number[right]);
        left++;
        right--;
    }

    printf("The smallest greater number with the same set of digits is: %s\n", number);
}

int main() {
    char number[20];
    printf("Enter a number: ");
    scanf("%s", number);

    findNextGreater(number);

    return 0;
}
