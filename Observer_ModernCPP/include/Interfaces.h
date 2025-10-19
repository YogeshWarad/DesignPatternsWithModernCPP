#pragma once
#include <string>
class Observer;

#include <memory>

class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(std::shared_ptr<Observer*> observer) = 0;
    virtual void detach(std::shared_ptr<Observer*> observer) = 0;
    virtual void notify() = 0;
};

class Observer{
public:
    virtual ~Observer() = default;
    virtual void update(std::string &messageFromObersver)=0;
};