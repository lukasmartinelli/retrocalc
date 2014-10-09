#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "digit.h"
#include <vector>
#include <stdexcept>

void getDigitReturnsCorrectSegmentsForNumberZero() {
	//Act
	auto digit = getDigit(0);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL("   ",digit.at(2));
	ASSERT_EQUAL("| |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberOne() {
	//Act
	auto digit = getDigit(1);

	//Assert
	ASSERT_EQUAL("   ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL("   ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberTwo() {
	//Act
	auto digit = getDigit(2);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("|  ",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberThree() {
	//Act
	auto digit = getDigit(3);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberFour() {
	//Act
	auto digit = getDigit(4);

	//Assert
	ASSERT_EQUAL("   ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberFive() {
	//Act
	auto digit = getDigit(5);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("|  ",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberSix() {
	//Act
	auto digit = getDigit(6);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("|  ",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("| |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberSeven() {
	//Act
	auto digit = getDigit(7);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL("   ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberEight() {
	//Act
	auto digit = getDigit(8);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("| |",digit.at(3));
	ASSERT_EQUAL(" ̣̣- ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberNine() {
	//Act
	auto digit = getDigit(9);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitBiggerThanTenThrowsInvalidArgException() {
	//Act & Assert
	ASSERT_THROWS(getDigit(10), std::invalid_argument);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;

	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberZero));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberOne));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberTwo));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberThree));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberFour));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberFive));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberSix));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberSeven));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberEight));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberNine));
	s.push_back(CUTE(getDigitBiggerThanTenThrowsInvalidArgException));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



