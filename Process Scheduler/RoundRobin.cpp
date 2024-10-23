#include <iostream>
using namespace std;

void roundRobinScheduling(int processes[], int n, int burstTime[], int quantum) {
    int remainingBurst[n], waitTime[n] = {0}, turnAroundTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = burstTime[i];
    }

    int currentTime = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (remainingBurst[i] > 0) {
                done = false;  // There is still a process pending
                if (remainingBurst[i] > quantum) {
                    currentTime += quantum;
                    remainingBurst[i] -= quantum;
                } else {
                    currentTime += remainingBurst[i];
                    waitTime[i] = currentTime - burstTime[i];
                    remainingBurst[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitTime[i];
    }

    cout << "Round Robin Scheduling:\n";
    cout << "Processes\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitTime[i] << "\t\t" << turnAroundTime[i] << "\n";
    }
}
