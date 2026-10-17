#ifndef ENGINE_COMMON_CDEV_VECTOR_H
#define ENGINE_COMMON_CDEV_VECTOR_H

#include <vector>

template<class T>
class CDev_Allocator {
public:
    template<class Other>
    struct rebind {
        typedef CDev_Allocator<Other> other;
    };
};

template<class T, class Allocator = CDev_Allocator<T> >
class cdev_vector : public std::_Vector_val<T, Allocator> {
public:
    size_t size() const {
        return _Myfirst == 0 ? 0 : _Mylast - _Myfirst;
    }

    T& operator[](size_t position) {
        _SCL_SECURE_VALIDATE_RANGE(position < size());
        return *(_Myfirst + position);
    }

private:
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
};

#endif
