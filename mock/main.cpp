///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    mock project main function.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22


#include "stdafx.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    int ret = ::RUN_ALL_TESTS();
    return ret;
}

