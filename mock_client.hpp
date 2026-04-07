#pragma once

#include <gmock/gmock.h>

class MockClient {
public:
    MOCK_METHOD(void, foo, ());
};