# Queue in Bedth First Search

The queue uses in bredth first search has largely been copied from the Queue which was implemented under `queue/lib/queue.c`.
As generic types can't be used, this first example of a queue was implemented with just `int` values for simplicity. A more practical use of queue's is here, where items in the queue are nodes in a tree.
Unfortunately, this does result in code duplication.
