#pragma once

// From: https://www.youtube.com/watch?v=meARMOmTLgE&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=5
#if defined(__APPLE__) && defined(__MACH__)
    #define ASURA_API __attribute__((visibility("default")))
    #define AS_PLATFORM_MACOS
#elif _WIN64
    #ifdef AS_BUILD_DLL
        #define ASURA_API __declspec(dllexport)
    #else
        #define ASURA_API __declspec(dllimport)
    #endif
    #define AS_PLATFORM_WIN64
#else
    /* 
     * We'll only support macOS since that's the main development environment. 
     * Aim to test Windows and Linux as well at some point to add support for them.
     */
    #error ASURA::Only macOS supported for now.
#endif
