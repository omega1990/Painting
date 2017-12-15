#pragma once
#include <memory>
#include <windows.h>
#include <vector>
#include <thread>
#include <vector>
#include <random>

#include "Common.h"
#include "SingletonBase.h"

class Painter : public SingletonBase<Painter>
{
public:
	Painter();
	~Painter();

	void ShowConsoleCursor(bool showFlag);

	int GetRandomNumber(uint aStart, uint aEnd);

	COLORREF GenerateRandomColor();

	std::pair<uint, uint> GenerateRandomPixel(int aX, int aY);

	void CreateThread(std::vector<std::thread>& aOutThreads);

	std::shared_ptr<HWND> GetConsole();
	std::shared_ptr<HDC> GetDc();

private:
	const HWND myConsole = GetConsoleWindow();
	const HDC myDc = GetDC(myConsole);

};

