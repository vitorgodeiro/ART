/****
* @file surface_list.cpp
*
* Copyright © 2018 Vítor Godeiro LTDA.
****/

#include "../../include/shape/surface_list.h"

SurfaceList::SurfaceList () {};
SurfaceList::SurfaceList (std::vector<Surface*> l) :list (l) {};

inline bool SurfaceList::hit (const Ray& r, float t_min, float t_max, Hit& rec) const {
	
	Hit temp_rec;
    bool hit_anything = false;
    float closest_so_far = t_max;
    for (int i = 0; i < list.size(); i++) {
    	if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
	return hit_anything;
}