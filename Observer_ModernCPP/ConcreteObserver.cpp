#include "include/ConcreteObserver.h"
#include <iostream>
#include <string>  

ConcreteObserver::ConcreteObserver() {
    // Constructor implementation (if needed)
}

void ConcreteObserver::update(std::string &messageFromObserver) {
    std::cout << "ConcreteObserver: " << messageFromObserver << std::endl;
}   