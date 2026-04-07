
#include "mock_client.hpp"
#include "client.hpp"

class SomeClassThatUsesMyClient {
public:
    explicit SomeClassThatUsesMyClient(AnyClientRef client)
        : client_(std::move(client)) {}

    void run() {
        client_.foo();
    }

private:
    AnyClientRef client_;
};

TEST(SomeClassTest, CallsFoo) {
    MockClient mock;
    RealClient client;
    EXPECT_CALL(mock, foo()).Times(1);

    SomeClassThatUsesMyClient sut{AnyClientRef(mock)};
    SomeClassThatUsesMyClient another{AnyClientRef(client)};

    sut.run();
    another.run();
}