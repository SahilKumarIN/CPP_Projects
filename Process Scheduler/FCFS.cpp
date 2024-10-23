#include <iostream>
using namespace std;

void fcfsScheduling(int processes[], int n, int burstTime[]) {
    int waitTime[n], turnAroundTime[n];
    waitTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitTime[i];
    }

    cout << "FCFS Scheduling:\n";
    cout << "Processes\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitTime[i] << "\t\t" << turnAroundTime[i] << "\n";
    }
}
