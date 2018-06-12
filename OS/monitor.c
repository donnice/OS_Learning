// #include <stdio.h>

// monitor DiningPhilosophers {
//     enum {THINKING, HUNGERY, EATING} state[5];
//     condition self[5];

//     void pickup(int i) {
//         state[i] = HUNGERY;
//         test(i);
//         if(state[i] != EATING)
//             self[i].wait();
//     }

//     void putdown(int i) {
//         state[i] = THINKING;
//         test((i+4)%5);
//         test((i+1)%5);
//     }

//     void test(int i) {
//         if((state[(i+4)%5] != EATING) && (state[i] == HUNGERY) && (state[(i+1)%5] != EATING))
//         {
//             state[i] = EATING;
//             self[i].signal();
//         }
//     }

//     initialization_code() {
//         for(int i = 0; i < 5; i++) {
//             state[i] = THINKING;
//         }
//     }
// }