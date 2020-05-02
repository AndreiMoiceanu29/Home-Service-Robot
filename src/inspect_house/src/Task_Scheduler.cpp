#include "Task_Scheduler.h"
#include <stack>
#include <cstdio>

Task_Scheduler::Task_Scheduler(){
	printf("Scheduler created!\n");
}

Task_Scheduler::~Task_Scheduler(){
	printf("Scheduler destroyed\n");
}

void Task_Scheduler::pushJob(Job job){
	this->manager.push(job);
}
void Task_Scheduler::terminateJob(){
	this->manager.pop(job);
}
Job Task_Scheduler::getCurrentJob(){
	return this->manager.top();
}
