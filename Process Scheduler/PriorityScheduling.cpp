#include <iostream>
using namespace std;

void priorityScheduling(int processes[], int n, int burstTime[], int priority[]) {
    int waitTime[n], turnAroundTime[n];
    int p[n], bt[n], pr[n];

    for (int i = 0; i < n; i++) {
        p[i] = processes[i];
        bt[i] = burstTime[i];
        pr[i] = priority[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    waitTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitTime[i] = bt[i - 1] + waitTime[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = bt[i] + waitTime[i];
    }

    cout << "Priority Scheduling:\n";
    cout << "Processes\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t\t" << bt[i] << "\t\t" << pr[i] << "\t\t" << waitTime[i] << "\t\t" << turnAroundTime[i] << "\n";
    }
}
