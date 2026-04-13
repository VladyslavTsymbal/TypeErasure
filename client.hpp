#pragma once

#include <memory>
#include <utility>
#include <iostream>

class AnyClient {
public:
    struct Concept {
        virtual ~Concept() = default;
        virtual void foo() = 0;
        virtual int fooInt() = 0;
    };

private:
    template <class T>
    struct Model final : Concept {
        T object;

        explicit Model(T obj) : object(std::move(obj)) {}

        void foo() override {
            object.foo();
        }

        int fooInt() override {
            return object.fooInt();
        }
    };

public:
    template <class T>
    AnyClient(T& obj)
        : self_(std::make_unique<Model<T>>(obj)) {}

    void foo() {
        self_->foo();
    }

    int fooInt() {
        return self_->fooInt();
    }

private:
    std::unique_ptr<Concept> self_;
};

class RealClient {
public:
    void foo() {
        std::cout << "Real Client: FOO\n";
    }

    int fooInt() {
        return 5;
    }
};