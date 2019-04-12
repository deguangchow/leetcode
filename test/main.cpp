/////  Copyright (C) 2018 Mars/Venus Future.Inc
///      http://www.futuresoft.com.cn
///
/// \brief unit test project main function.
///
/// \author zhoudeguang
/// \version 1.0
/// \2019/04/12

#include "stdafx.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret = ::RUN_ALL_TESTS();
    return ret;
}

