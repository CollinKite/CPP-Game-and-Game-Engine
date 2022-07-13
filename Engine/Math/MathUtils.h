#pragma once

namespace math
{
    const float Pi = 3.14159265359;
    const float DoublePi = 6.28318530718;
    const float HalfPi = 1.57079632679;

    inline float DegToRad(float degrees) 
    { 
        return degrees * (Pi / 180); 
    }

    inline float RadtoDeg(float radians)
    {
        return radians * (180 / Pi);
    }

    int sqr(int v)
    {
        return v * v;
    }
}