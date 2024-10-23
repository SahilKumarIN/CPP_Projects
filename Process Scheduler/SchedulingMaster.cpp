#include <iostream>
#include "FCFS.cpp"
#include "SJF.cpp"
#include "RoundRobin.cpp"
#include "PriorityScheduling.cpp"

using namespace std;

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n], burstTime[n], priority[n];
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTime[i];
        cout << "Enter priority for process " << i + 1 << ": ";
        cin >> priority[i];
    }

    cout << "Choose an option: " << endl;
    cout << "1. Select a scheduling algorithm" << endl;
    cout << "2. Let the system suggest the best algorithm" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Choose a scheduling algorithm: " << endl;
        cout << "1. FCFS" << endl;
        cout << "2. SJF" << endl;
        cout << "3. Round Robin" << endl;
        cout << "4. Priority Scheduling" << endl;

        int algoChoice;
        cin >> algoChoice;

        switch (algoChoice) {
            case 1:
                fcfsScheduling(processes, n, burstTime);
                break;
            case 2:
                sjfScheduling(processes, n, burstTime);
                break;
            case 3:
                cout << "Enter time quantum for Round Robin: ";
                cin >> quantum;
                roundRobinScheduling(processes, n, burstTime, quantum);
                break;
            case 4:
                priorityScheduling(processes, n, burstTime, priority);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } else if (choice == 2) {
        int maxBurst = burstTime[0], minBurst = burstTime[0];
        for (int i = 1; i < n; i++) {
            if (burstTime[i] > maxBurst) maxBurst = burstTime[i];
            if (burstTime[i] < minBurst) minBurst = burstTime[i];
        }

        if (maxBurst - minBurst > 10) {
            cout << "System suggests: SJF Scheduling" << endl;
            sjfScheduling(processes, n, burstTime);
        } else {
            cout << "System suggests: FCFS Scheduling" << endl;
            fcfsScheduling(processes, n, burstTime);
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
