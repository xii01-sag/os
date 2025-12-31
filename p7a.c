#include <stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    int pointer = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    printf("\nRef String\tPage Frames\n");

    for (i = 0; i < n; i++) {
        avail = 0;
        for (j = 0; j < no; j++) {
            if (frame[j] == a[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
            frame[pointer] = a[i];
            pointer = (pointer + 1) % no;
            count++;
        }

        printf("%d\t\t", a[i]);
        for (j = 0; j < no; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", count);

    return 0;
}
