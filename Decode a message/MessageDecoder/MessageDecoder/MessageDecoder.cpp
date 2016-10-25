/** MessageDecoder
	MessageDecoder.cpp

    @author Thomas Eggleston
	@version 1.0 15/09/2016
*/

#include "stdafx.h"
#include "iostream"
#include "string"



/**
Converts an integer into an uppercase character or zero, if it is divisible by 27.
*/
char upperCase(int i)
{
	int j = i % 27;
	if (j == 0)
	{
		return 0;
	}
	return j + 'A' - 1;
}
/**
Converts an integer into an lowercase character or zero, if it is divisible by 27.
*/
char lowerCase(int i)
{
	int j = i % 27;
	if (j == 0)
	{
		return 0;
	}
	return j + 'a' - 1;
}
/**
Converts an integer into punctuation characters or zero, if divisible by 9.
*/
char punct(int i)
{
	int j = i % 9;

	switch (j)
	{
	case 0:
		return 0;  // Switch mode
	case 1:
		return 33;  // Exclaimation mark
	case 2:
		return 63;  // Question mark
	case 3:
		return 44;  // Comma
	case 4:
		return 46;  // Period
	case 5:
		return 32;  // Space
	case 6:
		return 59;  // Semi-colon
	case 7:
		return 34;  // Double-quote
	case 8:
		return 39;  // Single-quote
	default:
		return 0;
	}
}
/**
	Waits for keyboard input and converts character stream into decoded string.

*/
std::string messageDecoder()
{
	std::string output = "";

	int mode = 0;  // Start in uppercase mode
	int i = 0;  // Integer currently being read
	char c;  // Current character

	do
	{
		c = std::cin.get();
		i = c - '0';
		c = std::cin.get();

		while (c != 10 && c != 44)  // Stop if new line or comma
		{
			i *= 10;
			i += c - '0';
			c = std::cin.get();
		}

		char number;

		switch (mode)
		{
		case 0:  // Uppercase mode
			number = upperCase(i);
			if (number)
			{
				output += number;
			}
			else
			{
				mode++;
			}
			break;
		case 1:  // Lowercase mode
			number = lowerCase(i);
			if (number)
			{
				output += number;
			}
			else
			{
				mode++;
			}
			break;
		case 2:  // Punctuation mode
			number = punct(i);
			if (number)
			{
				output += number;
			}
			else
			{
				mode = 0;
			}
			break;
		default:
			break;
		}
	} while (c != 10);  // New line

	return output;
}

int main()
{
	std::string message = messageDecoder();
	std::cout << message << '\n';
	std::cin.get();
    return 0;
}

