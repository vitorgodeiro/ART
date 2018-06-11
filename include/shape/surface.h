/****
* @file surface.h
* @brief Definition of Surface class
*/

/* Copyright © 2018 Vítor Godeiro. */

#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "../util/ray.h" 
#include "../util/hit.h"

/** 
* @class Surface
* @brief The class that represents an Surface object
*/
class Surface {
    public:
        virtual bool hit (const Ray& r, float t_min, float t_max, Hit& rec) const = 0;
};

#endif
