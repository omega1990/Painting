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

	std::shared_ptr<PhotoObject> pixels = reader->ReadBMP("C:\\Users\\Darko i Jelena\\Desktop\\lena.bmp");

	painter->ConfigureCanvasSize(pixels->width, pixels->height);
	painter->PaintPhoto(threads, *pixels);


	for (auto& thrd : threads)
	{
		thrd.join();
	}



	

	ReleaseDC(*painter->GetConsole(), *painter->GetDc());
	std::cin.ignore();
	return 0;
}