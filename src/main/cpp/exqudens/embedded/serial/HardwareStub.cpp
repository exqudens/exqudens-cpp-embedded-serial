#include <string>
#include <stdexcept>

#include "exqudens/embedded/serial/Hardware.hpp"

namespace exqudens::embedded::serial {

    int Hardware::mainInit() {
        throw std::runtime_error("Not implemented!");
    }

    void Hardware::delay(uint32_t microSeconds) {
        throw std::runtime_error("Not implemented!");
    }

    void Hardware::setLedState(uint16_t led, bool state) {
        throw std::runtime_error("Not implemented!");
    }

    Hardware::~IHardware() noexcept = default;

}
