/*
 * Copyright 2011-2018 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */
 
#ifndef BGFX_RENDERER_GXM_H_HEADER_GUARD
#define BGFX_RENDERER_GXM_H_HEADER_GUARD
#   include <vitasdk.h>

#   define GXM_DISPLAY_PENDING_COUNT 2

namespace bgfx { namespace gxm {

    struct VertexBufferGXM
            void create(uint32_t _size, void* _data, VertexDeclHandle _declHandle, uint16_t _flags);
        
        void update(uint32_t _offset, uint32_t _size, void* _data, bool _discard = false);
        
        void destroy();
    };
    
    struct IndexBufferGXM
    {
        void create(uint32_t _size, void* _data, uint16_t _flags);
        
        void update(uint32_t _offset, uint32_t _size, void* _data, bool _discard = false);
        
        void destroy();
    };
    
    struct ShaderGXM
    {
        void create(const Memory* _mem);
        void destroy();
    };
    
    struct ProgramGXM
    {
        void create(const ShaderGXM& _vsh, const ShaderGXM& _fsh);
        void destroy();
    };
} }

#endif