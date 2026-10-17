#ifndef SQEX_THREAD_MUTEX_H
#define SQEX_THREAD_MUTEX_H

#include <windows.h>

namespace Sqex {
namespace Thread {

class Mutex {
public:
    virtual ~Mutex();

private:
    CRITICAL_SECTION criticalSection;
};

} // namespace Thread
} // namespace Sqex

#endif
