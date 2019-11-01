#include <iostream>
#include "mlp.hpp"
#include <png++/png.hpp>

void write_len(double* d){
  long counter = 0;
  while(d[counter] != NULL){
    std::cout << d[counter] << ", ";
    counter++;
  }

  std::cout << std::endl << counter << std::endl;
}

int main (int argc, char **argv)
{
    png::image <png::rgb_pixel> png_image (argv[1]);

    int size = png_image.get_width() * png_image.get_height();

    Perceptron* p = new Perceptron (3, size, 256, 1);

    std::cout << size << " kezdes\n";

    double* image = new double[size];

    write_len(image);

    int w = png_image.get_width();
    int h = png_image.get_height();

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            image[i*w + j] = png_image[i][j].red;

    write_len(image);

    std::cout << "kezdes";

    double* value = (*p) (image);

    write_len(value);

    std::cout << "csere";

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            png_image[i][j].red = value[i*w + j];

    std::cout << "iras";

    png_image.write(argv[1]);

    std::cout << "kiiratas";

    std::cout << value << std::endl;

    std::cout << "vege";

    delete p;
    delete [] image;

}
