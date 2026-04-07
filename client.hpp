#pragma once

#include <memory>
#include <utility>
#include <iostream>

class AnyClientRef {
public:
    struct Concept {
        virtual ~Concept() = default;
        virtual void foo() = 0;
    };

private:
    template <class T>
    struct Model final : Concept {
        T* object;

        explicit Model(T& obj) : object(std::addressof(obj)) {}

        void foo() override {
            object->foo();
        }
    };

public:
    template <class T>
    AnyClientRef(T& obj)
        : self_(std::make_unique<Model<T>>(obj)) {}

    void foo() {
        self_->foo();
    }

private:
    std::unique_ptr<Concept> self_;
};

class RealClient {
public:
    void foo() {
        std::cout << "Real Client: FOO\n";
    }
};