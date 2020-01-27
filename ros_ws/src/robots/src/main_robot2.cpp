/**** Projet long N7 2017 ****/

#include "robot2.h"

#include <ros/ros.h>


int main(int argc, char **argv)
{
	//Initialisation du noeud ROS
	ros::init(argc,argv,"robot2");
	ros::NodeHandle nh;

	//CmdRobot
	Robot2 Robot2;
	Robot2.init(nh);
	ros::Rate loop_rate(26);

	while(ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
}
