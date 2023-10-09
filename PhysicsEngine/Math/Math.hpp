#pragma once

#include <cfloat>
#include <cmath>

namespace Physics
{

#define PE_FLOAT_CMP(x, y) (fabsf((x) - (y)) <= FLT_EPSILON * fmaxf(1.0f, fmaxf(fabsf(x), fabsf(y))))

static constexpr float PE_PI = 3.14159265358979323846f;

constexpr float DegreesToRadians(float v)
{
    return v * (PE_PI / 180.0f);
}

constexpr float RadiansToDegress(float v)
{
    return v * (180.0f / PE_PI);
}

} // namespace Physics
