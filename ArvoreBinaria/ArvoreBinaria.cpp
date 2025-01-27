#include <iostream>
using namespace std;

// definicao de tipo
class No
{
private:
	No *esq, *dir;
	int valor;

NO* raiz = NULL;

public:
	No(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}

	int getChave()
	{
		return chave;
	}

	No* getEsq()
	{
		return esq;
	}

	No* getDir()
	{
		return dir;
	}

	void setEsq(No *no)
	{
		esq = no;
	}

	void setDir(No *no)
	{
		dir = no;
	}
};

// headers
// estrutura principal
void menu();
void inicializar();
void inserir();
void exibir();
void exibirQuantidade();



// funcoes auxiliares Arvore
NO* insereArvore(NO* no, int valor);
NO* criaNO(int valor);
int elementosArvore(NO* no);
void exibirElementosArvore(NO* no);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Arvore";
		cout << endl << endl;
		cout << "1 - Inicializar Arvore \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Inserir elemento \n";
		cout << "4 - Exibir elementos \n";

		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:exibirQuantidade();
			break;
		case 3: inserir();
			break;
		case 4: exibir();
			break;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// provisório porque não libera a memoria usada pela arvore
	NO* raiz = NULL;
	
	cout << "Arvore inicializada \n";

}


void inserir()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	if (raiz == NULL) {
		raiz = criaNO(valor);
	}
	else {
		 insereArvore(raiz, valor);
	}


}

void exibirQuantidade() {
	cout << "Quantidade de elementos: " << elementosArvore(raiz) << endl;
	
}

void exibir() {
	exibirElementosArvore(raiz);
}


NO* criaNO(int valor)
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

NO* insereArvore(NO* no, int valor)
{
	if(valor < no->getChave())
		{
	
			if(no->getEsq() == NULL)
			{
				No *novo_no = new No(valor);
				no->setEsq(novo_no); 
			}
			else
			{
				NO* insereArvore(no->getEsq(), valor);
			}
		}
		else if(valor > no->getChave())
		{
			if(no->getDir() == NULL)
			{
				No *novo_no = new No(valor);
				no->setDir(novo_no);
			}
			else
			{
				NO* insereArvore(no->getDir(), valor);
			}
}

int elementosArvore(NO* no)
{
	if (no == NULL) {
		return 0;
	}

	return 1 + elementosArvore(no->esq) + elementosArvore(no->dir);
}

void exibirElementosArvore(NO* no)
{
	 aux = raiz;
                     topo = NULL;

                     do {

                          while(aux != NULL) {

                                aux_pilha = new pilha();
                                aux_pilha -> num = aux;                 
                                aux_pilha -> prox = topo;
                                topo = aux_pilha;
                                aux = aux -> esq;
                            }

                          if(topo != NULL) {
                                aux_pilha = topo;
                                cout << aux_pilha -> num -> x << " ";
                                aux = topo -> num -> dir;
                                topo = topo -> prox;
                             }
                     } while(topo != NULL or aux != NULL);
               }    
            cout << endl;
}
