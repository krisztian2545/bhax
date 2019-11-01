#include <iostream>
#include "mlp.hpp"
#include <png++/png.hpp>

using namespace png;

int main (int argc, char **argv)
{

    image <rgb_pixel> png_image (argv[1]);
    int w = png_image.get_width();
    int h = png_image.get_height();
    int size = png_image.get_width() * png_image.get_height();
    image <rgb_pixel> png_image2(w, h);

    Perceptron* p = new Perceptron (3, size, 256, size);

    std::cout << size << " kezdes\n";

    double* image = new double[size];
    double* image2 = new double[size];
    double* image3 = new double[size];

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j){
          image[i*w + j] = png_image[i][j].red;
          image2[i*w + j] = png_image[i][j].green;
          image3[i*w + j] = png_image[i][j].blue;
        }

    double* value = (*p) (image);
    double* value2 = (*p) (image);
    double* value3 = (*p) (image);



    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j){
          png_image2[i][j].red = value[i*w + j] * 100;
          png_image2[i][j].green = value2[i*w + j] * 100;
          png_image2[i][j].blue = value3[i*w + j] * 100;
        }

    png_image2.write("mandel2.png");

    for(int i = 2500; i < 2700; i++) std::cout << value[i] << " ";

    delete p;
    delete [] image;

}
