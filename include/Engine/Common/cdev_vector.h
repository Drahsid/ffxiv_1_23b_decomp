#ifndef ENGINE_COMMON_CDEV_VECTOR_H
#define ENGINE_COMMON_CDEV_VECTOR_H

#include "Engine/Common/cdev_allocator.h"
#include <vector>

template<class T, class Allocator = CDev_Allocator<T> >
class cdev_vector : public std::vector<T, Allocator> {
};

#endif
