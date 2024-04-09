#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço e memória
#include <locale.h>//biblioteca de alocação de textos por região
#include <string.h>//biblioteca responsável por cuidar das string

int registro()//Função responsável por cadastrar os usuários no sistema

{	
    //Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis
	
	printf("Digite o cpf a ser cadastrado:\n ");//Coletando informação do usuário
	scanf("%s",cpf);//%S refere-se as string
	
	strcpy(arquivo ,cpf); //Responsável por copiar os valores das string
	
	FILE*file;//Cria o arquivo no banco de dados
	file=fopen(arquivo,"w"); //cria o arquivo e o"W"significa escrever
	fprintf(file,cpf);  //Salva o valor da variável
	fclose(file);  //Fecha o arquivo
	
	file=fopen(arquivo,"a");//abre o arquivo e o"a" significa alterar
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando informações do usuário
	scanf("%s",nome);//salvando na string
	
	file=fopen(arquivo,"a");//cria o arquivo e o "a"significa alterar
	fprintf(file,nome);//salva o valor  da variável
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//colentando informãções do usuário
	scanf("%s",sobrenome);//salvando na string
	
	file=fopen(arquivo,"a");//cria o arquivo
	fprintf(file,sobrenome);//salva a variável
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");//coletando informações do usário
	scanf("%s",cargo);//salvando na string
	
	file=fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//salvando na strimg
	fclose(file);//fecha o arquivo
	
	system ("pause");
	 
}

int consulta()//função responsável por consultar os usuários
{
	setlocale(LC_ALL,"portuguese");//definindo linguagem
	
	//início criação de variáveis
	char cpf[40];
	char conteudo[200];
	//fim de criação de variáveis
	
	printf("Digite o cpf a ser consultado:");//coletando informações do usuário
	scanf("%s",cpf);//salvando na string
	
	FILE*file;
	file=fopen(cpf,"r");//abre o arquivo e o "r" significa ler
	
	if(file==NULL)
	{
	printf("Não foi possível abrir o arquivo,não localizado!.\n");	
	}
	
	while(fgets(conteudo,200, file) !=NULL)
	{
	printf("\nEssas são as informações do usuário:\n CPF:");
	printf("%s", conteudo);
	printf("\n\n");
	fclose(file);//fecha o arquivo
	
	}
	
	system("pause");
}
	

int deletar()//função responsável por deletar os usuários
{
	//início de criação de variáveis
	char cpf[40];
	//fim de criação de variáveis
	
	printf("Digite o CPF do usuário a ser deletado: ");//coletando informações do usuário
	scanf("%s",cpf);//salvando na string
	
	FILE *file;
	file = fopen(cpf,"r");//abrir arquivo
	
	if(file == NULL)//analíse de usuário inexistente
	{
		
	fclose(file);//fechar arquivo	
	printf("O usuário não se encontra no sistema!\n");
	system("pause");
	
	}
	
	else if(file!=NULL)//analíse de usuário existente
	{
		
	fclose(file);//fechar arquivo
	printf("Usuário deletado com sucesso!\n");
	system("pause");
	remove(cpf);
		
	}
	
}

int main()

    {
    int opcao=0;//definindo variáveis 
    int laco=1;
   
    for (laco=1;laco=1;)
   {
    system("cls");//limpar a tela
	
	setlocale(LC_ALL,"portuguese");//definindo linguagem
	  
	printf("###Cartório da EBAC ###\n\n");//inicío do menu
	printf("Escolha a opção desejada:\n\n");
	printf("\t1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	printf("Opção:");//fim do menu
	  
	scanf("%d",&opcao);//armazenando a escolha do usuário
	  
	system("cls");//responsável por limpar a tela
	  
	switch(opcao)//início da seleção do menu
	{
	case 1:
    registro();
	break;
	  
	case 2:
   	consulta();
	break;
	  
	case 3:
	deletar();
	break;
		
   	default:
   	printf("Essa opção não está disponível!\n");
    system("pause");
    break;					
	}//fim da seleção
	  
	 

}
}
	  

