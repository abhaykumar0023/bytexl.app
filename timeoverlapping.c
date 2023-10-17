#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

void mergeIntervals(struct Interval intervals[], int n) {
    if (n <= 0) return;
    qsort(intervals, n, sizeof(struct Interval), compare);
    struct Interval result[n];
    result[0] = intervals[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        struct Interval current = intervals[i];
        struct Interval previous = result[index];

        if (current.start <= previous.end) {
            result[index].end = (current.end > previous.end) ? current.end : previous.end;
        } else {
            index++;
            result[index] = current;
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("(%d, %d) ", result[i].start, result[i].end);
    }
}

int main() {
    struct Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    mergeIntervals(intervals, n);
    return 0;
}
