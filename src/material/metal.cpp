/****
* @file metal.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/material/metal.h"

Metal::Metal(const Vec3& a, float f) : albedo(a) { if (f < 1) fuzz = f; else fuzz = 1; }

bool Metal::scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const  {
	Vec3 reflected = reflect(Vec3::unit_vector(r_in.get_direction()), rec.normal);
    scattered = Ray(rec.point, reflected + fuzz*random_in_unit_sphere());
    attenuation = albedo;
	return (Vec3::dot(scattered.get_direction(), rec.normal) > 0);
}