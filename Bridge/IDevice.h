#include <iostream>
#include <memory>
#include <string>

// The "Implementor" interface
class IDevice {
public:
    virtual ~IDevice() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setVolume(int level) = 0;
    virtual bool isEnabled() const = 0;
};
