#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <string.h>
#include<cstdio>
#include<cstdlib>
#include<ball_chaser/ObjectFound.h>

// Define a global client that can request services
ros::ServiceClient client;
ros::Publisher isFound;
// This function calls the command_robot service to drive the robot in the specified direction


// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    FILE *tarPtr;
    char target[6];
    if((tarPtr = fopen("/home/student/roboticsND/final-project/src/ball_chaser/src/target.txt","r")) == NULL){
        ROS_INFO("Fisierul nu a putut fi deschis");
    } else {
    fscanf(tarPtr,"%s",target);
    int num_tar_px = 0;
    
    int target_pixel = 255;
    int startPos = img.width / 3;
    int endPos = img.width * 2 / 3;

    for(int i = 0; i < img.data.size() - 2; i+= 3){
        int red_val = img.data[i];
        int green_val = img.data[i+1];
        int blue_val = img.data[i+2];
        if(!strcmp(target,"white")){
           
         if(red_val == target_pixel && green_val == target_pixel && blue_val == target_pixel){
        
            num_tar_px++;

        }

        } else if(!strcmp(target,"red")){
            if(red_val == target_pixel && green_val == 0 && blue_val == 0){

            num_tar_px++;
        }
        } else if(!strcmp(target,"blue")){
            if(red_val == 0 && green_val == 0 && blue_val == target_pixel){

            num_tar_px++;
        }
    }
         else if(!strcmp(target,"green")){
            if(red_val == 0 && green_val == target_pixel && blue_val == 0){
            num_tar_px++;
        }
    }
}

    if(num_tar_px){
        
      ball_chaser::ObjectFound found;
      found.is_found = 1;
      isFound.publish(found);
}
    fclose(tarPtr);
    //fclose(resPtr);
    



    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
}
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;
    

    // Define a client service capable of requesting services from command_robot
    

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    isFound = n.advertise<ball_chaser::ObjectFound>("/obj_found",1);
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}