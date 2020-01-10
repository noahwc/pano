#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


class panoSet{
    public:
        panoSet();
        int loadImages(std::vector<std::string> filenames);
        int stitch();
        int loadOutPath(std::string path);
        int exportPano();
        std::string getOutLocation();
    private:
        std::string output_location;
        std::vector<cv::Mat> images;
};