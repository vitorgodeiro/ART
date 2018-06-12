/****
* @file hit.h
* @brief Definition of Hit struct
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _HIT_H_
#define _HIT_H_

#include "vec3.h"

class Material;

struct Hit
{
    float t;
    Point3 point;
    Vec3 normal;    
    Material *mat_ptr;
};

#include "../material/material.h"

#endif