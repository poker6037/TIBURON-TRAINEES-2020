#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include<iostream> 
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
using namespace cv;
Mat frame,frame_HSV,frame_threshold,frame_thresholdf,frame_thresholde;
using namespace std;

int main(int argc,char** argv)
{    VideoCapture cap("/home/poker/rishav/robosub_path-1.mp4");//recieve
     namedWindow("OUTPUT");
    
VideoWriter video("Final Video.avi",CV_FOURCC('M','J','P','G'),50,Size(640,480));
     
 
	  while (1) 
  {
         cap >> frame;
         imshow("video",frame);
         
cvtColor(frame,frame_HSV,COLOR_BGR2HSV);
         inRange(frame_HSV, Scalar(0,115,240), Scalar(180, 255,255), frame_threshold);//HSV CONVERT
         
Mat element1 = getStructuringElement( MORPH_RECT,Size( 7,7 ),Point( 0, 0 ) );
        erode( frame_threshold, frame_thresholde, element1 );//erode
        
Mat element = getStructuringElement( MORPH_RECT,Size( 13, 13),Point( 0, 0 ) );
  dilate( frame_thresholde,frame_thresholdf, element );//dialte
  
    imshow("OUTPUT", frame_thresholdf);//output





    video.write(frame_thresholdf);
          int key=waitKey(75);
        
  }
video.release();     
     
}

