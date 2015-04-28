#ifndef FORMPRINCIPAL_H_
#define FORMPRINCIPAL_H_

#include <QtWidgets/qdesktopwidget.h>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qmenubar.h>

#include "controle/ControladorUI.h"
#include "gui/forms/ui/ui_FormPrincipal.h"
#include "gui/Viewport.h"

/**
 * Formulário principal.
 */
class FormPrincipal : public QMainWindow, private Ui::FormPrincipal {
	Q_OBJECT

public:
	/**
	 * Construtor.
	 * @param controladorUI controlador da interface gráfica.
	 * @param pai formulário pai.
	 * @param flags flags de propriedades do formulário.
	 */
	FormPrincipal(ControladorUI* controladorUI, QDialog* pai = 0, Qt::WindowFlags flags = Qt::Widget);

	/**
	 * Destrutor.
	 */
	virtual ~FormPrincipal();

	/**
	 * Mover o formulário para o centro.
	 */
	void centralizar();

	/**
	 * Obter o controlador de interface gráfica.
	 * @return o controlador.
	 */
	ControladorUI* getControladorUI();

	/**
	 * Atualizar a cena.
	 * @param objetos objetos a serem desenhados.
	 */
	void atualizarCena(const QList<ObjetoGeometrico*>& objetos);

protected:
	/**
	 * Conectar os sinais e slots dos objetos do formulário.
	 */
	void conectarSinaisSlots();

	/**
	 * Inicializar o menu da janela.
	 */
	void inicializarMenu();

private slots:
	/**
	 * Botão de zoom in pressionado.
	 */
	void zoomIn();

	/**
	 * Botão de zoom out pressionado.
	 */
	void zoomOut();

	/**
	 * Atualizar zoom.
	 * @param valorAtual valor atual de zoom.
	 */
	void atualizarZoom(int valorAtual);

	/**
	 * Botão de navegação para cima pressionado.
	 */
	void navegarCima();

	/**
	 * Botão de navegação para a esquerda pressionado.
	 */
	void navegarEsquerda();

	/**
	 * Botão de navegação para a direita pressionado.
	 */
	void navegarDireita();

	/**
	 * Botão de navegação para baixo pressionado.
	 */
	void navegarBaixo();

	/**
	 * Rotacionar a visualização.
	 * @param valorAtual valor atual de rotação.
	 */
	void rotacionarVisualizacao(int valorAtual);

	/**
	 * Reiniciar a visualização para as configurações padrão.
	 */
	void reiniciarVisualizacao();

	/**
	 * Botão de inserir objeto pressionado.
	 */
	void inserirObjeto();

	/**
	 * Botão de remover objeto pressionado.
	 */
	void removerObjeto();

	/**
	 * Botão de transformar objeto pressionado.
	 */
	void transformarObjeto();

	/**
	 * Botão de importar cena pressionado.
	 */
	void importarCena();

	/**
	 * Botão de exportar cena pressionado.
	 */
	void exportarCena();

	/**
	 * Botão de limpar cena pressionado.
	 */
	void limparCena();

	/**
	 * Ver atalhos do sistema.
	 */
	void atalhosSistema();

	/**
	 * Ver informações sobre o sistema.
	 */
	void sobreSistema();

	/**
	 * Encerrar o sistema.
	 */
	void encerrarSistema();

	/**
	 * Atualizar eixo de rotação atual.
	 * @param selecionado opção foi selecionada.
	 */
	void atualizarEixoRotacao(bool selecionado);

	/**
	 * Atualizar algoritmo de clipping.
	 */
	void atualizarAlgoritmoClipping(bool cohenSutherland);

	/**
	 * Atualizar tipo de projeção.
	 */
	void atualizarTipoProjecao(bool projecaoParalela);

private:
	ControladorUI* controladorUI;
	Viewport* viewport;
	int valorZoom;
	int valorRotacaoX;
	int valorRotacaoY;
	int valorRotacaoZ;

};

#endif /* FORMPRINCIPAL_H_ */
