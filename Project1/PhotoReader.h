#pragma once
#include <memory>

class PhotoReader
{
public:
	PhotoReader();
	~PhotoReader();

	static std::shared_ptr<PhotoReader> GetInstance();

private: 
	static std::shared_ptr<PhotoReader> myPhotoReader;
};

