/*
 * Copyright 2011-2018 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#include "entry_p.h"

#if ENTRY_CONFIG_USE_NATIVE && BX_PLATFORM_VITA

#include <bgfx/platform.h>
#include <bx/config.h>
#include <bx/handlealloc.h>
#include <bx/os.h>
#include <bx/timer.h>
#include <bx/uint32_t.h>

#include <tinystl/allocator.h>
#include <tinystl/string.h>


namespace entry
{
	struct Context : public entry::PlatformCallback
	{
		Context(): m_init(false)
			, m_exit(false)
		{
			PlatformCallback::s_singleton = this;
		}

		void init(AppI* _app)
		{
			m_init = true;
		}

		bool update(AppI* _app)
		{
			return 0;
		}

		int32_t run(int _argc, const char* const* _argv)
		{
			
			int32_t result = main(_argc, _argv);

			return 0;
		}
        
		bool m_init;
		bool m_exit;
		EventQueue m_eventQueue;
    };

    static Context s_ctx;
    
    void setWindowSize(WindowHandle _handle, uint32_t _width, uint32_t _height)
	{
        BX_UNUSED(_handle);
        BX_UNUSED(_width);
        BX_UNUSED(_height);
	}

	void setWindowTitle(WindowHandle _handle, const char* _title)
	{
        BX_UNUSED(_handle);
        BX_UNUSED(_title);
	}

	void setWindowFlags(WindowHandle _handle, uint32_t _flags, bool _enabled)
	{
		BX_UNUSED(_handle);
        BX_UNUSED(_flags);
        BX_UNUSED(_enabled);
	}

	void toggleFullscreen(WindowHandle _handle)
	{
		BX_UNUSED(_handle);
	}

	void setMouseLock(WindowHandle _handle, bool _lock)
	{
		BX_UNUSED(_handle);
        BX_UNUSED(_lock);
	}
    
    const Event* poll()
	{
		return s_ctx.m_eventQueue.poll();
	}

	const Event* poll(WindowHandle _handle)
	{
		return s_ctx.m_eventQueue.poll(_handle);
	}

	void release(const Event* _event)
	{
		s_ctx.m_eventQueue.release(_event);
	}
} // namespace entry

int main(int _argc, const char* const* _argv)
{
	using namespace entry;
	return s_ctx.run(_argc, _argv);
}

#endif // BX_PLATFORM_WINDOWS
