#include "ros/ros.h"
#include "std_msgs/Int32.h"

void chatterCallback(const std_msgs::Int32::ConstPtr& msg2)
{
  ROS_INFO("NODE_3 heard: [%d]", msg2->data); 

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "NODE_3");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("ch2", 1000, chatterCallback);


 
  ros::spin();

  return 0;
}
