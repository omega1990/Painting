#pragma once
#include "Common.h"

template <class T>
class SingletonBase
{
public:
	static std::shared_ptr<T> GetInstance()	
	{
		if (!myInstance)
		{
			myInstance = std::make_shared<T>(T());
		}

		return myInstance;
	};

private:
	static std::shared_ptr<T> myInstance;
};

template <class T>
std::shared_ptr<T> SingletonBase<T>::myInstance = nullptr;

