#include <iostream>
#include <omp.h>
#include "util/image.cpp"

int main (int argc, char* argv[]){
    int nx = 200;
    int ny = 100;

    Image img (nx, ny);

    
    #pragma omp parallel for
    for (int j = ny - 1; j >= 0; j--){
        int y = j + .5;
        for (int i = 0; i < nx; i++){
            int x = i + .5;
            float r = float(x) / float(nx);
            float g = float(y) / float(ny);
            float b = 0.2;
            
            img(i, ny - j - 1)[0] = r;
            img(i, ny - j - 1)[1] = g;
            img(i, ny - j - 1)[2] = b;
            
        }
    }

    img.writePppmAscii("result.ppm");

}
