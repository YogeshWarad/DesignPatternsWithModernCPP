// Simple test main for Observer_ModernCPP
#include <iostream>
#include "include/ConcreteSubject.h"
#include "include/ConcreteObserver.h"
#include <memory>

int main() {
    auto subject = std::make_shared<ConcreteSubject>();
    auto observer1 = std::make_shared<ConcreteObserver>();
    auto observer2 = std::make_shared<ConcreteObserver>();

    subject->attach(std::static_pointer_cast<Observer*>(observer1));
    subject->attach(std::static_pointer_cast<Observer*>(observer2));

    subject->notify();

    // destroy observer1 and notify again to see weak_ptr cleanup
    observer1.reset();
    subject->notify();

    return 0;
}
