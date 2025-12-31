#include <stdio.h>

int main() {
    int fragment[20], b[20], p[20];
    int barray[20] = {0}, parray[20] = {0};
    int nb, np, temp, lowest;
    int i, j;

    printf("\n\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process no.%d: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= np; i++) {
        lowest = 9999;
        parray[i] = -1;
        for (j = 1; j <= nb; j++) {
            if (barray[j] == 0) {
                temp = b[j] - p[i];
                if (temp >= 0 && temp < lowest) {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        if (parray[i] != -1) {
            fragment[i] = b[parray[i]] - p[i];
            barray[parray[i]] = 1;
        } else {
            fragment[i] = -1;
        }
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= np; i++) {
        if (parray[i] != -1)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i, p[i], parray[i], b[parray[i]], fragment[i]);
        else
            printf("\n%d\t\t%d\t\tNot Allocated\t-\t\t-", i, p[i]);
    }

    return 0;
}
