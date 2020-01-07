#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <filesystem>

using namespace cv;


class panoSet{
    public:
        int loadImages(std::vector<string> filenames);
        int stitch();
        int loadOutPath(string path);
    private:
        std::filesystem::path output_location;
        std::vector<Mat> images;
};