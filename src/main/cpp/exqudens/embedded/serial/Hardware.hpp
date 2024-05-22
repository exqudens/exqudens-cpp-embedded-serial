#pragma once

#include "exqudens/embedded/serial/IHardware.hpp"

namespace exqudens::embedded::serial {

    class Hardware : public virtual IHardware {

        public:

            int mainInit() override;

            void delay(uint32_t microSeconds) override;

            void setLedState(uint16_t led, bool state) override;

            ~Hardware() noexcept override;

    };

}
