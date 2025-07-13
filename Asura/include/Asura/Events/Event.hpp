#pragma once

#include "Asura/Core.hpp"

#include <ostream>

// https://www.youtube.com/watch?v=xnopUoZbMEk&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=9
namespace Asura {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        AppTick, AppUpdate, AppRender
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication   = 1 << 0,
        EventCategoryInput         = 1 << 1,
        EventCategoryKeyboard      = 1 << 2,
        EventCategoryMouse         = 1 << 3,
        EventCategoryMouseButton   = 1 << 4,
        EventCategoryWindow        = 1 << 5,
    };

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; }\
    virtual EventType GetEventType() const override { return GetStaticType(); }\
    virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

    class ASURA_API Event {
        friend class EventDispatcher;
    public:
        virtual ~Event() = default;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;

        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category) {
            return GetCategoryFlags() & category;
        }
    protected:
        bool _handled = false;
    };

    class EventDispatcher {
    public:
        EventDispatcher(Event& event) : _event(event) {}

        template<typename T, typename F>
        bool Dispatch(const F& func) {
            if (_event.GetEventType() == T::GetStaticType()) {
                _event._handled = func(static_cast<T&>(_event));
                return true;
            }
            return false;
        }

    private:
        Event& _event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }

}