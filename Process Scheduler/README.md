
# Process Scheduling Algorithms in C++

Welcome to the **Process Scheduling Algorithms in C++** repository! This project contains implementations of various process scheduling algorithms commonly used in operating systems.

## Project Overview

This repository showcases the following process scheduling algorithms:
- First-Come, First-Served (FCFS)
- Shortest Job First (SJF)
- Round Robin Scheduling
- Priority Scheduling

Each algorithm is implemented in its own file for clarity and modularity.

## How to Get Started

1. **Clone this repository**.
2. **Compile the master program**:
   g++ SchedulingMaster.cpp FCFS.cpp SJF.cpp RoundRobin.cpp PriorityScheduling.cpp -o scheduler
3. **Run the program**:
   ./scheduler

## Usage

- Input the number of processes and their respective burst times and priorities.
- Choose a scheduling algorithm or let the system suggest the best one based on burst time variation.

## Contribution Guidelines

- Feel free to fork the repository and submit a pull request with improvements or new features!
- Ensure your code is well-documented and follows best practices.

## License

This project is licensed under the MIT License.

