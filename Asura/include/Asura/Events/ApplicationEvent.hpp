#pragma once

#include "Event.hpp"
#include "Core.hpp"

#include <sstream>

namespace Asura {
    class ASURA_API WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() {}
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ASURA_API WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int w, unsigned int h) : _width(w), _height(h) {}

        inline unsigned int GetWidth()  const { return _width; };
        inline unsigned int GetHeight() const { return _height; };

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << _width << ", " << _height;
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryWindow)
    private:
        unsigned int _width, _height;
    };


}