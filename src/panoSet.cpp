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

int panoSet::loadOutFilename(std::string name){
    panoSet::output_name = name;
    return 0;
}

int panoSet::loadOutPath(std::string path){
    panoSet::output_location = path;
    return 0;
}

std::string panoSet::getOutLocation(){
    return panoSet::output_location;
}

int panoSet::exportPano(){
    panoSet::pano.convertTo(panoSet::pano, CV_16U);
    cv::imwrite(panoSet::output_location, panoSet::pano);
    return 0;
}