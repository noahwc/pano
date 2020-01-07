#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>


class panoSet{
    public:
        vector<Mat> images;
        int loadImages(std::vector<string> filenames);
        int stitch();
    private:
};