#include "schedulers.h"

using namespace std;


/*
create a queue that stores all the tasks
*/
queue<task*> task_list;
int currId = 0;

void add(string name, int priority, int burst){
	struct task* next_task = new struct task();
	next_task->name = name;
	next_task->tid = currId;
	next_task->priority = priority;
	next_task->burst = burst;

	task_list.push(next_task); //push task onto queue
	++currId;
}

void schedule(){
	while(task_list.size() != 0){
		struct task* next_task = task_list.front(); //peek the front to store the task
		task_list.pop(); //removes the task from the front of the queue
		run(next_task, next_task->burst);
		cout << "\tFinished task " << next_task->name << endl;
		delete next_task;
	}
}