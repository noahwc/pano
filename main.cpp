#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <filesystem>

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
        std::cout << "Failed to load image(s)";
        return EXIT_FAILURE;
    }

    if(!args.find("--out")){
        args["--out"] == "./";
    }

    current_pano.loadOutPath(args["--out"]);

    int stitch_result = current_pano.stitch(args)

    if(stitch_result){
        std::cout << "Successfully stitched images and output result to: " << args["--out"] << endl;
    }
    else{
        std::cout << "Failed to stitch images with error: " << stitch_result << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}