#include <stdio.h>
#include <stdlib.h>
int request[50];
int SIZE, pre, head;
int up[50], down[50];
int uptrack, downtrack;
int dist(int a, int b) {
    return abs(a - b);
}
void sort(int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
    uptrack = downtrack = 0;
    for (i = 0; i < n; i++) {
        if (request[i] < head)
            down[downtrack++] = request[i];
        else if (request[i] > head)
            up[uptrack++] = request[i];
    }
}
void scan(int n) {
    int i, seekcount = 0;
    printf("SEEK SEQUENCE = ");
    sort(n);
    if (pre < head) {
        for (i = 0; i < uptrack; i++) {
            printf("%d ", up[i]);
            seekcount += dist(head, up[i]);
            head = up[i];
        }
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", down[i]);
            seekcount += dist(head, down[i]);
            head = down[i];
        }
    } else {
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", down[i]);
            seekcount += dist(head, down[i]);
            head = down[i];
        }
        for (i = 0; i < uptrack; i++) {
            printf("%d ", up[i]);
            seekcount += dist(head, up[i]);
            head = up[i];
        }
    }
    printf("\nTOTAL DISTANCE: %d\n", seekcount);
}
int main() {
    int n, i;
    printf("ENTER THE DISK SIZE:\n");
    scanf("%d", &SIZE);
    printf("ENTER THE NO OF REQUEST SEQUENCE:\n");
    scanf("%d", &n);
    printf("ENTER THE REQUEST SEQUENCE:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);
    printf("ENTER THE CURRENT HEAD:\n");
    scanf("%d", &head);
    request[n++] = 0;
    request[n++] = SIZE - 1;
    printf("ENTER THE PRE REQUEST:\n");
    scanf("%d", &pre);
    scan(n);
    return 0;
}
