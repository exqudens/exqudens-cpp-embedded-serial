#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "TestLogging.hpp"
#include "TestUtils.hpp"

namespace exqudens::embedded::serial {

    class OtherUnitTests : public testing::Test {

        protected:

            inline static const char* LOGGER_ID = "exqudens.embedded.serial.OtherUnitTests";

    }

    TEST_F(OtherUnitTests, test1) {
        try {
            std::string testGroup = testing::UnitTest::GetInstance()->current_test_info()->test_suite_name();
            std::string testCase = testing::UnitTest::GetInstance()->current_test_info()->name();
            TEST_LOG_I(LOGGER_ID) << "'" << testGroup << "." << testCase << "' start";

            // TODO

            TEST_LOG_I(LOGGER_ID) << "'" << testGroup << "." << testCase << "' end";
        } catch (const std::exception& e) {
            FAIL() << TestUtils::toString(e);
        }
    }

}
