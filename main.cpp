#include <iostream>
#include <cassert>
#include "ColorPair.h"

/// <summary>
/// Tests NumberToPair
/// </summary>
void testNumberToPair(int pairNumber,
	TelCoColorCoder::MajorColor expectedMajor,
	TelCoColorCoder::MinorColor expectedMinor)
{
	TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair " << colorPair.ToString() << '\n';
	assert(colorPair.getMajorColor() == expectedMajor);
	assert(colorPair.getMinorColor() == expectedMinor);
}

/// <summary>
/// Tests PairToNumber
/// </summary>
void testPairToNumber(TelCoColorCoder::MajorColor major,
	TelCoColorCoder::MinorColor minor,
	int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << '\n';
	assert(pairNumber == expectedPairNumber);
}
void UnitTests()
{
	testNumberToPair(4, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::BROWN);
	testNumberToPair(5, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::SLATE);

	testPairToNumber(TelCoColorCoder::MajorColor::BLACK, TelCoColorCoder::MinorColor::ORANGE, 12);
	testPairToNumber(TelCoColorCoder::MajorColor::VIOLET, TelCoColorCoder::MinorColor::SLATE, 25);
}

int main()
{
	UnitTests();

	TelCoColorCoder::ColorPair::PrintReferenceManual();

	return 0;
}
