/**
 * Representation of a task in the system.
 */

#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

// representation of a task
typedef struct task {
    string name;
    int tid;
    int priority;
    int burst;
} Task;

#endif
