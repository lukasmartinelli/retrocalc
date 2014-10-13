#include "sevensegment.h"
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <ostream>

Digit getDigit(unsigned int number) {
	if(number > 9) throw std::invalid_argument("Only digits from 0 to 9 are supported");
	return DIGITS.at(number);
}

void printDigits(std::ostream &out, std::vector<Digit> printableDigits, unsigned int lineCount) {
	Digit lines(lineCount);

	for(const auto digit : printableDigits) {
		for (auto it = digit.begin(); it != digit.end(); ++it) {
			auto index = std::distance(digit.begin(), it);
			lines.at(index).append(*it);
		}
	}

	for(auto line : lines) {
		out << line << "\n";
	}
}

void printLargeNumber(int number, std::ostream &out) {
	std::vector<Digit> printableDigits {};
	unsigned int positiveNumber { number < 0 ? -number : number };

	do {
		const unsigned int digit { positiveNumber % 10 };
		printableDigits.insert(printableDigits.begin(), getDigit(digit));
		positiveNumber /= 10;
	} while (positiveNumber > 0);

	if(number < 0) {
		printableDigits.insert(printableDigits.begin(), MINUS_SYMBOL);
	}

	printDigits(out, printableDigits, 5);
}

void printError(std::ostream &out) {
	printDigits(out, ERROR_DIGITS, 5);
}
