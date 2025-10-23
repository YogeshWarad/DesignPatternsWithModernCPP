#include "RemoteControl.hpp"
class AdvancedRemoteControl : public RemoteControl {
public:
    using RemoteControl::RemoteControl;

    void mute() {
        std::cout << "Remote: Muting device.\n";
        device->setVolume(0);
    }
};
