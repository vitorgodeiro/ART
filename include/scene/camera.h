#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../util/ray.h" 

class Camera  {
  public:
    Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect) { 
      Vec3 u, v, w;
      float theta = vfov*M_PI/180;
      float half_height = tan(theta/2);
      float half_width = aspect * half_height;
      origin = lookfrom;
      w = Vec3::unit_vector(lookfrom - lookat);
      u = Vec3::unit_vector(Vec3::cross(vup, w));
      v = Vec3::cross(w, u);
      lower_left_corner = origin  - half_width*u -half_height*v - w;
      horizontal = 2*half_width*u;
      vertical = 2*half_height*v;
    }

    Ray get_ray(float u, float v) { return Ray(origin, lower_left_corner + u*horizontal + (1 - v)*vertical); }

    Vec3 origin;
    Vec3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;
};
#endif