#ifndef _TEST_NN_HPP
#define _TEST_NN_HPP

#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <cstring>
#include <vector>

#include "gtutils.hpp"

#include "ex/ex.hpp"

struct MatrixState
{
    std::vector<float> x;
    std::vector<float> y;
    const float prod;
};

struct MatrixTest : testing::Test, testing::WithParamInterface<MatrixState>
{
    MatrixTest() {}
};

struct ActivationState
{
    void(*func)(std::vector<float>&);
    std::vector<float> z;
    const std::vector<float> a;
};

struct ActivationTest : testing::Test, testing::WithParamInterface<ActivationState>
{
    ActivationTest() {}
};

#endif