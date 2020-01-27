/**** Projet long N7 2017 ****/

#include "robot3.h"

#include <ros/ros.h>


int main(int argc, char **argv)
{
	//Initialisation du noeud ROS
	ros::init(argc,argv,"robot3");
	ros::NodeHandle nh;

	//CmdRobot
	Robot3 Robot3;
	Robot3.init(nh);
	ros::Rate loop_rate(26);

	while(ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}
}
