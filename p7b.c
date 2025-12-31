#include <stdio.h>

int i, j, nof, nor, flag = 0, ref[50], frm[10], pf = 0, victim = -1;
int recent[50], lrucal[10], count = 0;

int lruvictim();

int main() {
    printf("\nLRU PAGE REPLACEMENT ALGORITHM\n");
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    printf("Enter number of reference string elements: ");
    scanf("%d", &nor);

    printf("Enter reference string:\n");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    for (i = 0; i < nof; i++) {
        frm[i] = -1;
        lrucal[i] = 0;
    }
    for (i = 0; i < 50; i++)
        recent[i] = -1;

    printf("\nReference String: ");
    for (i = 0; i < nor; i++)
        printf("%d ", ref[i]);
    printf("\n");

    for (i = 0; i < nor; i++) {
        flag = 0;
        for (j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            if (count < nof) {
                victim = count;
            } else {
                victim = lruvictim();
            }
            frm[victim] = ref[i];
            pf++;
            count++;
        }

        recent[ref[i]] = i;

        printf("Ref %d -> ", ref[i]);
        for (j = 0; j < nof; j++) {
            if (frm[j] != -1)
                printf("%d ", frm[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pf);

    return 0;
}

int lruvictim() {
    int i, temp1;
    int minIndex = 0;

    for (i = 0; i < nof; i++) {
        temp1 = frm[i];
        lrucal[i] = recent[temp1];
    }

    for (i = 1; i < nof; i++) {
        if (lrucal[i] < lrucal[minIndex])
            minIndex = i;
    }

    return minIndex;
}
