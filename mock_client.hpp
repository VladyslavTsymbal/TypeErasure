#pragma once

#include <gmock/gmock.h>

class MockClient {
public:
    MOCK_METHOD(void, foo, ());
    MOCK_METHOD(int, fooInt, ());
};

struct MockWrap {
    std::shared_ptr<MockClient> mock_;

    MockWrap()
        : mock_(std::make_shared<MockClient>()) {}

    void foo()
    {
        mock_->foo();
    }

    int fooInt()
    {
        return mock_->fooInt();
    }

    MockClient& operator*() {
        return *mock_;
    }
};