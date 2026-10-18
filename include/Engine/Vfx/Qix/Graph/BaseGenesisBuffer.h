#ifndef ENGINE_VFX_QIX_GRAPH_BASE_GENESIS_BUFFER_H
#define ENGINE_VFX_QIX_GRAPH_BASE_GENESIS_BUFFER_H

#include "types.h"
#include "Engine/Vfx/Common/Object.h"

namespace SQEX {
namespace CDev {
namespace Engine {
namespace Vfx {
namespace Qix {
namespace Graph {

class Struct_00BDB4F0;
struct GenesisBufferSource;

struct GenesisBufferChain {
    s16 headIndex;
    s16 tailIndex;
};

struct GenesisBufferEntry {
    Struct_00BDB4F0* unk_00;
    GenesisBufferSource* unk_04;
    u32 unk_08;
    s16 previousIndex;
    s16 nextIndex;
};

class IGenesisBuffer {
public:
    IGenesisBuffer() {
    }

    virtual ~IGenesisBuffer() {
    }

    virtual void func_00BF7FF0() = 0;
    virtual void Realloc(s32 arg0) = 0;
    virtual void func_00BF8010() = 0;
    virtual s32 func_00BF8020() = 0;
    virtual s32 func_00BF8030() = 0;
    virtual GenesisBufferEntry* func_00BF8040(s32 arg0) = 0;
    virtual u16 func_00BF8060(GenesisBufferEntry* arg0) = 0;
    virtual s32 func_0060DE70() = 0;
    virtual s32 func_00A87F40() = 0;
    virtual void func_00BE83C0(GenesisBufferChain* arg0, u32 arg1, GenesisBufferSource* arg2) = 0;
    virtual void func_00BF8080() = 0;
    virtual void func_00BF8090() = 0;
    virtual bool func_00BF80A0() = 0;
};

class BaseGenesisBuffer : public Common::Object, public IGenesisBuffer {
public:
    BaseGenesisBuffer(u32 arg0, s32 arg1);
    virtual ~BaseGenesisBuffer();
    virtual void func_00BF7FF0();
    virtual void func_00BF8010();
    virtual s32 func_00BF8020();
    virtual s32 func_00BF8030();
    virtual GenesisBufferEntry* func_00BF8040(s32 arg0);
    virtual u16 func_00BF8060(GenesisBufferEntry* arg0);
    virtual s32 func_0060DE70() {
        return peakEntryCount;
    }
    virtual s32 func_00A87F40() {
        return previousEntryCount;
    }
    virtual void func_00BF8080();
    virtual void func_00BF8090();
    virtual bool func_00BF80A0();
    void Entry_(GenesisBufferChain* arg0, s32 arg1, u32 arg2, GenesisBufferSource* arg3);

    u32 unk_04;
    GenesisBufferEntry* entries;
    bool unk_0C;
    s32 unk_10;
    s32 capacity;
    s32 entryCount;
    s32 peakEntryCount;
    s32 previousEntryCount;
};

} // namespace Graph
} // namespace Qix
} // namespace Vfx
} // namespace Engine
} // namespace CDev
} // namespace SQEX

#endif
