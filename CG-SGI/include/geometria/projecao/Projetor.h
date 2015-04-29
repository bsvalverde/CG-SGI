#ifndef PROJETOR_H_
#define PROJETOR_H_

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
	 */
	Projetor(const TipoProjecao& tipo);

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

};

#endif /* PROJETOR_H_ */
