#include "aspch.h"

#include "Application.hpp"

#include "../include/Asura/Events/ApplicationEvent.hpp"
#include "../include/Asura/Events/InputEvent.hpp"
#include <spdlog/spdlog.h>

void OnEvent(Asura::Event& e) {
    Asura::EventDispatcher dispatcher(e);
    // Specific for a WindowResizeEvent
    dispatcher.Dispatch<Asura::WindowResizeEvent>([](Asura::WindowResizeEvent& e) {
        spdlog::info(e.ToString());
        return true;
    });
}

namespace Asura {
    Application::Application() {
    }

    Application::~Application() {  
    }
    
    void Application::Run() {
        EventBus bus;
        bus.PushEvent(new WindowResizeEvent(1200, 720));
        bus.DispatchAll(OnEvent);
    }
}