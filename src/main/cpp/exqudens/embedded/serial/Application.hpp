#pragma once

#include <memory>

#include "exqudens/embedded/serial/IHardware.hpp"

namespace exqudens::embedded::serial {

    class Application {

        private:

            std::shared_ptr<IHardware> hal = nullptr;
            bool running = true;

        public:

            static Application& getInstance();

            Application& setRunning(bool value);

            Application& setHal(const std::shared_ptr<IHardware> value = nullptr);
            std::shared_ptr<IHardware> getHal();

            int run();

        private:

            Application();

            ~Application();

    };

}
