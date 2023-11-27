#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// m�ximo de coisas
#define MAX_CLIENTES 10
#define MAX_PROCEDIMENTOS 10
#define MAX_CONSULTAS 10

// struct de clientes
struct Cliente {
	char nome[50];
	char nomePet[50];
	char telefone[50];
};

// struct de procedimentos
struct Procedimento {
	char nomePet[50];
	int tipo;
};

// struct de consulta
struct Consulta {
	char nomePet[50];
	int dia;
	int medico;
};

int i, j;
int numClientes = 0;

void petshop() {
	printf("Super_Petshop_Gabriel_ES\n");
}

void gabriel(struct Cliente clientes[], int *numClientes) {
	petshop();

	while (*numClientes < MAX_CLIENTES) {
		printf("Quantos clientes ser�o cadastrados (m�ximo %d)? ", MAX_CLIENTES - *numClientes);
		int numNovosClientes;
		scanf("%d", &numNovosClientes);
		system("cls");

		if (*numClientes + numNovosClientes > MAX_CLIENTES) {
			printf("N�mero de clientes excede o limite. Tente novamente.\n");
		} else {
			for (i = 0; i < numNovosClientes; i++) {
				petshop();
				printf("Digite o nome do cliente: \n");
				scanf("%s", clientes[*numClientes].nome);
				printf("Digite o nome do pet: \n");
				scanf("%s", clientes[*numClientes].nomePet);
				printf("Digite seu telefone: \n");
				scanf("%s", clientes[*numClientes].telefone);
				system("cls");
				(*numClientes)++;
			}
			break;
		}
	}
}

void imprimirRelatorio(struct Cliente clientes[], struct Procedimento procedimentos[], struct Consulta consultas[], int numClientes, int numProcedimentos, int numConsultas) {
	petshop();
	printf("Relat�rio:\n");

	for (i = 0; i < numClientes; i++) {
		printf("\n%d� Cliente: %s\nPet: %s\nTelefone: %s\n", i + 1, clientes[i].nome, clientes[i].nomePet, clientes[i].telefone);

		for (j = 0; j < numProcedimentos; j++) {
			if (strcmp(clientes[i].nomePet, procedimentos[j].nomePet) == 0) {
				char tipoProcedimento[10];
				if (procedimentos[j].tipo == 1) {
					strcpy(tipoProcedimento, "Banho");
				} else if (procedimentos[j].tipo == 2) {
					strcpy(tipoProcedimento, "Tosa");
				} else {
					strcpy(tipoProcedimento, "Banho e Tosa");
				}

				printf("Procedimento agendado para %s: %s\n", procedimentos[j].nomePet, tipoProcedimento);
				break;
			}
		}
	}

	for (i = 0; i < numConsultas; i++) {
		char diaConsulta[10];
		if (consultas[i].dia == 1) {
			strcpy(diaConsulta, "Segunda-feira");
		} else {
			strcpy(diaConsulta, "Quinta-feira");
		}

		char medicoConsulta[20];
		if (consultas[i].medico == 1) {
			strcpy(medicoConsulta, "Dr. Gabriel");
		} else {
			strcpy(medicoConsulta, "Dr. Fabiano");
		}

		printf("\nConsulta para %s agendada na %s com o m�dico %s", consultas[i].nomePet, diaConsulta, medicoConsulta);
	}

}

int main() {

	setlocale(LC_ALL, "portuguese");

	char senhaCorreta[] = "patinha";
	char senhaDigitada[20];

	do {
		petshop();
		printf("Digite a senha: ");
		scanf("%s", senhaDigitada);
		system("cls");

		if (strcmp(senhaDigitada, senhaCorreta) != 0) {
			printf("Senha incorreta. Tente novamente.\n");
		}
	} while (strcmp(senhaDigitada, senhaCorreta) != 0);

	int escolha;
	struct Cliente clientes[MAX_CLIENTES];
	struct Procedimento procedimentos[MAX_PROCEDIMENTOS];
	struct Consulta consultas[MAX_CONSULTAS];
	int numClientes = 0, numProcedimentos = 0, numConsultas = 0;

	do {
		petshop();
		printf("Menu Principal:\n");
		printf("1. Cadastrar Cliente\n");
		printf("2. Agendar Procedimento\n");
		printf("3. Agendar Consulta\n");
		printf("4. Imprimir Relat�rio\n");
		printf("5. Sair\n");
		printf("Escolha uma op��o: ");
		scanf("%d", &escolha);
		system("cls");

		switch (escolha) {
			case 1:
				gabriel(clientes, &numClientes);
				break;

			case 2:
				petshop();
				if (numProcedimentos < MAX_PROCEDIMENTOS) {
					printf("Quantos procedimentos ser�o agendados (m�ximo 10)? ");
					int numNovosProcedimentos;
					scanf("%d", &numNovosProcedimentos);
					system("cls");

					for (i = 0; i < numNovosProcedimentos; i++) {
						petshop();
						printf("Digite o nome do %d� pet novamente: ", i + 1);
						scanf("%s", procedimentos[numProcedimentos].nomePet);
						printf("Agendar banho (1), tosa (2) ou ambos (3)? ");
						scanf("%d", &procedimentos[numProcedimentos].tipo);
						system("cls");
						numProcedimentos++;
					}
				} else {
					petshop();
					printf("Limite m�ximo de procedimentos atingido.\n");
				}
				break;

			case 3:
				do {
					petshop();
					if (numConsultas < MAX_CONSULTAS) {
						printf("Lista de Clientes Cadastrados:\n");
						for (i = 0; i < numClientes; i++) {
							printf("%d. %s - Pet: %s\n", i + 1, clientes[i].nome, clientes[i].nomePet);
						}

						int escolhaCliente;
						printf("Escolha o n�mero do cliente para agendar a consulta: ");
						scanf("%d", &escolhaCliente);
						system("cls");

						if (escolhaCliente >= 1 && escolhaCliente <= numClientes) {
							strcpy(consultas[numConsultas].nomePet, clientes[escolhaCliente - 1].nomePet);

							petshop();
							printf("Agendar consulta para segunda-feira (1) ou quinta-feira (2)? ");
							scanf("%d", &consultas[numConsultas].dia);
							system("cls");

							petshop();
							printf("Escolha o m�dico para a consulta:\n");
							printf("1. Dr. Gabriel\n");
							printf("2. Dr. Fabiano\n");
							scanf("%d", &consultas[numConsultas].medico);
							system("cls");

							numConsultas++;

							petshop();
							printf("Deseja agendar outra consulta? (1 para Sim, 0 para N�o): ");
							int agendarOutra;
							scanf("%d", &agendarOutra);
							system("cls");
							if (agendarOutra != 1) {
								break;
							}
						} else {
							petshop();
							printf("Escolha inv�lida. Tente novamente.\n");
						}

						while (getchar() != '\n');
					} else {
						petshop();
						printf("Limite m�ximo de consultas atingido.\n");
						break;
					}
				} while (1);
				break;

			case 4:
				imprimirRelatorio(clientes, procedimentos, consultas, numClientes, numProcedimentos, numConsultas);
				printf("\n\nPressione Enter para continuar...");
				getchar();
				getchar();
				system("cls");
				break;

			case 5:
				petshop();
				printf("Volte sempre ao Super_Petshop_Gabriel_ES");
				break;

			default:
				petshop();
				printf("Op��o inv�lida. Tente novamente.\n");
		}

	} while (escolha != 5);

	return 0;
}

