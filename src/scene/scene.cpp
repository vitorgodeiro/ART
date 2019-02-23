/****
* @file image.cpp
*
* Copyright © 2019 Vítor Godeiro LTDA.
****/

#include "../../include/scene/scene.h"

Scene::Scene(){
	world = new SurfaceList();
}

Vec3 Scene::sample(const Ray& r, int depth){
	Hit rec;
	if (world->hit(r, 0.001, std::numeric_limits<float>::max(), rec)){
		Ray scattered;
		Vec3 attenuation;
		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)){
			return attenuation*sample(scattered, depth + 1);
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

void Scene::accelerate(){
	
}

Image Scene::render(){
	auto start = std::chrono::steady_clock::now();
    Image img (nx, ny);

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
                Ray r = cam->get_ray (u, v);

                c = c + sample(r, 0);
            }
            c = c/ns;

            img(i, j) = Color3f(sqrt(c[0]), sqrt(c[1]), sqrt(c[2]));
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << "Rendering in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    return img;
}

void Scene::parsing(){
	nx = 900;
    ny = 600;
    ns = 64;
    
    int n = 500;
    world->list.push_back(new Sphere(Vec3(0,-1000,0), 1000, new Lambertian(Vec3(0.5, 0.5, 0.5))));
    int i = 1;

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            float choose_mat = drand48();
            Vec3 center(a+0.9*drand48(),0.2,b+0.9*drand48()); 
            if ((center-Vec3(4,0.2,0)).length() > 0.9) { 
                if (choose_mat < 0.8) {  // diffuse
                    world->list.push_back(new Sphere(center, 0.2, new Lambertian(Vec3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()))));
                }
                else if (choose_mat < 0.95) { // metal
                    world->list.push_back(new Sphere(center, 0.2,
                            new Metal(Vec3(0.5*(1 + drand48()), 0.5*(1 + drand48()), 0.5*(1 + drand48())),  0.5*drand48())));
                }
                else {  // glass
                    world->list.push_back(new Sphere(center, 0.2, new Dielectric(1.5)));
                }
            }
        }
	}

	world->list.push_back(new Sphere(Vec3(0, 1, 0), 1.0, new Dielectric(1.5)));
    world->list.push_back(new Sphere(Vec3(-4, 1, 0), 1.0, new Lambertian(Vec3(0.4, 0.2, 0.1))));
    world->list.push_back(new Sphere(Vec3(4, 1, 0), 1.0, new Metal(Vec3(0.7, 0.6, 0.5), 0.0)));

    Vec3 lookfrom (13,2,3);
    Vec3 lookat (0, 0, 0);
    float dist_to_focus = (lookfrom - lookat).length();
    float aperture = 0.1;
   	cam = new Camera(lookfrom, lookat, Vec3(0,1,0), 20, float(nx)/float(ny), aperture, dist_to_focus);
}