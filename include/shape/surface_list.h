#ifndef _SURFACE_LIST_H_
#define _SURFACE_LIST_H_

#include "surface.h" 
#include <vector>

class SurfaceList: public Surface {
    public:
    	SurfaceList () {};
        SurfaceList (std::vector<Surface*> l) :list (l) {};
        inline virtual bool hit (const Ray& r, float t_min, float t_max, Hit& rec) const;


        std::vector<Surface*> list;
};

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

#endif
