#!/bin/sh
xterm -e " gazebo " &
sleep 5
xterm -e " soure /opt/ros/kinetic/setup.bash; roscore" &
sleep 5
xterm -e " rosrun rviz rviz"

