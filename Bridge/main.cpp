#include <iostream>
#include <memory>
#include "IDevice.h"
#include "RemoteControl.hpp"
#include "AdvancedRemoteControl.cpp"
#include "TV.hpp"
int main() 
{
    std::shared_ptr<IDevice> tv = std::make_shared<TV>();
    std::shared_ptr<IDevice> radio = std::make_shared<Radio>();

    RemoteControl remote(tv);
    AdvancedRemoteControl advancedRemote(radio);

    std::cout << "--- Using TV Remote ---\n";
    remote.togglePower();
    remote.volumeUp();
    remote.togglePower();

    std::cout << "\n--- Using Advanced Radio Remote ---\n";
    advancedRemote.togglePower();
    advancedRemote.volumeUp();
    advancedRemote.mute();
    advancedRemote.togglePower();

    return 0;
}
