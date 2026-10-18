#ifndef ENGINE_MEDIA_PLAYER_I_PLAYER_H
#define ENGINE_MEDIA_PLAYER_I_PLAYER_H

#include "Engine/Media/Player/MemoryObject.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Media {
namespace Player {

class IPlayer : public MemoryObject {
public:
    virtual ~IPlayer();
};

} // namespace Player
} // namespace Media
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
