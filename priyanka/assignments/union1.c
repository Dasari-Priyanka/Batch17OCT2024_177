#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

// Union definition for Job
union Job {
   char name[32];         // 32 bytes
   unsigned short ucount; // 2 bytes
   float salary;          // 4 bytes
   int workerNo;          // 4 bytes
   char *orgname;         // 4 bytes (on a 32-bit system)
};

// Function to read and store the salary in the union
void store_salary(union Job *job, float salary) {
    job->salary = salary;  // Store salary in the union
}

// Function to read and store the worker number in the union
void store_workerNo(union Job *job, int workerNo) {
    job->workerNo = workerNo;  // Store workerNo in the union
}

// Function to print salary and workerNo
void print_job(union Job *job) {
    // Print the salary - It will print garbage if workerNo is written last
    printf("Salary: %.2f\n", job->salary);
    // Print the workerNo - It will print the correct value if it was written last
    printf("Worker No: %d\n", job->workerNo);
}

int main() {
    // Create an array of unions
    union Job uarr[10];  // Array of 10 unions

    // Step 1: Store salary in the first union of uarr
    store_salary(&uarr[0], 50000.0);

    // Step 2: Store worker number in the same union
    store_workerNo(&uarr[0], 1234);

    // Step 3: Print the salary and worker number
    printf("Printing Salary and Worker No in the order of Salary -> Worker No:\n");
    print_job(&uarr[0]);

    // Step 4: If we print salary first, it may show garbage due to being overwritten by workerNo
    printf("\nPrinting Worker No and Salary in the order of Worker No -> Salary:\n");
    print_job(&uarr[0]);

    return 0;
}

