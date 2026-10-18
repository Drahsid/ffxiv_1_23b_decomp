#ifndef ENGINE_MEDIA_PLAYER_I_PLAYER_FACTORY_H
#define ENGINE_MEDIA_PLAYER_I_PLAYER_FACTORY_H

#include "Engine/Media/Player/IPlayer.h"
#include "types.h"
#include <memory>

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Media {
namespace Player {

class IPlayerFactory : public MemoryObject {
public:
    virtual ~IPlayerFactory() {
    }

    virtual std::auto_ptr<IPlayer> CreatePlayer(f32 arg0) = 0;
};

} // namespace Player
} // namespace Media
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
