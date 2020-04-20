#include<ros/ros.h>
#include<visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include <tf/tf.h>
#include <math.h>

float odom_x = 0;
float odom_y = 0;

void odom_callback(const nav_msgs::Odometry::ConstPtr& msg);

int main(int argc, char **argv)
{
	/* code */
	float pickup[] = {2.93,0.05};
	float dropoff[] = {-1.5,7.57};
	ros::init(argc,argv,"add_markers");
	ros::NodeHandle n;
	ros::Rate r(1);
	ros::Subscriber obom_sub = n.subscribe("/odom", 1000, odom_callback);
	ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);
	uint32_t shape = visualization_msgs::Marker::CUBE;
	bool reached_marker = false;


		visualization_msgs::Marker marker;
		// Set the frame ID and timestamp.

		marker.header.frame_id = "map";
		marker.header.stamp = ros::Time::now();

		marker.ns = "basic_shapes";
		marker.id = 0;
		marker.type = shape;
		marker.action = visualization_msgs::Marker::ADD;

		marker.pose.position.x = pickup[0];
		marker.pose.position.y = pickup[1];
		marker.pose.position.z = 0.5;
		marker.pose.orientation.x = 0.0;
		marker.pose.orientation.y = 0.0;
		marker.pose.orientation.z = 0.0;
		marker.pose.orientation.w = 1.0;

		marker.scale.x = 0.25;
		marker.scale.y = 0.25;
		marker.scale.z = 0.5;

		marker.color.r = 0.0f;
		marker.color.g = 0.0f;
		marker.color.b = 1.0f;
		marker.color.a = 1.0;

		marker.lifetime = ros::Duration();
		
		while(ros::ok()){
			float dx, dy;
			float eps = 0.5;

			if(!reached_marker){
				marker_pub.publish(marker);
				dx = fabs(marker.pose.position.x - odom_x);
				dy = fabs(marker.pose.position.y - odom_y);
				//ROS_INFO("Distance to goal x:%f   y:%f",dx,dy);
				if((dx < eps) && (dy < eps)){
					
					marker.action = visualization_msgs::Marker::DELETE;
					marker_pub.publish(marker);
					reached_marker = true;
					ros::Duration(5.0).sleep();

				}
			} else{
				dx = fabs(marker.pose.position.x - odom_x);
				dy = fabs(marker.pose.position.y - odom_y);
				if((dx < eps) && (dy < eps)){
					marker.action = visualization_msgs::Marker::ADD;
					marker.pose.position.x = dropoff[0];
					marker.pose.position.y = dropoff[1];
					marker.pose.position.z = 0.5;
					
					marker_pub.publish(marker);
				}
			}
			ros::spinOnce();
			r.sleep();

		}
		


	
	return 0;
}
void odom_callback(const nav_msgs::Odometry::ConstPtr& msg){
	::odom_x = msg->pose.pose.position.x;
	::odom_y = msg->pose.pose.position.y;
}