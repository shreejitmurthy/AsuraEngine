#include <iostream>
#include <Asura.h>

class Sandbox : public Asura::Application {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

Asura::Application* Asura::CreateApplication() {
    return new Sandbox();
}