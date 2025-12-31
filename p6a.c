#include <stdio.h>

int main() {
    int fragments[10], blocks[10], files[10];
    int block_arr[10] = {0}, file_arr[10];
    int number_of_blocks, number_of_files;
    int m, n, temp, top;

    printf("Enter the Total Number of Blocks: ");
    scanf("%d", &number_of_blocks);

    printf("Enter the Total Number of Files: ");
    scanf("%d", &number_of_files);

    printf("\nEnter the Size of the Blocks:\n");
    for (m = 0; m < number_of_blocks; m++) {
        printf("Block No.[%d]: ", m + 1);
        scanf("%d", &blocks[m]);
    }

    printf("\nEnter the Size of the Files:\n");
    for (m = 0; m < number_of_files; m++) {
        printf("File No.[%d]: ", m + 1);
        scanf("%d", &files[m]);
    }

    for (m = 0; m < number_of_files; m++) {
        top = -1;
        file_arr[m] = -1;
        for (n = 0; n < number_of_blocks; n++) {
            if (block_arr[n] == 0) {
                temp = blocks[n] - files[m];
                if (temp >= 0) {
                    if (temp > top) {
                        file_arr[m] = n;
                        top = temp;
                    }
                }
            }
        }
        if (file_arr[m] != -1) {
            fragments[m] = blocks[file_arr[m]] - files[m];
            block_arr[file_arr[m]] = 1;
        } else {
            fragments[m] = -1; // not allocated
        }
    }

    printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
    for (m = 0; m < number_of_files; m++) {
        if (file_arr[m] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   m + 1, files[m], file_arr[m] + 1,
                   blocks[file_arr[m]], fragments[m]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t-\t\t-", m + 1, files[m]);
        }
    }
    printf("\n");

    return 0;
}
