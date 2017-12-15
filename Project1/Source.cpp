#include <iostream>
#include <cmath>
#include <time.h> 

#include "Common.h"
#include "PhotoReader.h"
#include "Painter.h"

int main()
{
	srand(time(NULL));

	std::shared_ptr<PhotoReader> reader = PhotoReader::GetInstance();
	std::shared_ptr<Painter> painter = Painter::GetInstance();

	painter->ShowConsoleCursor(false);

	std::vector<std::thread> threads = std::vector<std::thread>();

	painter->CreateThread(threads);

	for (auto& thrd : threads)
	{
		thrd.join();
	}

	ReleaseDC(*painter->GetConsole(), *painter->GetDc());
	std::cin.ignore();
	return 0;
}