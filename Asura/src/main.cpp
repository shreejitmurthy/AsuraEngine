/*
    Kept here as a reference for using Asura's dependencies, for now, not needed.
*/

#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define SOKOL_GFX_IMPL
#define SOKOL_GLCORE
#include <sokol_gfx.h>
#include <sokol_log.h>

#include <spdlog/spdlog.h>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        spdlog::error("ASURA::Initialise Error: {}", SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    const int screenWidth = 800;
    const int screenHeight = 600;

    SDL_Window* window = SDL_CreateWindow("Window", 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext ctx = SDL_GL_CreateContext(window);
    bool open = true;

    sg_desc desc;
    sg_setup(&desc);

    sg_pass_action pass_action = (sg_pass_action) {
        .colors[0] = {
            .load_action = SG_LOADACTION_CLEAR,
            .clear_value = { 0.2f, 0.3f, 0.3f, 1.0f }
        }
    };

    sg_swapchain swapchain = {
        .width = screenWidth,
        .height = screenHeight,
        .color_format = SG_PIXELFORMAT_RGBA8,
    };

    spdlog::info("ASURA::Initialised graphics");

    SDL_GL_SetSwapInterval(1);

    SDL_Event event;

    while (open) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    open = false;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE) {
                        open = false;
                    }
                    break;

                default:
                    break;
            }
        }

        sg_begin_pass((sg_pass){
            .action = pass_action,
            .swapchain = swapchain
        });
        sg_end_pass();
        sg_commit();  // Commit so we can be notified about the end/start of a frame (maybe useful later)

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_GL_DestroyContext(ctx);
    SDL_Quit();
    spdlog::info("ASURA::Goodbye!");

    return 0;
}
