#include "PhotoReader.h"

PhotoReader::PhotoReader()
{	
}

PhotoReader::~PhotoReader()
{
}

std::shared_ptr<PhotoReader>
PhotoReader::GetInstance()
{
	if (!myPhotoReader)
	{
		myPhotoReader = std::make_shared<PhotoReader>(PhotoReader());
	}

	return myPhotoReader;
}

std::shared_ptr<PhotoReader> PhotoReader::myPhotoReader;

