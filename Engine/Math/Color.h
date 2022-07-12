#pragma once
#include <cstdint>

namespace crae
{
	//typedef unsigned char u8_t; Old version - defines unsigned char as a unsigned 8 bit
	//using u8_t = unsigned char; Modern Version does same thing

	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
}