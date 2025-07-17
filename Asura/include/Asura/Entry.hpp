#pragma once

#ifdef AS_PLATFORM_MACOS

extern Asura::Application* Asura::CreateApplication();

int main(int argc, char** argv) {
    auto app = Asura::CreateApplication();
    app->Run();
    delete app;
}

#endif