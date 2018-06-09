#include <iostream>
#include <omp.h>
#include "util/image.cpp"
#include "../include/util/vec3.h"

int main (int argc, char* argv[]){
    
    int nx = 200;
    int ny = 100;

    Image img (nx, ny);

    
    #pragma omp parallel for
    for (int j = ny - 1; j >= 0; j--){
        int y = j + .5;
        for (int i = 0; i < nx; i++){
            int x = i + .5;
            img(i, ny - j - 1) = Color3f(float(x) / float(nx), float(y) / float(ny), 0.2);
        }
    }

    img.writePppmAscii("result.ppm");

}
