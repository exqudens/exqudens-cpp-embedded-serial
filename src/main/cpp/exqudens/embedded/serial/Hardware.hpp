#pragma once

#include "exqudens/embedded/serial/IHardware.hpp"

namespace exqudens::embedded::serial {

    class Hardware : public virtual IHardware {

        private:

            std::function<void(uint8_t* buffer, uint32_t* length)> usbTransferFunction = {};

        public:

            int mainInit() override;

            void delay(uint32_t microSeconds) override;

            void setLedState(uint16_t led, bool state) override;

            void setUsbTransferFunction(const std::function<void(uint8_t* buffer, uint32_t* length)>& value) override;
            std::function<void(uint8_t* buffer, uint32_t* length)> getUsbTransferFunction() override;

            ~Hardware() noexcept override;

    };

}
