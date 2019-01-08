#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>

namespace AMA {
	class ErrorState {
		char* errorMessage;

	public:

		explicit ErrorState(const char* = nullptr);

		ErrorState(const ErrorState&) = delete;

		ErrorState& operator=(const ErrorState&) = delete;

		~ErrorState();

		void clear();

		bool isClear() const;

		void message(const char*);

		const char* message() const;
	};
	std::ostream& operator << (std::ostream&, const ErrorState&);
}
#endif
