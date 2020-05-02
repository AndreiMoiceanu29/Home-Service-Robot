#include<ros/ros.h>
#include<move_base_msgs/MoveBaseAction.h>
#include<actionlib/client/simple_action_client.h>
#include<tf/tf.h>

// Define a client for to send goal requests to the move_base server
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char **argv)
{
	/* code */
	ros::init(argc,argv,"pick_objects");
    double x_goal[] = {4.23,3.74,1.54,0.17,-2.10,-1.55,-0.15};
    double y_goal[] = {-0.10,2.34,1.74,1.93,2.03,-2.63,-0.34};
    int num_pts = sizeof(x_goal)/sizeof(double);
    double bin_location[] = {x_goal[num_pts-1],y_goal[num_pts-1]};
	MoveBaseClient ac("move_base",true);

    while(!ac.waitForServer(ros::Duration(5.0))){
    	ROS_INFO("Waiting for the move_base action server to come up!");
    }

    move_base_msgs::MoveBaseGoal goal;

    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    for(int i = 0; i< num_pts; i++){
        goal.target_pose.pose.position.x = x_goal[i];
        goal.target_pose.pose.position.y = y_goal[i];
        goal.target_pose.pose.orientation = tf::createQuaternionMsgFromYaw(3.14);

        ROS_INFO("Sending goal");
        ac.sendGoal(goal);
        ac.waitForResult();

        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
            ROS_INFO("The robot reached it's destination!");
        } else{
            ROS_INFO("The robot couldn't reach it's destination!");
        }

    //Wait 5 secs
        ros::Duration(5.0).sleep();
        ROS_INFO("Moving to the next destination!");
    }
    ROS_INFO("Inspection complete!");

	return 0;
}
