#include <string>
#include <stdlib.h>
using namespace std;

class Job
{
public:
	virtual void setName(String name) = 0;

protected:
	string name;
	bool is_done
};

class Inspector: public Job{
private:
	double x_dropoff;
	double y_dropoff;
public:
	void setName(String name){
		this->name = name;
	}
	void hasDropped(double x, double y){
		double eps = 1e-2;
		if(fabs(x - x_dropoff) <= eps && fabs(y - y_dropoff) <= eps){
			this->is_done = true;
		}else{
			this->is_done = false;
		}
	}
}

class Collector: public Job{
private:
	int current_idx = 0;
	double x_goal[];
	double y_goal[];
public:
	void setName(String name){
		this->name = name;
	}
	int getCurrentWp(){
		return(this->x_goal[this->current_idx],this->y_goal[this->current_idx]);
	}
	void completedExecution(double x, double y){
		if(current_idx == sizeof(x_goal)/sizeof(double)){
			is_done = true;
		} else{
			is_done = false;
		}
	}

	void setGoals(double x_goal[], double y_goal[]){
		this->x_goal = x_goal;
		this->y_goal = y_goal;
	}
}