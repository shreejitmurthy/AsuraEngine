#pragma once

#include "Core.hpp"

namespace Asura {
    class ASURA_API Application {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // Defined in client
    Application* CreateApplication();
}
