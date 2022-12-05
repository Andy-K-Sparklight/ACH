#ifndef INCLUDE_ALICORN_CH_ACH_SYS_SCHEDULE
#define INCLUDE_ALICORN_CH_ACH_SYS_SCHEDULE

#include <functional>
#include <uv.h>

namespace Alicorn
{
namespace Sys
{

extern uv_thread_t ACH_UV_THREAD;
extern uv_async_t ACH_UV_ASYNC_HANDLER;
extern bool uvRunningFlag;

// Init the UV async callback
void setupUVThread();

// Run a function on UV thread.
// This is the ONLY safe way to use uv loop. Even if it's non-blocking.
// The func MUST be microtask, otherwise the loop will be blocked.
// Only run things like deploying tasks!
void runOnUVThread(std::function<void()> func);

// If some blocking tasks must be created, put it here.
// Nothing will collect theses threads when exit.
// So make sure to exit normally!
void runOnWorkerThread(std::function<void()> func);

// Join the UV thread and close the loop
void stopUVThread();

}
}

#endif /* INCLUDE_ALICORN_CH_ACH_SYS_SCHEDULE */