#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::ToString()
{
	switch (code)
	{
	case IndexOutsideLimit:
		return "Index is outside the limit";
	case MaxSizeReached:
		return "Max size reached";
	case Unknownmake:
		return "Unable to find this make";
	case UnknownModel:
		return "Unable to find this model";
	case UnableToOpenFile:
		return "Unable to open file";
	case NegativePrice:
		return "Price is negative";
	default:
		return "";
	}
}