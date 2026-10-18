#include "Engine/Media/Player/Win/DefaultPlayerFactory.h"
#include "Engine/Media/Player/Win/Player.h"
#include "Engine/Common/Log.h"

using SQEX::CDev::Engine::Media::Player::Win::DefaultPlayerFactory;

DefaultPlayerFactory::~DefaultPlayerFactory() {
}

static void Default_Assert_Handler(const char* expression, const char* message, const char* file, s32 line, const char* function) {
    LOG_ASSERT_FAILURE(expression, message, file, line, function);
}

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Media {
namespace Player {
namespace Win {

std::auto_ptr<IPlayer> DefaultPlayerFactory::CreatePlayer(f32 arg0) {
    Player* pPlayer = new Player();
    LOG_ASSERT_AT(".\\player\\win\\DefaultPlayerFactoryWIN.cpp", 22, pPlayer != 0, "");
    return std::auto_ptr<IPlayer>(pPlayer);
}

} // namespace Win
} // namespace Player
} // namespace Media
} // namespace Engine
} // namespace CDev
} // namespace SQEX
