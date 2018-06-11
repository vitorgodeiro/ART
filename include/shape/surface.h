#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "../util/ray.h" 
#include "../util/hit.h"

class Surface {
    public:
        virtual bool hit (const Ray& r, float t_min, float t_max, Hit& rec) const = 0;
};

#endif
