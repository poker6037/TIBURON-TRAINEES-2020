#include "ros/ros.h"
#include "std_msgs/Int32.h"

std_msgs::Int32 msg4;

void chatterCallback1(const std_msgs::Int32::ConstPtr& msg3)
{
  msg4.data=msg3->data;
}

void chatterCallback(const std_msgs::Int32::ConstPtr& msg2)
{
  if(msg2->data==msg4.data)
   ROS_INFO("CORRECT");
  else
   ROS_INFO("INCORRECT OPTION");

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "NODE_3");

  ros::NodeHandle n;
  ros::NodeHandle m;
  ros::Subscriber sub = n.subscribe("ch2", 1000, chatterCallback);
  ros::Subscriber sub1 = m.subscribe("ch3", 1000, chatterCallback1);
ros::spin();

  return 0;
}
