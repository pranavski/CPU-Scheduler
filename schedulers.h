#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include "task.h"
#include "cpu.h"
#include <queue>
#include <iostream>

using namespace std;

// add a task to the list 
void add(string name, int priority, int burst);

// invoke the scheduler
void schedule();
