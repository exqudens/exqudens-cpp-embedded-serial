#include <string>
#include <stdexcept>

#include "exqudens/embedded/serial/Hardware.hpp"
#include "main.h"

namespace exqudens::embedded::serial {

    int Hardware::mainInit() {
        return HAL_Main_Init();
    }

    void Hardware::delay(uint32_t microSeconds) {
        HAL_Delay(microSeconds);
    }

    void Hardware::setLedState(uint16_t led, bool state) {
        if (led == 1u) {
            if (state) {
                HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
            } else {
                HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
            }
        } else {
            throw std::runtime_error("Unsupported led: " + std::to_string(led));
        }
    }

    Hardware::~Hardware() noexcept = default;

}
