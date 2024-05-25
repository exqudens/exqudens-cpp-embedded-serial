#pragma once

#include "exqudens/embedded/serial/IHardware.hpp"

namespace exqudens::embedded::serial {

    class Application {

        private:

            IHardware* hal = nullptr;
            bool running = true;

        public:

            static Application& getInstance();

            Application& setRunning(bool value);

            Application& setHal(IHardware* value = nullptr);
            IHardware* getHal();

            int run();

        private:

            Application();

            ~Application();

    };

}
