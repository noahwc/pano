#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "include/panoSet.hpp"

#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{

    panoSet current_pano;

    std::map<std::string, std::vector<std::string> >  args;

    for(int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            std::string flag = argv[i];
            while(i < argc){
                args[flag].push_back(argv[i]);
                if(++i < argc && argv[i][0] != '-'){ // Check if at the next flag.
                    i--;
                    break;
                }
            }
        }
    }

    if(current_pano.loadImages(args["--images"]) == -1){
        std::cout << "Failed to load image(s)";
        return EXIT_FAILURE;
    }

    if(!args.count("--out")){
        args["--out"].push_back("./");
    }
    current_pano.loadOutPath(args["--out"][0]);

    int stitch_result = current_pano.stitch();
    if(stitch_result){
        std::cout << "Failed to stitch images with error: " << stitch_result << std::endl;
        return EXIT_FAILURE;
    }

    int export_result = current_pano.exportPano();
    if(export_result){
        std::cout << "Failed export image with error: " << export_result << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << "Successfully stitched images and exported resulting image to: " << current_pano.getOutLocation() << std::endl;
    return EXIT_SUCCESS;
}