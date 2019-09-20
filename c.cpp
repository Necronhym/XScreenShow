/*
		Automata 2.0

	General purpose automation software
	based off OCR using tesseract and openCV
	for X11 linux platforms

	-N3cr0 15.0.2019.	
*/
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <string>
struct ScreenShot
	{
		//Cosntructor:
		Display* display;
		Window root;
		ScreenShot(Display* d)
			{
				display = d;
				root = DefaultRootWindow(display);
			}
		int x, y, w, h;
		//X11 stuff:
		XImage* img;
		cv::Mat Get(int x, int y, int w, int h)
			{
				img = XGetImage(display, root, x, y, w, h, AllPlanes, ZPixmap);
        			return cv::Mat(h, w, CV_8UC4, img->data);
			}
		~ScreenShot()
			{
				XDestroyImage(img);
			}
	};
////////////////////////////////////////////////////////////
//			MAIN
////////////////////////////////////////////////////////////
int main( int argc, char* argv[])
	{
		//X11 Display:	
		Display *display = XOpenDisplay(NULL);
		//ScreenShotContainer:
		ScreenShot Screen(display);
		cv::imshow( "Test", Screen.Get(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4])));
		cv::waitKey(0);
		//Closes X11 Display:
		XCloseDisplay(display);	
		return 0;
	}
