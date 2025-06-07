#include <gtest/gtest.h>
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include <gmock/gmock.h>

class MockFlyBehavior : public FlyBehavior {
public:
    MOCK_METHOD(void, fly, (), (override));
};

class MockQuackBehavior : public QuackBehavior {
public:
    MOCK_METHOD(void, quack, (), (override));
};


class DuckTest : public ::testing::Test {
protected:
    Duck duck;
    MockFlyBehavior* mockFly;
    MockQuackBehavior* mockQuack;

    void SetUp() override {
        mockFly = new MockFlyBehavior();
        mockQuack = new MockQuackBehavior();
        duck.setFlyBehavior(mockFly);
        duck.setQuackBehavior(mockQuack);
    }

    void TearDown() override {
        delete mockFly;
        delete mockQuack;
    }
};

TEST_F(DuckTest, PerformFlyCallsCorrectBehavior) {
    EXPECT_CALL(*mockFly, fly()).Times(1);
    duck.performFly();
}

TEST_F(DuckTest, PerformQuackCallsCorrectBehavior) {
    EXPECT_CALL(*mockQuack, quack()).Times(1);
    duck.performQuack();
}

TEST_F(DuckTest, SwimPrintsCorrectMessage) {
    testing::internal::CaptureStdout();
    duck.swim();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "swimming\n");
}
TEST_F(DuckTest, DisplayPrintsDefaultMessage) {
    testing::internal::CaptureStdout();
    duck.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "I am a duck\n");
}

TEST_F(DuckTest, SetFlyBehaviorChangesStrategy) {
    auto* newFly = new MockFlyBehavior();
    EXPECT_CALL(*newFly, fly()).Times(1);
    
    duck.setFlyBehavior(newFly);
    duck.performFly();
    
    delete newFly;
}

TEST_F(DuckTest, SetQuackBehaviorChangesStrategy) {
    auto* newQuack = new MockQuackBehavior();
    EXPECT_CALL(*newQuack, quack()).Times(1);
    
    duck.setQuackBehavior(newQuack);
    duck.performQuack();
    
    delete newQuack;
}

TEST(DuckInitializationTest, DefaultBehaviorIsNull) {
    Duck testDuck;
    testing::internal::CaptureStdout();
    testDuck.swim();
    testDuck.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "swimming\nI am a duck\n");
}
