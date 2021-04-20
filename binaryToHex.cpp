#include <iostream>
#include "string"
#include <cmath>

void binaryHex(std::string &number);
std::string reverseString(std::string &hexvalue);

char decimalToHexTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'};

int main()
{
    std::string binaryNumber = "10111101010111110";
    binaryHex(binaryNumber);
}

void binaryHex(std::string &number)
{

    std::string storeHexString = "";

    for (size_t i = number.size() - 1; i < number.size(); i -= 4)
    {

        int interval = 0;
        int position = i;
        int partionSum = 0;

        while (interval < 4)
        {
            if (number[position] == '1')
            {
                partionSum += std::pow(2, interval);
            }

            position--;
            interval++;
        }
        storeHexString += decimalToHexTable[partionSum];
    }
    storeHexString += "x0";
    std::cout << reverseString(storeHexString) << "\n";
}

std::string reverseString(std::string &hexvalue)
{

    std::string hexCode = "";
    for (int i = hexvalue.size(); i >= 0; i--)
    {
        hexCode += hexvalue[i];
    }
    return hexCode;
}
