#include <iostream>
#include <algorithm>
using namespace std;

void sjfScheduling(int processes[], int n, int burstTime[]) {
    int waitTime[n], turnAroundTime[n], totalWait = 0;
    int sortedProcesses[n], sortedBurst[n];

    for (int i = 0; i < n; i++) {
        sortedProcesses[i] = processes[i];
        sortedBurst[i] = burstTime[i];
    }

    sort(sortedBurst, sortedBurst + n);

    waitTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitTime[i] = sortedBurst[i - 1] + waitTime[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = sortedBurst[i] + waitTime[i];
    }

    cout << "SJF Scheduling:\n";
    cout << "Processes\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << sortedProcesses[i] << "\t\t" << sortedBurst[i] << "\t\t" << waitTime[i] << "\t\t" << turnAroundTime[i] << "\n";
    }
}
