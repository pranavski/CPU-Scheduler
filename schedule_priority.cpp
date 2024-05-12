#include "schedulers.h"

using namespace std;

/*
Creates a priority queue that orders based on task->priority
Priority is ranked from largest to smallest value 
*/
priority_queue< pair<int, task*> > task_list; 
int currId = 0;

void add(string name, int priority, int burst){
	struct task* next_task = new struct task();
	next_task->name = name;
	next_task->tid = currId;
	next_task->priority = priority;
	next_task->burst = burst;

    task_list.push(make_pair(priority, next_task)); //push the task onto the priority queue
	
	++currId;
}

void schedule(){
	while(task_list.size() != 0){
		struct task* next_task = task_list.top().second; //peek the top of the queue and store it in the struct
		task_list.pop(); //removes the task from the front of the queue
		run(next_task, next_task->burst);
        cout << "\tFinished task " << next_task->name << endl;
		delete next_task;
	}
}