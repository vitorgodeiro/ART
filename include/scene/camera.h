#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../util/ray.h" 

class Camera  {
  public:
    Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist) { 
      lens_radius = aperture / 2;
      float theta = vfov*M_PI/180;
      float half_height = tan(theta/2);
      float half_width = aspect * half_height;
      origin = lookfrom;
      w = Vec3::unit_vector(lookfrom - lookat);
      u = Vec3::unit_vector(Vec3::cross(vup, w));
      v = Vec3::cross(w, u);
      lower_left_corner = origin  - half_width*focus_dist*u -half_height*focus_dist*v - w*focus_dist;
      horizontal = 2*half_width*focus_dist*u;
      vertical = 2*half_height*focus_dist*v;
    }

    Ray get_ray(float u, float v) { return Ray(origin, lower_left_corner + u*horizontal + (1 - v)*vertical); }

    Vec3 origin;
    Vec3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 u, v, w;
    float lens_radius;
};
#endif