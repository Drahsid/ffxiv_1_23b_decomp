#ifndef ENGINE_VFX_QIX_GRAPH_RING_GENESIS_BUFFER_H
#define ENGINE_VFX_QIX_GRAPH_RING_GENESIS_BUFFER_H

#include "Engine/Vfx/Qix/Graph/BaseGenesisBuffer.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Graph {

class RingGenesisBuffer : public BaseGenesisBuffer {
public:
    RingGenesisBuffer(u32 arg0, s32 arg1);
    virtual ~RingGenesisBuffer();
    virtual void func_00BE83C0(GenesisBufferChain* arg0, u32 arg1, GenesisBufferSource* arg2);
    virtual void func_00BF7FF0();
    virtual GenesisBufferEntry* func_00BF8040(s32 arg0);
    virtual void Realloc(s32 arg0);

    s32 unk_24;
};

} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
