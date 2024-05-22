#include <cstdlib>
#include <exception>

#include "exqudens/embedded/serial/Application.hpp"
#include "exqudens/embedded/serial/Hardware.hpp"

namespace exqudens::embedded::serial {

    void Application::setRunning(bool running) {
        Application::running = running;
    }

    int Application::run() {
        try {
            bool halDeleteRequired = false;

            if (hal == nullptr) {
                hal = new Hardware();
            }

            int result = hal->mainInit();

            if (result != EXIT_SUCCESS) {
                if (halDeleteRequired) {
                    delete hal;
                    hal = nullptr;
                }
                return result;
            }

            unsigned int shortMax = 4;
            unsigned int shortIndex = 0;
            do {
                if (shortIndex + 1 == shortMax) {
                    hal->delay(3000u);
                } else {
                    hal->setLedState(1, true);
                    hal->delay(500u);
                    hal->setLedState(1, false);
                    hal->delay(500u);
                }
                shortIndex = (shortIndex + 1) % shortMax;
            } while (running);

            if (halDeleteRequired) {
                delete hal;
                hal = nullptr;
            }

            return result;
        } catch (const std::exception& e) {
            return EXIT_FAILURE;
        } catch (...) {
            return EXIT_FAILURE;
        }
    }

}
