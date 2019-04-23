///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MockMyStack
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#pragma once
#ifndef MOCKMYSTACK_H
#define MOCKMYSTACK_H

#include "stdafx.h"
#include "MyStack.h"

class MockMyStack : public MyStack {
public:
    MockMyStack() : MyStack() {}
    MOCK_METHOD1(push, void(int));
    MOCK_METHOD0(pop, int());
    MOCK_METHOD0(top, int());
    MOCK_METHOD0(empty, bool());
};



TEST(MockMyStack, MyStack) {
    MockMyStack mmst;

    EXPECT_CALL(mmst, push(::testing::_))
        .Times(2)
        .WillRepeatedly(::testing::Return());


    EXPECT_CALL(mmst, top())
        .Times(1)
        .WillOnce(::testing::Return(2));

    EXPECT_CALL(mmst, pop())
        .Times(2)
        .WillOnce(::testing::Return(2))
        .WillOnce(::testing::Return(1));

    EXPECT_CALL(mmst, empty())
        .Times(2)
        .WillOnce(::testing::Return(true))
        .WillOnce(::testing::Return(false));

    ON_CALL(mmst, empty())
        .WillByDefault(::testing::Return(true));


    mmst.push(1);
    mmst.push(2);
    mmst.empty();
    mmst.top();
    mmst.pop();
    mmst.pop();
    mmst.empty();
}



#endif  //MOCKMYSTACK_H
