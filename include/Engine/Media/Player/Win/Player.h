#ifndef ENGINE_MEDIA_PLAYER_WIN_PLAYER_H
#define ENGINE_MEDIA_PLAYER_WIN_PLAYER_H

#include "Engine/Media/Player/IPlayer.h"
#include "types.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Media {
namespace Player {
namespace Win {

class Player : public IPlayer {
public:
    Player();

private:
    bool enabled;
    bool active;
    bool playing;
    bool paused;
    u32 unk_08[8];
};

} // namespace Win
} // namespace Player
} // namespace Media
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
