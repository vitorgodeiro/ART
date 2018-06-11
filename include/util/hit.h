/****
* @file hit.h
* @brief Definition of Hit struct
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _HIT_H_
#define _HIT_H_

#include "vec3.h"

struct Hit
{
    float t;
    Point3 point;
    Vec3 normal;    
};

#endif