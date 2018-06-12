#include <iostream>
#include <omp.h>
#include "util/image.cpp"
#include "util/blue.cpp"
#include "shape/sphere.cpp"
#include "../include/util/vec3.h"
#include "../include/util/ray.h"
#include "shape/surface_list.cpp"
#include "material/lambertian.cpp"
#include "material/metal.cpp"
#include "material/dielectric.cpp"
#include "../include/scene/camera.h"

Vec3 color (const Ray& r, SurfaceList *world, int depth){
	Hit rec;
	if (world->hit(r, 0.0, 1000, rec)){
		Ray scattered;
		Vec3 attenuation;
		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)){
			return attenuation*color(scattered, world, depth + 1);
		}
		else{
			return Vec3(0, 0, 0);
		}
	}
	else {
		Vec3 unit_direction = Vec3::unit_vector(r.get_direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1-t)*Vec3(1, 1, 1) + t*Vec3(0.5, 0.7, 1);
	}	
}

int ns = 64;

int main (int argc, char* argv[]){
    
    int nx = 800;
    int ny = 400;

    Image img (nx, ny);

    Vec3 lower_left_corner (-2, -1, -1);
    Vec3 horizontal (4, 0, 0);
    Vec3 vertical (0, 2, 0);
    Vec3 origin (0, 0, 0);
    
    SurfaceList *world = new SurfaceList();
    world->list.push_back(new Sphere(Vec3(0,-100.5,-1), 100, new Lambertian (Vec3(0.8, 0.8, 0.0))));
    world->list.push_back(new Sphere(Vec3(0,0,-1), 0.5, new Lambertian (Vec3(0.8, 0.3, 0.3))));
    world->list.push_back(new Sphere(Vec3(1,0,-1), 0.5, new Metal(Vec3(0.8, 0.6, 0.2), 0)));
    world->list.push_back(new Sphere(Vec3(-1,0,-1), 0.45, new Dielectric(1.5)));
   	Camera cam(Vec3(-2,2,1), Vec3(0,0,-1), Vec3(0,1,0), 90, float(nx)/float(ny));

    #pragma omp parallel for
    for (int j = ny - 1; j >= 0; j--){
        int y = j + .5;
        float *samples = Blue::get(ns);
        for (int i = 0; i < nx; i++){
            int x = i + .5;
            Vec3 c;
            for (int n = 0; n < ns; n++){
                float v = (y + samples[n*2 + 1]) / float(ny);
                float u = (x + samples[n*2]) / float(nx);
                Ray r(origin, lower_left_corner + u*horizontal + v*vertical);

                c = c + color(r, world, 0);
            }
            c = c/ns;
            img(i, ny - j - 1) = Color3f(sqrt(c[0]), sqrt(c[1]), sqrt(c[2]));
        }
    }

    img.writePppmAscii("result.ppm");

}
