#include "schedulers.h"

using namespace std;

/*
Creates a priority queue that orders based on task->burst
Priority is ranked from smallest to largest value 
*/
queue<task*> task_list; 
int currId = 0;

int slice = 10; //the time quantum is set to 10 based on what the instructions said

void add(string name, int priority, int burst){
	struct task* next_task = new struct task();
	next_task->name = name;
	next_task->tid = currId;
	next_task->priority = priority;
	next_task->burst = burst;

	task_list.push(next_task); //push the task onto the priority queue
	
	++currId;
}

void schedule(){
	while(task_list.size() != 0){
		struct task* next_task = task_list.front(); //peek the top of the queue and store it in the struct
		task_list.pop(); //removes the task from the front of the queue
		
		if (next_task->burst > slice){
			run(next_task, slice);
			next_task->burst -= slice; //decrement the burst value by 10 
			task_list.push(next_task);//add to the end of the queue
		} else {
			run(next_task, next_task->burst);//run the task
			cout << "\tFinished task " << next_task->name << endl;
			delete next_task;
		}
	}
}