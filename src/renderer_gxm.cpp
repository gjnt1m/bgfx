/*
 * Copyright 2011-2018 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#include "bgfx_p.h"

#if BGFX_CONFIG_RENDERER_GXM
#   include "renderer_gxm.h"

namespace bgfx
{
    

} // namespace bgfx

namespace bgfx { namespace gxm
{
    struct RendererContextGXM : public RendererContextI
    {
        RendererContextGXM()
        {
            
        }
        
        ~RendererContextGXM()
        {
            
        }
        
        RendererType::Enum getRendererType() const override
        {
           return RendererType::Gxm;
        }

        const char* getRendererName() const override
        {
            return BGFX_RENDERER_GXM_NAME;
        }
        
        bool isDeviceRemoved() override
        {
           return false;
        }

        bool init(const Init& _init)
        {
            return true;
        }
        
        bool shutdown()
        {
            return true;
        }
        

        void flip() override
        {
        }

        void createIndexBuffer(IndexBufferHandle /*_handle*/, const Memory* /*_mem*/, uint16_t /*_flags*/) override
        {
        }

        void destroyIndexBuffer(IndexBufferHandle /*_handle*/) override
        {
        }

        void createVertexDecl(VertexDeclHandle /*_handle*/, const VertexDecl& /*_decl*/) override
        {
        }

        void destroyVertexDecl(VertexDeclHandle /*_handle*/) override
        {
        }

      void createVertexBuffer(VertexBufferHandle /*_handle*/, const Memory* /*_mem*/, VertexDeclHandle /*_declHandle*/, uint16_t /*_flags*/) override
      {
      }

      void destroyVertexBuffer(VertexBufferHandle /*_handle*/) override
      {
      }

      void createDynamicIndexBuffer(IndexBufferHandle /*_handle*/, uint32_t /*_size*/, uint16_t /*_flags*/) override
      {
      }

      void updateDynamicIndexBuffer(IndexBufferHandle /*_handle*/, uint32_t /*_offset*/, uint32_t /*_size*/, const Memory* /*_mem*/) override
      {
      }

      void destroyDynamicIndexBuffer(IndexBufferHandle /*_handle*/) override
      {
      }

      void createDynamicVertexBuffer(VertexBufferHandle /*_handle*/, uint32_t /*_size*/, uint16_t /*_flags*/) override
      {
      }

      void updateDynamicVertexBuffer(VertexBufferHandle /*_handle*/, uint32_t /*_offset*/, uint32_t /*_size*/, const Memory* /*_mem*/) override
      {
      }

      void destroyDynamicVertexBuffer(VertexBufferHandle /*_handle*/) override
      {
      }

      void createShader(ShaderHandle /*_handle*/, const Memory* /*_mem*/) override
      {
      }

      void destroyShader(ShaderHandle /*_handle*/) override
      {
      }

      void createProgram(ProgramHandle /*_handle*/, ShaderHandle /*_vsh*/, ShaderHandle /*_fsh*/) override
      {
      }

      void destroyProgram(ProgramHandle /*_handle*/) override
      {
      }

      void* createTexture(TextureHandle /*_handle*/, const Memory* /*_mem*/, uint64_t /*_flags*/, uint8_t /*_skip*/) override
      {
         return NULL;
      }

      void updateTextureBegin(TextureHandle /*_handle*/, uint8_t /*_side*/, uint8_t /*_mip*/) override
      {
      }

      void updateTexture(TextureHandle /*_handle*/, uint8_t /*_side*/, uint8_t /*_mip*/, const Rect& /*_rect*/, uint16_t /*_z*/, uint16_t /*_depth*/, uint16_t /*_pitch*/, const Memory* /*_mem*/) override
      {
      }

      void updateTextureEnd() override
      {
      }

      void readTexture(TextureHandle /*_handle*/, void* /*_data*/, uint8_t /*_mip*/) override
      {
      }

      void resizeTexture(TextureHandle /*_handle*/, uint16_t /*_width*/, uint16_t /*_height*/, uint8_t /*_numMips*/) override
      {
      }

      void overrideInternal(TextureHandle /*_handle*/, uintptr_t /*_ptr*/) override
      {
      }

      uintptr_t getInternal(TextureHandle /*_handle*/) override
      {
         return 0;
      }

      void destroyTexture(TextureHandle /*_handle*/) override
      {
      }

      void createFrameBuffer(FrameBufferHandle /*_handle*/, uint8_t /*_num*/, const Attachment* /*_attachment*/) override
      {
      }

      void createFrameBuffer(FrameBufferHandle /*_handle*/, void* /*_nwh*/, uint32_t /*_width*/, uint32_t /*_height*/, TextureFormat::Enum /*_format*/, TextureFormat::Enum /*_depthFormat*/) override
      {
      }

      void destroyFrameBuffer(FrameBufferHandle /*_handle*/) override
      {
      }

      void createUniform(UniformHandle /*_handle*/, UniformType::Enum /*_type*/, uint16_t /*_num*/, const char* /*_name*/) override
      {
      }

      void destroyUniform(UniformHandle /*_handle*/) override
      {
      }

      void requestScreenShot(FrameBufferHandle /*_handle*/, const char* /*_filePath*/) override
      {
      }

      void updateViewName(ViewId /*_id*/, const char* /*_name*/) override
      {
      }

        void updateUniform(uint16_t /*_loc*/, const void* /*_data*/, uint32_t /*_size*/) override
        {
        }

        void setMarker(const char* /*_marker*/, uint32_t /*_size*/) override
        {
        }

        void invalidateOcclusionQuery(OcclusionQueryHandle /*_handle*/) override
        {
        }

        virtual void setName(Handle /*_handle*/, const char* /*_name*/) override
        {
        }

        void submit(Frame* _render, ClearQuad& /*_clearQuad*/, TextVideoMemBlitter& /*_textVideoMemBlitter*/) override
        {
        }

        void blitSetup(TextVideoMemBlitter& /*_blitter*/) override
        {
        }

        void blitRender(TextVideoMemBlitter& /*_blitter*/, uint32_t /*_numIndices*/) override
        {
        }
        
        ShaderGXM m_shaders[BGFX_CONFIG_MAX_SHADERS];
        ProgramGXM m_program[BGFX_CONFIG_MAX_PROGRAMS];
        IndexBufferGXM m_indexBuffers[BGFX_CONFIG_MAX_INDEX_BUFFERS];
        VertexBufferGXM m_vertexBuffers[BGFX_CONFIG_MAX_VERTEX_BUFFERS];
        VertexDecl m_vertexDecls[BGFX_CONFIG_MAX_VERTEX_DECLS];
    };
    
    static RendererContextGXM* s_renderGXM;
    
    RendererContextI* rendererCreate(const Init& _init)
    {
        s_renderGXM = BX_NEW(g_allocator, RendererContextGXM);
        if (!s_renderGXM->init(_init) )
        {
            BX_DELETE(g_allocator, s_renderGXM);
            s_renderGXM = NULL;
        }
        return s_renderGXM;
    }

    void rendererDestroy()
    {
        s_renderGXM->shutdown();
        BX_DELETE(g_allocator, s_renderGXM);
        s_renderGXM = NULL;
    }
} /* namespace gxm */ } // namespace bgfx

#else
namespace bgfx { namespace gxm
{
    RendererContextI* rendererCreate(const Init& _init)
    {
        BX_UNUSED(_init);
        return NULL;
    }

    void rendererDestroy()
    {
    }
} /* namespace gxm */ } // namespace bgfx

#endif //BGFX_CONFIG_RENDERER_DIRECT3D11