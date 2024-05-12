/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>
#include <iostream>

#include "cpu.h"
#include "task.h"

// run this task for the specified time slice
void run(Task *task, int slice) {
    cout << "Running task = [" << task->name << "] [";
    cout << task->priority << "] [" << task->burst << "] for ";
    cout << slice << " units." << endl;
}
