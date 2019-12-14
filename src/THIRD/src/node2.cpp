#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
 image_transport::Publisher pub;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  { cv::Mat img=cv_bridge::toCvShare(msg, "bgr8")->image;
    cv::imshow("2nd node preview",img);
    int c=cv::waitKey(10);
    if(c == 'p')
    pub.publish(msg);
    else if(c =='s')
    cv::imwrite("output.png",img);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv)
{ 
  ros::init(argc, argv, "node_2");
  ros::NodeHandle nh;
  cv::namedWindow("2nd node preview");
  cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("cam", 1, imageCallback);
  pub  = it.advertise("cam2", 1);    
ros::spin();
  cv::destroyWindow("2nd node preview");
}
