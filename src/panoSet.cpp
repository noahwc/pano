#include <stdio.h>
#include <iostream>
#include <vector>

#include "../include/panoSet.hpp"
#include <opencv2/opencv.hpp>


panoSet::panoSet(){
}

int panoSet::loadImages(std::vector<std::string> filenames){
    for(int i = 0; i < filenames.size(); i++){
        cv::Mat image = cv::imread(cv::samples::findFile( filenames[i] ), cv::IMREAD_COLOR );
        if(image.empty()){
            return 1;
        }
        panoSet::images.push_back(image);
    }
    return 0;
}

int panoSet::stitch(){
    return 0;
}

int panoSet::loadOutPath(std::string path){
    panoSet::output_location = path;
}

std::string panoSet::getOutLocation(){
    return panoSet::output_location;
}

int panoSet::exportPano(){
    return 0;
}