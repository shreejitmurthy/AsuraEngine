#pragma once

#include "Event.hpp"
#include "Core.hpp"

#include <cstdint>

namespace Asura {
    // KEYBOARD
    class ASURA_API KeyEvent : Event {
    public:
        inline std::uint32_t GetKeyCode() const { return _keyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    protected:
        KeyEvent(std::uint32_t keycode) : _keyCode(keycode) {}
        std::uint32_t _keyCode;
    };

    class ASURA_API KeyDownEvent : KeyEvent {
    public:
        KeyDownEvent(std::uint32_t keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}
        inline int GetRepeatCount() const { return _repeatCount; }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int _repeatCount;
    };

    class ASURA_API KeyReleasedEvent : KeyEvent {
    public:
        KeyReleasedEvent(std::uint32_t keycode) : KeyEvent(keycode) {}

        EVENT_CLASS_TYPE(KeyReleased)
    };

    // MOUSE
    class ASURA_API MouseMovedEvent : Event {
    public:
        MouseMovedEvent(float x, float y) : _mouseX(x), _mouseY(y) {}
        
        inline float X() { return _mouseX; }
        inline float Y() { return _mouseY; }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float _mouseX, _mouseY;
        float _mouseRelX, _mouseRelY;
    };

    class ASURA_API MouseButtonEvent : Event {
    public:
        inline std::uint8_t GetMouseButton() const { return _button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(std::uint8_t button, float x, float y) : _button(button), _x(x), _y(y) {}
        std::uint8_t _button;
        float _x, _y;
    };

    // SDL: bool down = true
    class ASURA_API MouseButtonDownEvent : MouseButtonEvent {
    public:
        MouseButtonDownEvent(std::uint8_t button, float x, float y) : MouseButtonEvent(button, x, y) {}
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    // SDL: bool down = false
    class ASURA_API MouseButtonReleasedEvent : MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(std::uint8_t button, float x, float y) : MouseButtonEvent(button, x, y) {}
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}