#include <stack>

class Task_Scheduler
{
private:
	std::stack<Job>manager;
	bool is_done;
public:
	Task_Scheduler();
	~Task_Scheduler();
	void pushJob(Job job);
	void terminateJob();
	Job getCurrentJob();
	
};