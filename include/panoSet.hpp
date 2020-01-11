#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


class panoSet{
    private:
        std::string output_location;
        std::string output_name;
        std::vector<cv::Mat> images;
        cv::Mat pano;
    public:
        panoSet();
        int loadImages(std::vector<std::string> filenames);
        int stitch();
        int loadOutPath(std::string path);
        int exportPano();
        int loadOutFilename(std::string name);
        std::string getOutLocation();
};