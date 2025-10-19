#include "include/ConcreteSubject.h"
#include <algorithm>
#include <string>

void ConcreteSubject::attach(std::shared_ptr<Observer*> observer)
{
    if (!observer) return;
    // Prevent duplicates: compare owner_before or lock to compare raw ptr
    for (auto &w : observers) {
        if (auto s = w.lock()) {
            if (s == observer) return;
        }
    }
    observers.push_back(observer);
}

void ConcreteSubject::detach(std::shared_ptr<Observer*> observer) 
{
    if (!observer) return;
    observers.erase(std::remove_if(observers.begin(), observers.end(), [&](const std::weak_ptr<Observer>& w){
        auto s = w.lock();
        return !s || s == observer;
    }), observers.end());
}

void ConcreteSubject::notify() 
{
    std::string msg = "Subject changed";
    for(auto it = observers.begin(); it != observers.end();)
    {
        if(auto s = it->lock())
        {
            (*s)->update(msg);
            ++it;
        } else{
            it = observers.erase(it);
        }
    }
}
    
