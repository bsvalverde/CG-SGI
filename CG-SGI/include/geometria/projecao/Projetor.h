#ifndef PROJETOR_H_
#define PROJETOR_H_

class Window;

/**
 * Projetor.
 */
class Projetor {

public:
	/**
	 * Tipo de projeção implementada pelo projetor.
	 */
	enum TipoProjecao {
		PARALELA_ORTOGONAL,
		PERSPECTIVA
	};

	/**
	 * Construtor.
	 * @param tipo tipo de projeção.
	 * @param window janela de visualização.
	 */
	Projetor(const TipoProjecao& tipo, Window* const window);

	/**
	 * Destrutor.
	 */
	virtual ~Projetor();

	/**
	 * Obter o tipo de projeção.
	 * @return tipo de projeção.
	 */
	TipoProjecao getTipo() const;

private:
	TipoProjecao tipo;
	Window* window;

};

#endif /* PROJETOR_H_ */
