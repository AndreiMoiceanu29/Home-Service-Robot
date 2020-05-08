#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
//TODO: Include the ball_chaser "DriveToTarget" header file

//ROS::Publisher motor comands.
ros::Publisher motor_command_publisher;
bool handle_drive_request(ball_chaser::DriveToTarget::Request &req, ball_chaser::DriveToTarget::Response &res);

int main(int argc, char  **argv)
{
	/* code */
	ros::init(argc,argv,"drive_bot");
	ros::NodeHandle n;

	motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel",10);
	ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot",handle_drive_request);
	ROS_INFO("Moving the robot.");
	//TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request cb function
	//TODO: Delete the loop, move the code to the inside of the cb function.
	
	//TODO: Handle ROS communcation events.
    ros::spin();
	return 0;
}
bool handle_drive_request(ball_chaser::DriveToTarget::Request &req, ball_chaser::DriveToTarget::Response &res){
	    geometry_msgs::Twist motor_command;
		motor_command.linear.x = req.linear_x;
		motor_command.angular.z = req.angular_z;

		motor_command_publisher.publish(motor_command);

		return true;
}