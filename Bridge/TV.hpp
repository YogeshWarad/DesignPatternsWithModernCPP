#include "IDevice.h"
class TV : public IDevice {
private:
    bool on = false;
    int volume = 30;

public:
    void turnOn() override {
        on = true;
        std::cout << "TV is now ON.\n";
    }
    void turnOff() override {
        on = false;
        std::cout << "TV is now OFF.\n";
    }
    void setVolume(int level) override {
        volume = level;
        std::cout << "TV volume set to " << volume << ".\n";
    }
    bool isEnabled() const override { return on; }
};

class Radio : public IDevice {
private:
    bool on = false;
    int volume = 20;

public:
    void turnOn() override {
        on = true;
        std::cout << "Radio is now ON.\n";
    }
    void turnOff() override {
        on = false;
        std::cout << "Radio is now OFF.\n";
    }
    void setVolume(int level) override {
        volume = level;
        std::cout << "Radio volume set to " << volume << ".\n";
    }
    bool isEnabled() const override { return on; }
};
