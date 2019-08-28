//Uncomment the following line if you are compiling this code in Visual Studio
//#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
 //open the video file or cam for reading
 VideoCapture cap(0);

 // if not success, exit program
 if (cap.isOpened() == false)
 {
  cout << "Cannot open the video file" << endl;
  cin.get(); //wait for any key press
  return -1;
 }

 //Uncomment the following line if you want to start the video in the middle
 //cap.set(CAP_PROP_POS_MSEC, 300);

 //get the frames rate of the video
 double fps = cap.get(CAP_PROP_FPS);
 cout << "Frames per seconds : " << fps << endl;

 String window_name = "My First Video";

 namedWindow(window_name, WINDOW_NORMAL); //create a window

 while (true)
 {
  Mat frame;
  bool bSuccess = cap.read(frame); // read a new frame from video

  //Breaking the while loop at the end of the video
  if (bSuccess == false)
  {
   cout << "Found the end of the video" << endl;
   break;
  }

  //show the frame in the created window
  imshow(window_name, frame);

  //wait for for 10 ms until any key is pressed.
  //If the 'Esc' key is pressed, break the while loop.
  //If the any other key is pressed, continue the loop
  //If any key is not pressed withing 10 ms, continue the loop
  if (waitKey(10) == 27)
  {
   cout << "Esc key is pressed by user. Stoppig the video" << endl;
   break;
  }
 }

 return 0;

}
