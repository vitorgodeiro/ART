#include <iostream>
#include <omp.h>
#include "util/image.cpp"
#include "shape/sphere.cpp"
#include "../include/util/vec3.h"
#include "../include/util/ray.h"
#include "shape/surface_list.cpp"

Vec3 color (const Ray& r, SurfaceList *world){
	Hit rec;
	if (world->hit(r, 0.0, 1000, rec))
		return 0.5*Vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	else {
		Vec3 unit_direction = Vec3::unit_vector(r.get_direction());
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1-t)*Vec3(1, 1, 1) + t*Vec3(0.5, 0.7, 1);
	}	
}

int main (int argc, char* argv[]){
    
    int nx = 1920;
    int ny = 1080;

    Image img (nx, ny);

    Vec3 lower_left_corner (-2, -1, -1);
    Vec3 horizontal (4, 0, 0);
    Vec3 vertical (0, 2, 0);
    Vec3 origin (0, 0, 0);
    
    SurfaceList *world = new SurfaceList();
    world->list.push_back(new Sphere(Vec3(0,-100.5,-1), 100));
    world->list.push_back(new Sphere(Vec3(0,0,-1), 0.5));
   
    #pragma omp parallel for
    for (int j = ny - 1; j >= 0; j--){
        int y = j + .5;
        float v = y / float(ny);
        for (int i = 0; i < nx; i++){
            int x = i + .5;
            float u = x/ float(nx);
            Ray r(origin, lower_left_corner + u*horizontal + v*vertical);

            Vec3 c = color(r, world);
            img(i, ny - j - 1) = Color3f(c[0], c[1], c[2]);
        }
    }

    img.writePppmAscii("result.ppm");

}
