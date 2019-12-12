#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "NODE_1");

  ros::NodeHandle n;

  ros::Publisher ch1_NODE1 = n.advertise<std_msgs::Int32>("ch1", 1000);

  ros::Rate loop_rate(1);

  int count = 1;
  while (ros::ok())
  {
    std_msgs::Int32 msg;

    msg.data =count;

    ROS_INFO("NODE 1 SENT %d", msg.data);

   
    ch1_NODE1.publish(msg);//sending to subscriber

    ros::spinOnce();

    loop_rate.sleep();
    count++;
  }


  return 0;
}
