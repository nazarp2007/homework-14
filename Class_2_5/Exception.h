#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Exception:public runtime_error
{
	const char* message;
public:
	Exception(const char* message) :runtime_error(message) {}
};