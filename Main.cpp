#include <iostream>
#include <string>
#include <limits.h>
#include "lib/RoundingLib.h"

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const std::string ABOUT_MESSAGE = "round";
const std::string CONTINUE_MESSAGE = "Continue? (y/n)>";
const std::string INCORRECT_MESSAGE = "Input is incorrect. Try again>";
const std::string INPUT_MESSAGE = "Input an integer>";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";

void ClearInputStream(std::istream &in);
int Seek(std::istream &in);
bool CheckBounds(int n, int leftBound, int rightBound);
int ReadInt(std::istream &in, int leftBound, int rightBound);
bool NeedContinue(std::istream &in);

int main()
{
    std::cout << ABOUT_MESSAGE << std::endl;
    bool cont = true;
    while (cont)
    {
        int a = ReadInt(std::cin, INT_MIN, INT_MAX);
        int b = ReadInt(std::cin, INT_MIN, INT_MAX);
        int c = ReadInt(std::cin, 0, INT_MAX);
        std::cout << OUTPUT_MESSAGE << Rounding(a, b, c) << std::endl;
        cont = NeedContinue(std::cin);
    }
    return 0;
}

void ClearInputStream(std::istream &in)
{
    in.clear();
    while (in.peek() != EOLN && in.peek() != EOF)
    {
        in.get();
    }
}

int Seek(std::istream &in)
{
    while (in.peek() != EOLN && SKIP_CHARACTERS.find((char)in.peek()) != std::string::npos)
    {
        in.get();
    }
    return in.peek();
}

bool CheckBounds(int n, int leftBound, int rightBound)
{
    return (leftBound <= n && n <= rightBound);
}

int ReadInt(std::istream &in, int leftBound, int rightBound)
{
    std::cout << INPUT_MESSAGE;
    int ans;
    in >> ans;
    while (!in || Seek(in) != EOLN || !CheckBounds(ans, leftBound, rightBound))
    {
        ClearInputStream(in);
        std::cout << INCORRECT_MESSAGE;
        in >> ans;
    }
    return ans;
}

bool NeedContinue(std::istream &in)
{
    std::cout << CONTINUE_MESSAGE;
    char ans;
    in >> ans;
    ans = std::toupper(ans);
    while (!in || Seek(in) != EOLN || ans != YES_CHAR && ans != NO_CHAR)
    {
        ClearInputStream(in);
        std::cout << INCORRECT_MESSAGE;
        in >> ans;
    }
    return ans == YES_CHAR;
}