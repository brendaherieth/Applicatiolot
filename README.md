# Applicatiolot
This application is a lottery generation application for computer processes. The application contains a scheduler that predicts the next process to execute. Application starts with a list of processes where every process contains a unique ID and a list of tickets containing priorities.
The application decides the next process to execute by generating a random number between 1 and total number of tickets accross processes.
Finally we look through each process in the scheduler queue and for every process if it holds a ticket that corresponds to the random number generated we return that process as the one to execute next.
