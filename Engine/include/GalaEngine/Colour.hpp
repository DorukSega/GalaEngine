// Project: GalaEngine
// File: Colour.hpp
// Description: Colour struct and predefined colours.
// Authors: Colleen (@colleen05)
// https://github.com/colleen05/GalaEngine
// Distributed under the zlib license.

#pragma once

#include <raylib.h>
#include <string>

// Grey tones
#define C_BLACK		{0x00, 0x00, 0x00, 0xFF}
#define C_DKGREY	{0x55, 0x55, 0x55, 0xFF}
#define C_GREY		{0xAA, 0xAA, 0xAA, 0xFF}
#define C_WHITE		{0xFF, 0xFF, 0xFF, 0xFF}

// EGA colours
#define C_RED		{0xFF, 0x00, 0x00, 0xFF}
#define C_DKRED		{0x7F, 0x00, 0x00, 0xFF}

#define C_YELLOW	{0xFF, 0xFF, 0x00, 0xFF}
#define C_DKYELLOW	{0x7F, 0x7F, 0x00, 0xFF}

#define C_GREEN		{0x00, 0xFF, 0x00, 0xFF}
#define C_DKGREEN	{0x00, 0x7F, 0x00, 0xFF}

#define C_CYAN		{0x00, 0xFF, 0xFF, 0xFF}
#define C_DKCYAN	{0x00, 0x7F, 0x7F, 0xFF}

#define C_BLUE		{0x00, 0x00, 0xFF, 0xFF}
#define C_DKBLUE	{0x00, 0x00, 0x7F, 0xFF}

#define C_MAGENTA	{0xFF, 0x00, 0xFF, 0xFF}
#define C_DKMAGENTA	{0x7F, 0x00, 0x7F, 0xFF}

// Extra colours
#define C_ORANGE	{0xFF, 0x7F, 0x00, 0xFF}
#define C_BROWN		{0x7F, 0x55, 0x00, 0xFF}
#define C_PURPLE	{0x55, 0x00, 0xAA, 0xFF}
#define C_PINK		{0xFF, 0x7F, 0xFF, 0xFF}

namespace GalaEngine {
	struct Colour {
		uint8_t r, g, b, a;

		// Colour Lerp(Colour colour, float t);
		// std::string ToString();

		operator Color() {
			return Color{r, g, b, a};
		}
	};
}