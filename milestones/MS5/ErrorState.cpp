#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"ErrorState.h"

using namespace std;

namespace AMA {

	ErrorState::ErrorState(const char* errorMessage_) {
		errorMessage = nullptr;
		if (errorMessage_ != nullptr) {
			message(errorMessage_);
		}
		else {
			clear();
		}
	}

	ErrorState::~ErrorState() {
		clear();
	}

	void ErrorState::clear() {
		delete[] errorMessage;
		errorMessage = nullptr;
	}

	bool ErrorState::isClear() const {
		bool result = false;
		if (errorMessage == nullptr) {
			result = true;
		}
		return result;
	}

	void ErrorState::message(const char* str_) {
		if (!isClear()){
			clear();		
		}
		int length = strlen(str_);
		errorMessage = new char[length + 1];
		strncpy(errorMessage, str_, length);
		errorMessage[length] = '\0';
	}

	const char* ErrorState::message() const {
		return errorMessage;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& ErrorState_) {
		if (!ErrorState_.isClear()) {
			os << ErrorState_.message();
		}
			return os;
	}
}
