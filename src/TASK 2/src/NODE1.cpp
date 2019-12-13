#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "NODE_1");
  ros::NodeHandle n; 
  ros::Publisher ch1_NODE1 = n.advertise<std_msgs::String>("ch1", 1000);
  ros::Publisher ch3_NODE1 = n.advertise<std_msgs::Int32>("ch3", 1000);
  ros::Rate loop_rate(0.08);
   
    std_msgs::String msg;
   
    std::stringstream ss;
    ss<<" \n Q.BIGGEST MOUNTAIN RANGE \n 1.K2 \t \t 2.EVEREST \n 3.KANCHANJUNGA \t 4.ROCKY";
    msg.data =ss.str(); 
	loop_rate.sleep();
 
    ROS_INFO("%s",msg.data.c_str());
  
   
    ch1_NODE1.publish(msg);//sending to subscriber
    std_msgs::Int32 msg2;
    msg2.data=2;
   
    ch3_NODE1.publish(msg2);//sending to subscriber

    ros::spinOnce();

    return 0;
}
