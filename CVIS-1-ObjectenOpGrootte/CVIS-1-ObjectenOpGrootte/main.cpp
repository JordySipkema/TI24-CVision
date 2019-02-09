//
//  main.cpp
//  CVIS-1-ObjectenOpGrootte
//
//  Created by Jordy Sipkema on 09/02/2019.
//  Copyright © 2019 Jordy Sipkema. All rights reserved.
//

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

int main(int argc, const char * argv[]) {
    cv::VideoCapture cap;
    cap.open(0);
    
    if (!cap.isOpened()){
        std::cerr << "***Could not initialize capturing...***" << std::endl;
        std::cerr << "Current parameter's value: " << std::endl;
        return -1;
    }
    
    cv::Mat frame;
    for(;;){
        cap >> frame;
        if (frame.empty()){
            std::cerr << "Frame is empty" << std::endl;
            break;
        }
        cv::imshow("Camera capture", frame);
        cv::waitKey(10);
    }
    
    return 1;
}
