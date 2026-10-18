#ifndef ENGINE_VFX_QIX_GRAPH_SURE_GENESIS_BUFFER_H
#define ENGINE_VFX_QIX_GRAPH_SURE_GENESIS_BUFFER_H

#include "Engine/Vfx/Qix/Graph/BaseGenesisBuffer.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Graph {

class SureGenesisBuffer : public BaseGenesisBuffer {
public:
    SureGenesisBuffer(u32 arg0, s32 arg1);
    virtual ~SureGenesisBuffer();
    virtual void func_00BE83C0(GenesisBufferChain* arg0, u32 arg1, GenesisBufferSource* arg2);
    virtual void Realloc(s32 arg0);
};

} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
