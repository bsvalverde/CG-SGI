#ifndef FORMINSERCAOOBJETO_H_
#define FORMINSERCAOOBJETO_H_

#include <QtWidgets/qcolordialog.h>

#include "controle/ControladorUI.h"
#include "geometria/Ponto.h"
#include "gui/forms/Form.h"
#include "gui/forms/ui/ui_FormInsercaoObjeto.h"

/**
 * Formulário de inserção de objetos.
 */
class FormInsercaoObjeto : public Form, private Ui::FormInsercaoObjeto {
	Q_OBJECT

public:
	/**
	 * Construtor.
	 * @param controladorUI controlador da interface gráfica.
	 * @param pai formulário pai.
	 * @param flags flags de propriedades do formulário.
	 */
	FormInsercaoObjeto(ControladorUI* controladorUI, QWidget* pai = 0, Qt::WindowFlags flags = Qt::Widget);

	/**
	 * Limpar conteúdo dos campos.
	 */
	void limparCampos();

protected:
	/**
	 * Conectar os sinais e slots dos objetos do formulário.
	 */
	void conectarSinaisSlots();

	/**
	 * Validar valor dos campos.
	 * @return true caso todos os campos tenham valores válidos.
	 */
	bool validarCampos();

private slots:
	/**
	 * Botão de inserir objeto pressionado.
	 */
	void inserirObjeto();

	/**
	 * Botão de inserir ponto do polígono pressionado.
	 */
	void inserirPontoPoligono();

	/**
	 * Botão de remover ponto do polígono pressionado.
	 */
	void removerPontoPoligono();

	/**
	 * Botão de inserir ponto da B-Spline pressionado.
	 */
	void inserirPontoBSpline();

	/**
	 * Botão de remover ponto da B-Spline pressionado.
	 */
	void removerPontoBSpline();

	/**
	 * Botão de selecionar a cor do objeto pressionado.
	 */
	void selecionarCorObjeto();

};

#endif /* FORMINSERCAOOBJETO_H_ */
