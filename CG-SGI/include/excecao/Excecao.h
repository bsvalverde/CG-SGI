#ifndef EXCECAO_H_
#define EXCECAO_H_

#include <exception>
#include <string>

/**
 * Exceção
 */
class Excecao : public std::exception {

public:
	/**
	 * Destrutor
	 */
	virtual ~Excecao() throw() { }

	/**
	 * Obter a mensagem da exceção como string de C
	 * @return A mensagem correspondente
	 */
	virtual const char* what() const throw() {
		return this->getMensagem().c_str();
	}

	/**
	 * Obter a mensagem da exceção como string de C++
	 * @return A mensagem correspondente
	 */
	virtual std::string getMensagem() const = 0;

};

#endif /* EXCECAO_H_ */
