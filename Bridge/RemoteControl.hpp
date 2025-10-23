#include "IDevice.h"
#include<memory>
class RemoteControl {
protected:
    std::shared_ptr<IDevice> device;

public:
    explicit RemoteControl(std::shared_ptr<IDevice> dev) : device(std::move(dev)) {}
    virtual ~RemoteControl() = default;

    virtual void togglePower() {
        if (device->isEnabled())
            device->turnOff();
        else
            device->turnOn();
    }

    virtual void volumeUp() {
        std::cout << "Remote: Increasing volume.\n";
        device->setVolume(50);
    }

    virtual void volumeDown() {
        std::cout << "Remote: Decreasing volume.\n";
        device->setVolume(10);
    }
};
