#include <stdio.h>
#include <iostream>
#include <vector>
#include "panoSet.h"
#include <opencv2/opencv.hpp>

using namespace cv;

void panoSet::panoSet(){
}

int panoSet::loadImages(std::vector<string> filenames){
    std::vector<Mat> files;
    for(int i = 0; i < filesnames.size(); i++){
        file = imread( samples::findFile( filenames[i] ), IMREAD_COLOR );
        if(file == NULL){
            return -1;
        }
        files.push_back(file)
    }
    return files.size();
}

int panoSet::stitch(){
    
}