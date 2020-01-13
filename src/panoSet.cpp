#include <stdio.h>
#include <iostream>
#include <vector>
#include "../include/panoSet.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


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
    std::cout << "Stitch in progress." << std::endl;
    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(cv::Stitcher::Mode::PANORAMA);
    cv::Stitcher::Status status = stitcher->stitch(panoSet::images, panoSet::pano);
    if (status != cv::Stitcher::OK){
        return 1;
    }
    return 0;
}

int panoSet::loadOutFile(std::string name){
    panoSet::output_name = name;
    return 0;
}

std::string panoSet::getOutLocation(){
    return panoSet::output_name;
}

int panoSet::exportPano(bool display_result){
    cv::imwrite(panoSet::output_name, panoSet::pano);

    if(display_result){
        cv::namedWindow( "Stitched Panorama", cv::WINDOW_AUTOSIZE );
        cv::imshow( "Stitched Panorama", panoSet::pano );
        cv::waitKey(0);
    }

    return 0;
}