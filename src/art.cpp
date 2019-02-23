#include <iostream>
#include <chrono>

#include "util/blue.cpp"
#include "shape/sphere.cpp"

#include "material/lambertian.cpp"
#include "material/metal.cpp"
#include "material/dielectric.cpp"

#include "scene/scene.cpp"


int main (int argc, char* argv[]){

    Scene scene;

    auto start0 = std::chrono::steady_clock::now();

    auto start = std::chrono::steady_clock::now();
    scene.parsing();
    auto end = std::chrono::steady_clock::now();
    std::cout << "Parsing in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    scene.accelerate();
    end = std::chrono::steady_clock::now();
    std::cout << "Accelerate in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;        

    Image img = scene.render();

    start = std::chrono::steady_clock::now();
    img.writePppmAscii("result.ppm");
    end = std::chrono::steady_clock::now();
    std::cout << "Saved in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Done in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start0).count() << " ms" << std::endl;
}
