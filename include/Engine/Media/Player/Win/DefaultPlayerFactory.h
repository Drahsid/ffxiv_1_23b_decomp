#ifndef ENGINE_MEDIA_PLAYER_WIN_DEFAULT_PLAYER_FACTORY_H
#define ENGINE_MEDIA_PLAYER_WIN_DEFAULT_PLAYER_FACTORY_H

#include "Engine/Media/Player/IPlayerFactory.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Media {
namespace Player {
namespace Win {

class DefaultPlayerFactory : public IPlayerFactory {
public:
    virtual ~DefaultPlayerFactory();
    virtual std::auto_ptr<IPlayer> CreatePlayer(f32 arg0);
};

} // namespace Win
} // namespace Player
} // namespace Media
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
