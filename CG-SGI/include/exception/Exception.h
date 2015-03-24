#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
#include <string>

/**
 * Exce��o
 */
class Exception : public std::exception {

public:
	/**
	 * Destrutor
	 */
	virtual ~Exception() throw() { }

	/**
	 * Obter a mensagem da exce��o como string de C
	 * @return A mensagem correspondente
	 */
	virtual const char* what() const throw() {
		return this->getMessage().c_str();
	}

	/**
	 * Obter a mensagem da exce��o como string de C++
	 * @return A mensagem correspondente
	 */
	virtual std::string getMessage() const = 0;

};

#endif /* EXCEPTION_H_ */
