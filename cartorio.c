#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h>//biblioteca de aloca��o de textos por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema

{	
    //In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis
	
	printf("Digite o cpf a ser cadastrado:\n ");//Coletando informa��o do usu�rio
	scanf("%s",cpf);//%S refere-se as string
	
	strcpy(arquivo ,cpf); //Respons�vel por copiar os valores das string
	
	FILE*file;//Cria o arquivo no banco de dados
	file=fopen(arquivo,"w"); //cria o arquivo e o"W"significa escrever
	fprintf(file,cpf);  //Salva o valor da vari�vel
	fclose(file);  //Fecha o arquivo
	
	file=fopen(arquivo,"a");//abre o arquivo e o"a" significa alterar
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando informa��es do usu�rio
	scanf("%s",nome);//salvando na string
	
	file=fopen(arquivo,"a");//cria o arquivo e o "a"significa alterar
	fprintf(file,nome);//salva o valor  da vari�vel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//colentando inform���es do usu�rio
	scanf("%s",sobrenome);//salvando na string
	
	file=fopen(arquivo,"a");//cria o arquivo
	fprintf(file,sobrenome);//salva a vari�vel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");//coletando informa��es do us�rio
	scanf("%s",cargo);//salvando na string
	
	file=fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//salvando na strimg
	fclose(file);//fecha o arquivo
	
	system ("pause");
	 
}

int consulta()//fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL,"portuguese");//definindo linguagem
	
	//in�cio cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//fim de cria��o de vari�veis
	
	printf("Digite o cpf a ser consultado:");//coletando informa��es do usu�rio
	scanf("%s",cpf);//salvando na string
	
	FILE*file;
	file=fopen(cpf,"r");//abre o arquivo e o "r" significa ler
	
	if(file==NULL)
	{
	printf("N�o foi poss�vel abrir o arquivo,n�o localizado!.\n");	
	}
	
	while(fgets(conteudo,200, file) !=NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio:\n CPF:");
	printf("%s", conteudo);
	printf("\n\n");
	fclose(file);//fecha o arquivo
	
	}
	
	system("pause");
}
	

int deletar()//fun��o respons�vel por deletar os usu�rios
{
	//in�cio de cria��o de vari�veis
	char cpf[40];
	//fim de cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);//salvando na string
	
	FILE *file;
	file = fopen(cpf,"r");//abrir arquivo
	
	if(file == NULL)//anal�se de usu�rio inexistente
	{
		
	fclose(file);//fechar arquivo	
	printf("O usu�rio n�o se encontra no sistema!\n");
	system("pause");
	
	}
	
	else if(file!=NULL)//anal�se de usu�rio existente
	{
		
	fclose(file);//fechar arquivo
	printf("Usu�rio deletado com sucesso!\n");
	system("pause");
	remove(cpf);
		
	}
	
}

int main()

    {
    int opcao=0;//definindo vari�veis 
    int laco=1;
   
    for (laco=1;laco=1;)
   {
    system("cls");//limpar a tela
	
	setlocale(LC_ALL,"portuguese");//definindo linguagem
	  
	printf("###Cart�rio da EBAC ###\n\n");//inic�o do menu
	printf("Escolha a op��o desejada:\n\n");
	printf("\t1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	printf("Op��o:");//fim do menu
	  
	scanf("%d",&opcao);//armazenando a escolha do usu�rio
	  
	system("cls");//respons�vel por limpar a tela
	  
	switch(opcao)//in�cio da sele��o do menu
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
   	printf("Essa op��o n�o est� dispon�vel!\n");
    system("pause");
    break;					
	}//fim da sele��o
	  
	 

}
}
	  

