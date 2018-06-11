/****
* @file utils.h
* @brief Utilitys for materials (lambertian, metal, dieletric ...)
*/

/* Copyright © 2018 Vítor Godeiro. */

#include "../util/vec3.h"
#include <stdlib.h>

#pragma once
#ifndef _MATERIAL_UTILS_H_
#define _MATERIAL_UTILS_H _

Vec3 random_in_unit_sphere() {
    Vec3 p;
    do {
        p = 2.0*Vec3(drand48(),drand48(),drand48()) - Vec3(1,1,1);
    } while (p.squared_length() >= 1.0);
    return p;
}

float schlick(float cosine, float ref_idx) {
    float r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}

bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted) {
    Vec3 uv = Vec3::unit_vector(v);
    float dt = Vec3::dot(uv, n);
    float discriminant = 1.0 - ni_over_nt*ni_over_nt*(1-dt*dt);
    if (discriminant > 0) {
        refracted = ni_over_nt*(uv - n*dt) - n*sqrt(discriminant);
        return true;
    }
    else 
return false;
}

Vec3 reflect(const Vec3& v, const Vec3& n) {
     return v - 2*Vec3::dot(v,n)*n;
}

#endif