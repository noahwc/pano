#include <stdio.h>
#include <iostream>
#include <vector>
#include <filesystem>

#include "panoSet.h"
#include <opencv2/opencv.hpp>

using namespace cv;

void panoSet::panoSet(){
}

int panoSet::loadImages(std::vector<string> filenames){
    for(int i = 0; i < filesnames.size(); i++){
        file = imread( samples::findFile( filenames[i] ), IMREAD_COLOR );
        if(file == NULL){
            return -1;
        }
        panoset::images.push_back(file)
    }
    return 0
}

int panoSet::stitch(){

}

int panoSet::loadOutPath(string path){
    panoSet::output_location = path;
}