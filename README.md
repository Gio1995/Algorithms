# Algorithms
In this repository the are the most famous programming algorithms studied during Operating System course (updating):

-Dekker: 
Algorithm to implement critical section without the use of the semaphores. This is the first solution to implement the critical section without livelock and deadlock.

-Peterson:
Algorithm to implement critical section without the use of the semaphores. This is a simpler solution than Dekker algorithm using an array of boolean flags which contain a flag for each process (thread).

-Eisenberg and McGuire:
Algorithm to implement critical section without the use of the semaphores. This algorithm implement an array flags of type "enum state" where each cell can take three values: IDLE, WAITING and ACTIVE. Each process decides to set, using these values, its own status.
