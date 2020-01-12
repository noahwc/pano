# pano
pano is an image stitcher made with OpenCV.

## Compiling
Compiling pano requires a C++ compiler with C++ 17 support (e.g. g++ 9), CMake 2.8 or better, and OpenCV 4.

pano can be built with `cmake build'.

## Usage

pano is currently a command line based program. The following command line options are available:

`--images`: a list of the images to be stiched together.

`--display`: (optional) display the resulting panorama in a graphical window.

`--path`: (optional, default is the working directory) the path where the result should be outputted.

`--name`: (optional, default is "pano") the name of the resulting file.

Note: Current pano only support outputting TIFF files.
