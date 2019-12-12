#include "ros/ros.h"
#include "std_msgs/Int32.h"



ros::Publisher ch2_NODE2;
  

void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("NODE_2 heard: [%d]", msg->data); 
 std_msgs::Int32 msg2;
 msg2.data =(msg->data)*(msg->data);
ch2_NODE2.publish(msg2);//sending to subscriber
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "NODE_2");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("ch1", 1000, chatterCallback);

   ch2_NODE2 = n.advertise<std_msgs::Int32>("ch2", 1000); 
 
  ros::spin();

  return 0;
}
