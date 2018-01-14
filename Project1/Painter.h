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

	void					ShowConsoleCursor(
								bool showFlag);

	int						GetRandomNumber(
								uint aStart, 
								uint aEnd);

	void					PaintRandomly(
								std::vector<std::thread>&	aOutThreads);

	void					PaintPhoto(
								std::vector<std::thread>&	aOutThreads,
								const PhotoObject&			aPhotoObject);

	COLORREF				GenerateRandomColor();

	std::pair<uint, uint>	GenerateRandomPixel(
								int aX, 
								int aY);

	std::shared_ptr<HWND>	GetConsole();
	std::shared_ptr<HDC>	GetDc();

	void					ConfigureCanvasSize(
								const unsigned int aWidth, 
								const unsigned int aHeight);

private:
	const HWND myConsole = GetConsoleWindow();
	const HDC myDc = GetDC(myConsole);

	unsigned int myCanvasWidth;
	unsigned int myCanvasHeight;

};

