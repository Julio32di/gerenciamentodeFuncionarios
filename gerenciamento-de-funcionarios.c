#include <stdio.h> // responsavel comunica��o dos usu�rio 
#include <stdlib.h>//aceita��o de caractere
#include <locale.h> // Essa bliblioteca  do meu codigo, vai fazer aloc�oes de texto 
#include <string.h>//  Essa bliblioteca que fica respons�vel por cuidar das strings

int registroFuncionario () 
{ 
	//Inicio de vari�veis/stringsTT
		char arquivo[40];                         
		char cpfFuncionario [40];
		char nomeFuncionario [40];
		char sobrenomeFuncionario[40];
		char cargoFuncionario[40];
		char QuantidadeUniformes[10];
		//fim da cria��o de vari�veis do tipo strings

		printf(" Digite  o Nome do Funcionario a Cadastrado:  ",nomeFuncionario);
		scanf("%s",nomeFuncionario);//%s refere-se a strings

		strcpy(arquivo, nomeFuncionario);//Respons�vel por criar os valores das nossas strings

		FILE*file ;//criando um arquivo
		file = fopen(arquivo, "w");//criando  um arquivo new e o "W" significa novo.
		fprintf(file, nomeFuncionario);// abrindo o arquivo file e (salvo o valor da vari�vel)
		fclose (file); // aqui fecho o arquivo
		system ("cls"); // limpo a tela para as proximas linha do meu c�digo

		file = fopen (arquivo, "a"); // aqui atualizo o meu arquivo
		fprintf(file, ","); // "," coloco uma virg�la para separar as informa��es coletadas
		fclose(file);

		printf("Digite o  sobrenome do Funcionario a ser Cadastrado: ");
		scanf("%s", sobrenomeFuncionario);

		file = fopen (arquivo, "a");
		fprintf(file, sobrenomeFuncionario);
		fclose (file);
		system ("cls");

		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);

		printf("Digite o CPF do Funcionario a ser cadastrado:  ");
		scanf("%s",cpfFuncionario);

		file = fopen (arquivo, "a");
		fprintf(file, cpfFuncionario);
		fclose (file);
		system ("cls");

		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);

		printf("Digite o Cargo do Funcionario a ser Cadastrado:  ");
		scanf("%s", cargoFuncionario);

		file = fopen (arquivo, "a");
		fprintf(file, cargoFuncionario);
		fclose (file);
		system ("cls");

		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);

		printf("Quantidade de uniformes do Funcionario:  ");
		scanf("%s",  QuantidadeUniformes);

		file = fopen(arquivo, "a");
		fprintf(file,QuantidadeUniformes);
		fclose(file);
		system ("cls");// limpando a tela


		printf("Registro de Funcionario Efetuado com Sucesso.");
		printf("\n\n");

		system ("pause");// pauso o programa e pe�o como parametro que o usu�rio pressione uma tecla para continuar

}

int consultaFuncionario ()// fun��o Responsavel por consultar os nomes ja cadastrado banco de dados 
{ 
	setlocale(LC_ALL, "Portuguese"); // fazendo o meu codigo aceitar acentua��oes

	char cpf [40];//declarando vari�veis da fun��o consultar e falando que � para salvar s� as 40 primeira caractere colocadas pelo usu�rio
	char nome [40];
	char conteudo[200];

	printf("Digite o nome do Funcionario a ser Consultado: ");
	scanf("%s",cpf);

	FILE * file;//consultando o arquivo
	file = fopen (cpf, "r");//lendo o arquivo DadosFunFlow


	if (file == NULL) 
	{ //valida��o de erros na busca se for NULL exibir esse printf
		printf("\t N�o foi possivel consultar esse Cpf! Esse CPF n�o existe. ");

	}
	while(fgets(conteudo,200,file) !=NULL);//validacao enquanto
	{
		printf("\t\n Essas s�o as informa��oes do Funcionario:\n");
		printf("\n\n");// pulando duas linhas
		printf("\t"); // colocando um espa�o antes da proxima linha
		printf("%s", conteudo);

	}

	system("pause");
	fclose(file);//fechei / arquivo consulta
}

int deletarFuncionario  () 
{
	//inicio de vari�veis / strings
	char name [40];
	// fim de vari�veis/ strings


	printf ("Digite o funcion�rio voce quer Deletar do Sistema?\n\n" );// input informac�es do usu�rio
	printf("Selecionando Funcionario: ");

	scanf("%s", name); // dando valor a vari�vel name do tipo %s
	printf("\n\n");

	FILE * file;// consultando o arquivo
	file = fopen (name, "r"); // lendo o arquivo

	if (file == NULL)
	{ // condi��o se n�o haver valor ou numeros fa�a
		printf(" O Funcionario ");
		printf(name);
		printf (" N�o se encontra no sistema!\n Por favor tente novamente com outro nome que esteja no sistema.\n");// mostrando o nome que esta sendo deletado do sistema e a msg de nao encontrado.
		printf("\n");// pulando linhas
		printf("pause");
		fclose(file);
	}  
	else 
	{
		fclose(file);
		remove(name);//fun��o de remove vai apagar o nada e se estiver um arquivo tamb�m
		printf(" O Funcionario " "");
		printf(name);
		printf("foi Exclu�do do sistema com sucesso\n\n");
		fclose(file);
	}
	system("pause");

}
int main() 
{

	// declarando as stringd/ vari�veis
	int OpcoesMenuRegistro=0;
	int lacosRepeatMenu=1;
	int ComparacaoStringsPasswoard;
	char PasswoardAdiministrador[]="a";

	// fim das strings/vari�veis

	setlocale(LC_ALL, "Portuguese");// aceitar caractere

	
	do 
	   {
			printf("\t### RH SejaFlow ###\n\n");
			printf("Login do administrador \n\n Digite a senha do adiministrador: ");
			scanf("%s",PasswoardAdiministrador);

			ComparacaoStringsPasswoard = strcmp(PasswoardAdiministrador, "admin");
	
	
	
			// colocando a minha valida��o por senha do meu programa.
			system("cls");
			if (ComparacaoStringsPasswoard == 0) 
			{
				//inicio do laco de repeat 1
				for(lacosRepeatMenu=1; lacosRepeatMenu=1;)
			 	{
					system("cls"); //Limpar a tela
					setlocale(LC_ALL, "Portuguese");//Definindo a linguagem que vai ser o meu programa

					printf("\t### RH SejaFlow ###\n\n");//Definindo o titulo do programa
			   		printf("\tEscolha a op��es que Deseja Executar Abaixo: \n\n");//definindo op��oes do meu menu 1,2,3
	
			 		//Inicio do Menu
					printf("\tCadastrando Funcionario\n ");
			   		printf("\t\t1 - Nome do Funcionario\n");
					printf("\t\t2 - Consulta de Nomes \n");
					printf("\t\t3 - Deletar funcionario \n");
					printf("\t\t4 - Sair do sistema \n\n");
					printf("\tSelecionar op��o:  ");
					// fim do menu

					scanf("%d",&OpcoesMenuRegistro);//armazenando as  escolhas do usu�rio

					system ("cls");

					//inicio da sele��o
					switch (OpcoesMenuRegistro) 
					{ // usando a condi��o	SWITCH
						case 1:
						registroFuncionario();
						break;

						case 2:
						consultaFuncionario();
						break;

						case 3:
						deletarFuncionario();
						break;

						case 4:
						printf("Obrigado por utilizar o nosso sistema\n ");
						return 0; // Quebrar de todos os la�os, repeat e fun��es do meu programa.
						break;

						default:
						printf ("\tDesculpe! Ainda n�o temos essa op��o disponivel no nosso sistema web. Por favor comparecer ao RH da SejaFlow ");
						system ("pause");
						break;
					}// Fim das sele��o
				}// fim do lacoRepeat1
			} else
				printf("\tsenha invalida\n Por favor informe a senha correta!\n tente novamente\n");
	    }while(ComparacaoStringsPasswoard == 1 ); // se a variav�l ComparacaoStringsPasswoad for =  2,  quer dizer que a senha esta errada, ir� repetir esse codigo. 
		return 0; 
	
}
