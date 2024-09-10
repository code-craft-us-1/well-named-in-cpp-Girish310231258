#include "ColorPair.h"
#include <iostream>

namespace TelCoColorCoder
{
	const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
	int numberOfMajorColors = std::size(MajorColorNames);

	const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
	int numberOfMinorColors = std::size(MinorColorNames);

	MajorColor majorColor;
	MinorColor minorColor;

	ColorPair::ColorPair(MajorColor major, MinorColor minor)
	{
		majorColor = major;
		minorColor = minor;
	}

	MajorColor ColorPair::getMajorColor() {
		return majorColor;
	}

	MinorColor ColorPair::getMinorColor() {
		return minorColor;
	}

	/// <summary>
	/// Returns color pair for the given pair number
	/// </summary>    
	ColorPair GetColorFromPairNumber(int pairNumber)
	{
		int zeroBasedPairNumber = pairNumber - 1;
		majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
		minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
		return ColorPair(majorColor, minorColor);
	}

	/// <summary>
	/// Returns pair number for the given major and minor color
	/// </summary>    
	int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
		return major * numberOfMinorColors + minor + 1;
	}

	/// <summary>
	/// Returns the string representation of the color pair
	/// </summary>    
	std::string ColorPair::ToString()
	{
		std::string colorPairStr = MajorColorNames[majorColor];
		colorPairStr += " ";
		colorPairStr += MinorColorNames[minorColor];
		return colorPairStr;
	}

	/// <summary>
	/// Prints the Reference Manual
	/// </summary>
	void ColorPair::PrintReferenceManual()
	{
		auto totalPairNo = numberOfMajorColors * numberOfMinorColors;
		std::cout << "PairNumber" << "\t" << "Major" << " " << "Minor" << '\n';
		for (int i = 1; i <= totalPairNo; i++)
		{
			TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(i);
			std::cout << "\t" << i << "\t" << colorPair.ToString() << '\n';
		}
	}
}
