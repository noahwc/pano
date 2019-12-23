#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "panoSet.h"

using namespace cv;

void panoSet::panoSet(vector<Mat> images){
    panoSet.images = images
}