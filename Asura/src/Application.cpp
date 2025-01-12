#include "Application.hpp"

#include <spdlog/spdlog.h>

namespace Asura {
    Application::Application() {
    }

    Application::~Application() {  
    }
    
    void Application::Run() {
        spdlog::info("Hello from Asura!");
    }
}