#include <stdio.h>
#include <stddef.h>

struct Job {
   char name[32];
   unsigned short ucount;  // 2 bytes
   float salary;           // 4 bytes
   int workerNo;           // 4 bytes
   char *orgname;          // 4 bytes
};

int main() {
    struct Job myvar;
    char *ptr = (char *)&myvar;  // ptr points to the base address of myvar

    // Method 1: Using base address of ucount
    *(ptr + offsetof(struct Job, ucount)) = 0x01;  // Place 0x01 at the first byte of ucount
    *(ptr + offsetof(struct Job, ucount) + 1) = 0x02;  // Place 0x02 at the second byte of ucount

    // Method 2: Using relative address of ucount
    *((unsigned short *)(ptr + offsetof(struct Job, ucount))) = 0x0102;  // Place 0x0102 in ucount

    // To verify
    printf("ucount: %x\n", myvar.ucount);  // Should print 0x0102

    return 0;
}

