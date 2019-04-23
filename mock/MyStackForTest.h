///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MyStackForTest
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/23

#pragma once
#ifndef MYSTACKFORTEST_H
#define MYSTACKFORTEST_H

#include "stdafx.h"


class MyStackForTest : public testing::Test {
protected:
    MyStack* pMyStack;
    virtual void SetUp() {
        pMyStack = new MyStack();
    }
    virtual void TearDown() {
        free(pMyStack);
    }
};

TEST_F(MyStackForTest, test_push) {
    EXPECT_NO_THROW(pMyStack->push(1));
    EXPECT_NO_THROW(pMyStack->push(2));

    EXPECT_NO_THROW(pMyStack->push(-1));
    EXPECT_NO_THROW(pMyStack->push(-2));

    EXPECT_NO_THROW(pMyStack->push(0));
    EXPECT_NO_THROW(pMyStack->push(-0));
}

TEST_F(MyStackForTest, test_pop) {
    //push
    EXPECT_NO_THROW(pMyStack->push(1));
    EXPECT_NO_THROW(pMyStack->push(2));

    EXPECT_NO_THROW(pMyStack->push(-1));
    EXPECT_NO_THROW(pMyStack->push(-2));

    EXPECT_NO_THROW(pMyStack->push(0));
    EXPECT_NO_THROW(pMyStack->push(-0));


    //pop
    EXPECT_EQ(0, pMyStack->pop());
    EXPECT_EQ(0, pMyStack->pop());

    EXPECT_EQ(-2, pMyStack->pop());
    EXPECT_EQ(-1, pMyStack->pop());

    EXPECT_EQ(2, pMyStack->pop());
    EXPECT_EQ(1, pMyStack->pop());
}

TEST_F(MyStackForTest, test_top) {
    //push
    EXPECT_NO_THROW(pMyStack->push(1));
    EXPECT_NO_THROW(pMyStack->push(2));

    //pop
    EXPECT_EQ(2, pMyStack->top());
    EXPECT_EQ(2, pMyStack->pop());

    EXPECT_EQ(1, pMyStack->top());
    EXPECT_EQ(1, pMyStack->pop());
}

#endif  //MYSTACKFORTEST_H
