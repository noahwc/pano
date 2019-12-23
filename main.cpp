#include <stdio.h>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;

int parseInput(int argc, char** argv){
    vector<Mat> files;
    for(int i = 0; i < argc; i++){
        image = imread( samples::findFile( argv[i] ), IMREAD_COLOR );
        images.push_back(file)
    }
    return 0;
}

int main(int argc, char** argv )
{
    if(!parseInput(argc, argv)){
        return EXIT_FAILURE;
    }

    return 0;
}