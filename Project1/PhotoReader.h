#pragma once
#include <memory>

#include "SingletonBase.h"

class PhotoReader : public SingletonBase<PhotoReader>
{
public:
	PhotoReader();
	~PhotoReader();
	std::shared_ptr<PhotoObject> ReadBMP(char * filename);

};



