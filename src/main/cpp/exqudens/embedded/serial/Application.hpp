#pragma once

#include "exqudens/embedded/serial/IHardware.hpp"

namespace exqudens::embedded::serial {

    class Application {

        private:

            inline static IHardware* hal = nullptr;
            inline static bool running = true;

        public:

            static void setRunning(bool running);

            static int run();

    };

}
