#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{

    panoSet current_pano;

    std:map<std:string, std::vector<std::string> > args;

    for(i = 1; i < argc; i++){
        if(argv[i][0] == "-"){
            std::string flag = argv[i];
            while(i < argc){
                args[flag].push_back(argv[i]);
                if(++i < argc && argv[i][0] != "-"){ // Check if at the next flag.
                    i--;
                    break;
                }
            }
        }
    }

    if(imageset.loadImages(args["--images"]); == -1){
        return EXIT_FAILURE;
    }

    return 0;
}