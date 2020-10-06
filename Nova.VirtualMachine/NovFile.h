#include <string>
#include "ByteClass.h"
#include "MainPointEntry.h"
#include  "ByteMethod.h"

#pragma once
class NovFile
{
public:
	NovFile(std::string& fileName);
	bool Deserialize();
	std::vector<ByteClass*> byteClasses;
	MainPointEntry mainPointEntry;
	std::vector<RuntimeContext::RuntimeElement> constants;
	void Print();
	void Dispose();
	ByteMethod* GetMainMethod();

private:
	std::string fileName;
};

