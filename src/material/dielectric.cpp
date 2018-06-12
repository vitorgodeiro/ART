/****
* @file dieletric.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/material/dielectric.h"

Dielectric::Dielectric(float ri) : ref_idx(ri) {}

bool Dielectric::scatter(const Ray& r_in, const Hit& rec, Vec3& attenuation, Ray& scattered) const  {
	Vec3 outward_normal;
	Vec3 reflected = reflect(r_in.get_direction(), rec.normal);
	float ni_over_nt;
	attenuation = Vec3(1.0, 1.0, 1.0); 
	Vec3 refracted;
	float reflect_prob;
	float cosine;
	if (Vec3::dot(r_in.get_direction(), rec.normal) > 0.000001) {
	  outward_normal = -rec.normal;
	  ni_over_nt = ref_idx;
	  cosine = Vec3::dot(r_in.get_direction(), rec.normal) / r_in.get_direction().length();
	  cosine = sqrt(1 - ref_idx*ref_idx*(1-cosine*cosine));
	}
	else {
	  outward_normal = rec.normal;
	  ni_over_nt = 1.0 / ref_idx;
	  cosine = -Vec3::dot(r_in.get_direction(), rec.normal) / r_in.get_direction().length();
	}
	if (refract(r_in.get_direction(), outward_normal, ni_over_nt, refracted)) 
	reflect_prob = schlick(cosine, ref_idx);
	else 
	reflect_prob = 1.0;
	if (drand48() < reflect_prob) 
	scattered = Ray(rec.point, reflected);
	else 
	scattered = Ray(rec.point, refracted);
	return true;
}