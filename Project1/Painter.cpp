#include "Painter.h"



Painter::Painter()
{
}


Painter::~Painter()
{
}


void Painter::ShowConsoleCursor(
	bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int Painter::GetRandomNumber(
	uint aStart = 0,
	uint aEnd = 255)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(aStart, aEnd);

	return dist(rng);
}

COLORREF Painter::GenerateRandomColor()
{
	return RGB(GetRandomNumber(), GetRandomNumber(), GetRandomNumber());
}

std::pair<uint, uint> Painter::GenerateRandomPixel(
	int aX = 0,
	int aY = 0)
{
	uint startX = aX > 0 ? aX - 1 : aX;
	uint startY = aY > 0 ? aY - 1 : aY;

	uint endX = aX > MAX_WIDTH - 1 ? MAX_WIDTH - 1 : aX + 1;
	uint endY = aY > MAX_HEIGHT - 1 ? MAX_HEIGHT - 1 : aY + 1;

	uint x = GetRandomNumber(startX, endX);
	uint y = GetRandomNumber(startY, endY);

	return std::make_pair(x, y);
}

void Painter::CreateThread(
	std::vector<std::thread>& aOutThreads)
{
	for (uint i = 0; i < NUMBER_OF_THREADS; i++)
	{
		aOutThreads.push_back(std::thread([&]()
		{
			std::pair<uint, uint> randomPixel =
				GenerateRandomPixel(GetRandomNumber(0, MAX_WIDTH), GetRandomNumber(0, MAX_HEIGHT));

			COLORREF color = GenerateRandomColor();

			while (true)
			{
				SetPixel(myDc, randomPixel.first, randomPixel.second, color);
				randomPixel = GenerateRandomPixel(randomPixel.first, randomPixel.second);
			}
		}));
	}
}

std::shared_ptr<HWND> 
Painter::GetConsole()
{
	return std::make_shared<HWND>(myConsole);
}

std::shared_ptr<HDC>
Painter::GetDc()
{
	return std::make_shared<HDC>(myDc);
}