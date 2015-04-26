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
	Projetor();

	/**
	 * Destrutor.
	 */
	virtual ~Projetor();

};

#endif /* PROJETOR_H_ */
