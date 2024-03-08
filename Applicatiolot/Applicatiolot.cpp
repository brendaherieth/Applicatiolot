#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Process {
private:
    int identifier; // Identifier for a process
    std::vector<int> tickets; // a list of tickets in the process  

public:
    // Default initializer
    Process(int ID, const std::vector<int>& list) : identifier(ID), tickets(list) {}

    // A function to return the identifier of process
    int getIdentifier() const { return identifier; }

    // A public to return all the tickets in process
    std::vector<int>& getAllTickets() { return tickets; }
};

class Scheduler {
private:
    std::vector<Process> allProcesses;
    int ticketsSum;

public:
    Scheduler() : ticketsSum(0) {}

    // This function adds a new process to the queue of processes in the scheduler
    void addProcess(Process& process) {
        allProcesses.push_back(process); // Adds new process to process list

        for (int ticket : process.getAllTickets()) { // Adds the total ticket of each process into our tickets sum
            ticketsSum += ticket;
        }
    }
    // A function to allocate lottery tickets
    void allocateLotteryTickets() {
        for (auto& process : allProcesses) { // Iterating through all processes in scheduler process queue
            std::vector<int>& allProcessTickers = process.getAllTickets();
            for (int& ticket : allProcessTickers) { // iterating through the tickets in each process
                if (ticket > 1) {
                    ticket = ticket;
                }
                else {
                    ticket = 1;
                }
            }
        }
    }

    // The function to select the next process using the random number generator
    const Process* findNextProcess() {
        // Generate random ticket
        int randomTicket = rand() % ticketsSum + 1;

        // Check which process has a ticket that matches the generated randomTicket
        for (auto& process : allProcesses) {
            for (int ticketInProcess : process.getAllTickets()) {
                if (randomTicket <= ticketInProcess) { // check to see if ticket matches with random ticket generated
                    return &process;
                }
                randomTicket -= ticketInProcess;
            }
        }
        return nullptr;
    }

};

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time

    // Example usage with new test processes
    Process process1(1, { 8, 4, 2 });
    Process process2(2, { 5, 3, 1 });
    Process process3(3, { 10 });

    Scheduler scheduler;
    scheduler.addProcess(process1);
    scheduler.addProcess(process2);
    scheduler.addProcess(process3);

    scheduler.allocateLotteryTickets();

    const Process* nextProcess = scheduler.findNextProcess();
    if (nextProcess) {
        std::cout << "Process: " << nextProcess->getIdentifier() << " executes next!" << std::endl;
    }
    else {
        std::cout << "No process won and selected." << std::endl;
    }

    return 0;
}
