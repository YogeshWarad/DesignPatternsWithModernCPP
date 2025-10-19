#pragma once
#include "Interfaces.h"
#include <vector>
#include <memory>

class ConcreteSubject : public Subject {
public:
    void attach(std::shared_ptr<Observer*> observer) override;
    void detach(std::shared_ptr<Observer*> observer) override;
    void notify() override;
private:
    std::vector<std::weak_ptr<Observer*>> observers;  // weak_ptrs to avoid owning observers
};