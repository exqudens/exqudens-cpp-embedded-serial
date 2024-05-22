#pragma once

#include <cstdint>

namespace exqudens::embedded::serial {

    class IHardware {

        public:

            virtual int mainInit() = 0;

            virtual void delay(uint32_t microSeconds) = 0;

            virtual void setLedState(uint16_t led, bool state) = 0;

            virtual ~IHardware() noexcept = default;

    };

}
