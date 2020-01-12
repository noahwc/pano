#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include "include/panoSet.hpp"
#include <opencv2/opencv.hpp>


std::string fixNameCollision(std::string filename, std::string path){
    std::string postfix = "";
    for(int i = 0; std::filesystem::exists(path + filename + postfix + ".tiff"); i++){
        postfix = std::to_string(i + 1);
    }
    return path + filename + postfix + ".tiff";
}

int main(int argc, char** argv )
{

    panoSet current_pano;

    std::map<std::string, std::vector<std::string> >  args;

    for(int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            std::string flag = argv[i];
            i++;
            while(i < argc){
                args[flag].push_back(argv[i]);
                if(++i < argc && argv[i][0] == '-'){ // Check if at the next flag.
                    i--;
                    break;
                }
            }
        }
    }

    if(!args.count("--path")){
        args["--path"].push_back("./");
    }

    if(!args.count("--name")){
        args["--name"].push_back("pano");
    }
    current_pano.loadOutFile(fixNameCollision(args["--name"][0], args["--path"][0]));

    if(current_pano.loadImages(args["--images"]) == -1){
        std::cout << "Failed to load image(s)";
        return EXIT_FAILURE;
    }

    int stitch_result = current_pano.stitch();
    if(stitch_result){
        std::cout << "Failed to stitch images with error: " << stitch_result << std::endl;
        return EXIT_FAILURE;
    }

    int export_result = current_pano.exportPano(args.count("--display"));
    if(export_result){
        std::cout << "Failed export image with error: " << export_result << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << "Successfully stitched images and exported resulting image to: " << current_pano.getOutLocation() << std::endl;
    return EXIT_SUCCESS;
}