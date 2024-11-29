#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <algorithm>

struct Process {
    int id;
    int arrivalTime;  // Час прибуття
    int burstTime;    // Час виконання
    int remainingTime; // Залишковий час виконання
    int priority;     // Пріоритет процесу
    int startTime;    // Час початку виконання
    int finishTime;   // Час завершення виконання
    int waitingTime;  // Час очікування
    int turnAroundTime; // Час обробки (waitingTime + burstTime)
    
    Process(int _id, int _arrivalTime, int _burstTime, int _priority)
        : id(_id), arrivalTime(_arrivalTime), burstTime(_burstTime),
          remainingTime(_burstTime), priority(_priority), startTime(-1), finishTime(-1),
          waitingTime(0), turnAroundTime(0) {}
};

// Випадкове генерування параметрів процесів
std::vector<Process> generateProcesses(int n) {
    std::vector<Process> processes;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> arrivalDist(0, 10);
    std::uniform_int_distribution<> burstDist(1, 10);
    std::uniform_int_distribution<> priorityDist(1, 5);
    
    for (int i = 0; i < n; ++i) {
        int arrivalTime = arrivalDist(gen);
        int burstTime = burstDist(gen);
        int priority = priorityDist(gen);
        processes.push_back(Process(i + 1, arrivalTime, burstTime, priority));
    }
    
    return processes;
}

// Алгоритм Round Robin
void roundRobin(std::vector<Process>& processes, int timeQuantum) {
    int time = 0;
    std::queue<Process*> readyQueue;
    std::vector<Process*> processesReady = processes;
    
    while (!processesReady.empty() || !readyQueue.empty()) {
        // Додаємо процеси, що прибули
        for (auto it = processesReady.begin(); it != processesReady.end(); ) {
            if (it->arrivalTime <= time) {
                readyQueue.push(&(*it));
                it = processesReady.erase(it);
            } else {
                ++it;
            }
        }
        
        if (!readyQueue.empty()) {
            Process* current = readyQueue.front();
            readyQueue.pop();
            
            if (current->startTime == -1) current->startTime = time;
            
            // Виконання процесу на квант часу
            int executionTime = std::min(current->remainingTime, timeQuantum);
            current->remainingTime -= executionTime;
            time += executionTime;
            
            if (current->remainingTime == 0) {
                current->finishTime = time;
                current->turnAroundTime = current->finishTime - current->arrivalTime;
                current->waitingTime = current->turnAroundTime - current->burstTime;
            } else {
                readyQueue.push(current);  // Повертаємо процес в чергу
            }
        } else {
            ++time; // Якщо черга пуста, час рухається вперед
        }
    }
    
    // Виведення результатів
    for (const auto& process : processes) {
        std::cout << "Process ID: " << process.id << " Arrival: " << process.arrivalTime
                  << " Burst: " << process.burstTime << " Priority: " << process.priority
                  << " Start: " << process.startTime << " Finish: " << process.finishTime
                  << " Waiting: " << process.waitingTime << " Turnaround: " << process.turnAroundTime << std::endl;
    }
}

// Алгоритм FCFS (First-Come-First-Served)
void fcfs(std::vector<Process>& processes) {
    int time = 0;
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });
    
    for (auto& process : processes) {
        if (process.arrivalTime > time) time = process.arrivalTime;  // Чекаємо на прибуття
        process.startTime = time;
        time += process.burstTime;
        process.finishTime = time;
        process.turnAroundTime = process.finishTime - process.arrivalTime;
        process.waitingTime = process.turnAroundTime - process.burstTime;
    }
    
    // Виведення результатів
    for (const auto& process : processes) {
        std::cout << "Process ID: " << process.id << " Arrival: " << process.arrivalTime
                  << " Burst: " << process.burstTime << " Start: " << process.startTime
                  << " Finish: " << process.finishTime << " Waiting: " << process.waitingTime
                  << " Turnaround: " << process.turnAroundTime << std::endl;
    }
}

// Алгоритм пріоритетного планування
void priorityScheduling(std::vector<Process>& processes) {
    int time = 0;
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority < b.priority || (a.priority == b.priority && a.arrivalTime < b.arrivalTime);
    });
    
    for (auto& process : processes) {
        if (process.arrivalTime > time) time = process.arrivalTime;  // Чекаємо на прибуття
        process.startTime = time;
        time += process.burstTime;
        process.finishTime = time;
        process.turnAroundTime = process.finishTime - process.arrivalTime;
        process.waitingTime = process.turnAroundTime - process.burstTime;
    }
    
    // Виведення результатів
    for (const auto& process : processes) {
        std::cout << "Process ID: " << process.id << " Arrival: " << process.arrivalTime
                  << " Burst: " << process.burstTime << " Priority: " << process.priority
                  << " Start: " << process.startTime << " Finish: " << process.finishTime
                  << " Waiting: " << process.waitingTime << " Turnaround: " << process.turnAroundTime << std::endl;
    }
}

// Функція для обчислення середнього часу очікування та обробки
void calculateAverageTimes(const std::vector<Process>& processes) {
    double totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (const auto& process : processes) {
        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnAroundTime;
    }
    
    std::cout << "Average Waiting Time: " << totalWaitingTime / processes.size() << std::endl;
    std::cout << "Average Turnaround Time: " << totalTurnaroundTime / processes.size() << std::endl;
}

int main() {
    int n = 5; // Кількість процесів
    std::vector<Process> processes = generateProcesses(n);
    
    std::cout << "Round Robin Scheduling (Time Quantum = 4):\n";
    roundRobin(processes, 4);
    calculateAverageTimes(processes);
    
    std::cout << "\nFCFS Scheduling:\n";
    fcfs(processes);
    calculateAverageTimes(processes);
    
    std::cout << "\nPriority Scheduling:\n";
    priorityScheduling(processes);
    calculateAverageTimes(processes);

    return 0;
}
