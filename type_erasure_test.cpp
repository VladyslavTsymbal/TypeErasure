#include "mock_client.hpp"
#include "client.hpp"

class SomeClassThatUsesMyClient {
public:
    explicit SomeClassThatUsesMyClient(AnyClient client)
        : client_(std::move(client)) {}

    void run() {
        client_.foo();
        (void)client_.fooInt();
    }

private:
    AnyClient client_;
};

TEST(SomeClassTest, CallsFoo) {
    MockWrap mock;
    RealClient client;
    EXPECT_CALL(*mock, foo()).Times(1);
    EXPECT_CALL(*mock, fooInt()).WillOnce(testing::Return(10));

    AnyClient mock_client_wrapper(std::move(mock));
    AnyClient client_wrapper(std::move(client));

    SomeClassThatUsesMyClient sut{std::move(mock_client_wrapper)};
    SomeClassThatUsesMyClient another{std::move(client_wrapper)};

    sut.run();
    another.run();
}