#pragma once
#include <variant>
#include <string>
#include <vector>
#include "ByteMethod.h"
#include "Null.h"
#include "Call.h"

class RuntimeVector;

class RuntimeStruct;

class NovFile;

class RuntimeContext
{
public:
	static Null* NULL_VALUE;

	using RuntimeElement = std::variant<int, RuntimeStruct*, std::string*, bool, Null*, RuntimeVector*>;

	NovFile* novFile;

	RuntimeContext(NovFile* file);

	/* Executing program initialization */
	void Initialize();

	/* Block constants */
	RuntimeContext::RuntimeElement GetConstant(int id);

	/* Stack management */
	void PushStack(RuntimeContext::RuntimeElement element);
	RuntimeContext::RuntimeElement PopStack();
	RuntimeContext::RuntimeElement PeekStack();
	RuntimeContext::RuntimeElement StackMinus(int minus);
	void ResizeStack(int newSize);
	size_t GetStackSize();

	/* Runtime Structs */
	RuntimeStruct* CreateStruct(int classId);
	RuntimeStruct* GetCurrentStruct();

	/* Static Fields */
	RuntimeContext::RuntimeElement Get(int classId, int fieldId);
	void Set(int classId, int fieldId, RuntimeContext::RuntimeElement value);
	std::vector<Call> callStack;
	std::vector<RuntimeStruct*> structsStack;
private:
	std::vector<RuntimeElement> stack;
};

