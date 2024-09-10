#pragma once
#include <string>

namespace TelCoColorCoder
{
	enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
	enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

	class ColorPair {
		MajorColor majorColor;
		MinorColor minorColor;
	public:
		ColorPair(MajorColor major, MinorColor minor);
		MajorColor getMajorColor();
		MinorColor getMinorColor();

		std::string ToString();
		static void PrintReferenceManual();
	};

	ColorPair GetColorFromPairNumber(int pairNumber);

	int GetPairNumberFromColor(MajorColor major, MinorColor minor);
}
