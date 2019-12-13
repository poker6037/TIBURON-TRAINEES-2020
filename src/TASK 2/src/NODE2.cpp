#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <sstream>
#include<iostream>

ros::Publisher ch2_NODE2;
  

void chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
   ROS_INFO("I heard: [%s]", msg->data.c_str());
   ROS_INFO(" ENTER YOUR CHOICE"); 
   std_msgs::Int32 msg2;
   std::cin>>msg2.data;
   ch2_NODE2.publish(msg2);//sending to subscriber
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "NODE_2");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("ch1", 1000, chatterCallback1);

  ch2_NODE2 = n.advertise<std_msgs::Int32>("ch2", 1000); 
  ros::spin();
  return 0;
}
