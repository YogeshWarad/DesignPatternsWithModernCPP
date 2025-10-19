#pragma once
#include "Interfaces.h"

class ConcreteObserver : public Observer {
public:
    ConcreteObserver();
    void update(std::string &messageFromObserver) override;
};