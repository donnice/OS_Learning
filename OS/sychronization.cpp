#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

bool lock;

bool test_and_set(bool *target); 
int compare_and_swap(int *val, int expected, int new_value);
void mutual_exclusion();
void bounded_waiting(int i, int j, int n, bool *waiting);

int main(int argc, char* argv[]) {
    return 0;
}

bool test_and_set(bool *target) {
    /* Mutex implementation with test_and_set */
    bool rv = *target;
    *target = true;

    return rv;
}

int compare_and_swap(int *value, int expected, int new_value) {
    /* Mutex implementation with compare_and_swap */
    int temp = *value;

    if(*value == expected)
        *value = new_value;

    return temp;
}

void mutual_exclusion() {
    do {
        while (test_and_set(&lock)) ; // do nothing
        /* critical section */
        lock = false;

        /* remainder section */
    } while(true);
}

void bounded_waiting(int i, int j, int n, bool *waiting) {
    do {
        waiting[i] = true;
        bool key = true;
        while(waiting[i] && key)
            key = test_and_set(&lock);
        waiting[i] = false;

        /* critical section */
        j = (i+1) % n; 
        while((j != i) && !waiting[j])
            j = (j+1)%n;

        if (j == i)
            lock = false;
        else
            waiting[j] = false;

            /* remainder section */       
    } while(true);
}