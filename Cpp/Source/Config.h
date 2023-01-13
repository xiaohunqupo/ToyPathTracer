
#if defined(__APPLE__) && !defined(__METAL_VERSION__)
#include <TargetConditionals.h>
#endif

#define kBackbufferWidth 1280
#define kBackbufferHeight 720

#if defined(__EMSCRIPTEN__)
#define CPU_CAN_DO_SIMD 0
#else
#define CPU_CAN_DO_SIMD 1
#endif

#if defined(__EMSCRIPTEN__) && !defined(__EMSCRIPTEN_PTHREADS__)
#define CPU_CAN_DO_THREADS 0
#else
#define CPU_CAN_DO_THREADS 1
#endif


#define DO_SAMPLES_PER_PIXEL 4
#define DO_ANIMATE_SMOOTHING 0.9f
#define DO_LIGHT_SAMPLING 1
#define DO_MITSUBA_COMPARE 0

// GPU tracing compute shader parameters
#define kCSGroupSizeX 8
#define kCSGroupSizeY 8
#define kCSMaxObjects 64

// Should float3 struct use SSE/NEON?
#define DO_FLOAT3_WITH_SIMD (CPU_CAN_DO_SIMD && 1)

// Should HitSpheres function use SSE/NEON?
#define DO_HIT_SPHERES_SIMD (CPU_CAN_DO_SIMD && 1)
