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

	MoveBaseClient ac("move_base",true);

    while(!ac.waitForServer(ros::Duration(5.0))){
    	ROS_INFO("Waiting for the move_base action server to come up!");
    }

    move_base_msgs::MoveBaseGoal goal;

    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = 2.93;
    goal.target_pose.pose.position.y = 0.05;
    goal.target_pose.pose.orientation = tf::createQuaternionMsgFromYaw(1.57);

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    	ROS_INFO("The robot reached it's destination!Picking up object");
    } else{
    	ROS_INFO("The robot couldn't reach it's destination!");
    }

    //Wait 5 secs
    ROS_INFO("Picking up object");
    ros::Duration(5.0).sleep();
    ROS_INFO("Object picked up, moving to drop off zone!");

    goal.target_pose.pose.position.x = -1.5;
    goal.target_pose.pose.position.y = 7.57;
    goal.target_pose.pose.orientation = tf::createQuaternionMsgFromYaw(1.57);

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    	ROS_INFO("The robot reached it's destination!Dropping the object !");
    } else{
    	ROS_INFO("The robot couldn't reach it's destination!");
    }



	return 0;
}
