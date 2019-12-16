#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream> 
#include <opencv2/core/core.hpp>// for converting the command line parameter to integer
#include <opencv2/opencv.hpp>
int main(int argc, char** argv)
{
 cv::namedWindow("output");
  ros::init(argc, argv, "NODE_1");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("cam", 1);
image_transport::Publisher pub2=it.advertise("cam2",1);

  

  cv::VideoCapture cap(0);
  cv::Mat frame;
  sensor_msgs::ImagePtr msg;
  ros::Rate loop_rate(50);

  while (nh.ok()) 
{
    cap >> frame;
    cv:imshow("output",frame);
  int c=cv::waitKey(10);
  if(c=='p')
   
    {
      msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      pub.publish(msg);
      pub2.publish(msg);
     cv::waitKey(1); 
    }

    ros::spinOnce();
    loop_rate.sleep();
  }
cv::destroyWindow("output");
}
