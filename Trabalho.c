#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void reverseString(char* str) 
{
    int length = strlen(str);
    int a, b;
    
    for (a = 0, b = length - 1; a < b; a++, b--) {
            char temp = str[a];
            str[a] = str[b];
            str[b] = temp;
    }
}


int binarioDecimal()
{   
    long long int decimal = 0, i = 0, resto, binario, temp;

    printf("Insira o número em binário que deseja converter para decimal: ");
    scanf("%lld", &binario);

    temp = binario;

    while (binario != 0) {
        resto = binario % 10;
        
        if(resto > 1 || resto < 0)
        {
            printf("\nNúmero binário inválido.\n");
            printf("Tente novamente.\n\n");
            binarioDecimal();
            return 0;
        }
        binario /= 10;
        decimal += resto * pow(2, i);
        ++i;
    }

    printf("\n\n%lld(2) = %lld(10)\n", temp,decimal);

    return 0;


}

int binarioOctal()
{
    long long int j = 1, decimal = 0, i = 0, resto, binario, temp, octal = 0;
    printf("Insira o número em binário que deseja converter para octal: ");
    scanf("%lld", &binario);

    temp = binario;
    
    
    while (binario != 0) 
    {
        resto = binario % 10;
        
        if(resto > 1 || resto < 0)
        {
            printf("\nNúmero binário inválido.\n");
            printf("Tente novamente.\n\n");
            binarioOctal();
            return 0;
        }
        binario /= 10;
        decimal += resto * pow(2, i);
        i++;
    }


    while(decimal > 0)
    {
        octal += (decimal % 8) * j;
        j*=10;
        decimal /= 8;
    }
    
    printf("\n\n%lld(2) = %lld(8)\n\n", temp, octal);

    return 0;

}

int binarioHexa()
{
    long long int binario, decimal = 0, i = 0, resto, j = 0, binarionicio;
    char hexadecimal[100] = "";
    
    printf("Insira o número em binário que deseja converter para hexadecimal: ");
    scanf("%lld", &binario);

    binarionicio = binario;

    while (binario != 0) 
    {
        resto = binario % 10;
        
        if(resto > 1 || resto < 0)
        {
            printf("\nNúmero binário inválido.\n");
            printf("Tente novamente.\n\n");
            binarioHexa();
            return 0;
        }
        binario /= 10;
        decimal += resto * pow(2, i);
        i++;
    }

    while(decimal != 0)
    {
        resto = decimal % 16;

        switch(resto)
        {
            case 0:
                hexadecimal[j] = '0';
                break;
            case 1:
                hexadecimal[j] = '1';
                break;
            case 2:
                hexadecimal[j] = '2';
                break;
            case 3:
                hexadecimal[j] = '3';
                break;
            case 4:
                hexadecimal[j] = '4';
                break;
            case 5:
                hexadecimal[j] = '5';
                break;
            case 6:
                hexadecimal[j] = '6';
                break;
            case 7:
                hexadecimal[j] = '7';
                break;
            case 8:
                hexadecimal[j] = '8';
                break;
            case 9:
                hexadecimal[j] = '9';
                break;
            case 10:
                hexadecimal[j] = 'A';
                break;
            case 11:
                hexadecimal[j] = 'B';
                break;
            case 12:
                hexadecimal[j] = 'C';
                break;
            case 13:
                hexadecimal[j] = 'D';
                break;
            case 14:
                hexadecimal[j] = 'E';
                break;
            case 15:
                hexadecimal[j] = 'F';
                break;
        }

        decimal /= 16;
        j++;
    }

    hexadecimal[j] = '\0';
    reverseString(hexadecimal);

    printf("\n\n%lld(2) = %s(16)\n", binarionicio, hexadecimal);

    return 0;
}

int octalBinario()
{
    long long int octal, decimal = 0, i = 0;
    char binario[200];

    printf("Insira o número em octal que deseja converter para binário: ");
    scanf("%lld", &octal);

    long long int temp = octal;

    while(octal != 0)
    {
        if(octal % 10 > 7 || octal % 10 < 0)
        {
            printf("\nNúmero octal inválido\n");
            printf("Tente novamente.\n\n");
            octalBinario();
            return 0;
        }

        decimal += octal % 10 * pow(8,i);
        octal/=10;
        i++;
    }

    i = 0;

    while(decimal != 0)
    {
        binario[i] = decimal % 2 + '0';
        decimal /=2;
        i++;
    }

    binario[i] = '\0';

    reverseString(binario);

    printf("\n\n%lld(8) = %s(2)\n", temp, binario);

    return 0;

}

int octalDecimal()
{
    long long int octal, decimal = 0, i = 0, temp;
    printf("Insira o número em octal que deseja converter para decimal: ");
    scanf("%lld", &octal);
    temp = octal;

    while(octal != 0)
    {
        if(octal % 10 > 7 || octal % 10 < 0)
        {
            printf("\nNúmero octal inválido\n");
            printf("Tente novamente.\n\n");
            octalDecimal();
            return 0;
        }

        decimal += octal % 10 * pow(8,i);
        octal/=10;
        i++;
    }

    printf("\n\n%lld(8) = %lld(10)\n", temp, decimal);

    return 0;
}

int octalHexa()
{
    long long int octal, decimal = 0, i = 0, temp, resto;
    char hexa[100];

    printf("Insira o número em octal que deseja converter para hexadecimal: ");
    scanf("%lld", &octal);

    temp = octal;

    while(octal != 0)
    {
        if(octal % 10 > 7 || octal % 10 < 0)
        {
            printf("\nNúmero octal inválido\n");
            printf("Tente novamente.\n\n");
            octalHexa();
            return 0;
        }

        decimal += octal % 10 * pow(8,i);
        octal/=10;
        i++;
    }

    i = 0;

    while(decimal != 0)
    {
        resto = decimal % 16;
        switch(resto)
        {
            case 0:
                hexa[i] = '0';
                break;
            case 1:
                hexa[i] = '1';
                break;
            case 2:
                hexa[i] = '2';
                break;
            case 3:
                hexa[i] = '3';
                break;
            case 4:
                hexa[i] = '4';
                break;
            case 5:
                hexa[i] = '5';
                break;
            case 6:
                hexa[i] = '6';
                break;
            case 7:
                hexa[i] = '7';
                break;
            case 8:
                hexa[i] = '8';
                break;
            case 9:
                hexa[i] = '9';
                break;
            case 10:
                hexa[i] = 'A';
                break;
            case 11:
                hexa[i] = 'B';
                break;
            case 12:
                hexa[i] = 'C';
                break;
            case 13:
                hexa[i] = 'D';
                break;
            case 14:
                hexa[i] = 'E';
                break;
            case 15:
                hexa[i] = 'F';
                break;
        }
        i++;
        decimal/=16;
    }

    hexa[i] = '\0';
    reverseString(hexa);

    
    printf("\n\n%lld(8) = %s(16)\n", temp, hexa);


    return 0;
}

int decimalBinario()
{
    long long int decimal, temp;
    char binario[200];
    int j = 0, resto;

    printf("Insira o número em decimal que deseja converter para binário: ");
    long long int ret;

    ret = scanf("%lld", &decimal);

    while (getchar() != '\n');

    if(ret != 1 || decimal < 0)
    {
        printf("\nNúmero decimal inválido.\n");
        printf("Tente novamente.\n\n");
        decimalBinario();
        return 0;
    }
    
    
    temp = decimal;

    while(decimal != 0)
    {
        resto = decimal % 2;
        binario[j] = resto + '0';
        j++;
        decimal/=2;
    }

    binario[j] = '\0';

    reverseString(binario);

    printf("\n\n%lld(10) = %s(2)\n", temp, binario);
    return 0;
}

int decimalOctal()
{
    return 0;
}

int decimalHexa()
{
    return 0;
}

int hexaBinario()
{
    return 0;
}

int hexaOctal()
{
    return 0;
}

int hexaDecimal()
{
    return 0;
}



int main()
{
    int escolha1, escolha2, escolha3;

    printf("\t\t-----Conversor de Bases-----\t\t\n\n");
    printf("Converter de:\n\n");
    printf("1|Binário\n");
    printf("2|Octal\n");
    printf("3|Decimal\n");
    printf("4|Hexadecimal\n");
    printf("5|Sair do programa\n\n");

    printf("Insira sua escolha: ");
    scanf("%d", &escolha1);
    while(escolha1 < 1 || escolha1 > 5)
    {
        printf("\nEscolha inválida\n");
        printf("Insira sua escolha novamente: ");
        scanf("%d", &escolha1);
    }

    printf("\n\n");

    switch(escolha1)
    {
        case 1:
            printf("Binário para:\n\n");
            printf("1|Octal\n");
            printf("2|Decimal\n");
            printf("3|Hexadecimal\n\n");

            printf("Insira sua escolha: ");
            scanf("%d", &escolha2);
            while(escolha2 < 1 || escolha2 > 3)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                scanf("%d", &escolha2);
            }

            printf("\n\n");

            switch(escolha2)
            {
                case 1:
                    binarioOctal();
                    break;
                case 2:
                    binarioDecimal();
                    break;
                case 3:
                    binarioHexa();
                    break;    
            }

            break;
        
        case 2:
            printf("Octal para:\n");
            printf("1|Binário\n");
            printf("2|Decimal\n");
            printf("3|Hexadecimal\n\n");

            printf("Insira sua escolha: ");
            scanf("%d", &escolha2);
            while(escolha2 < 1 || escolha2 > 3)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                scanf("%d", &escolha2);
            }

            printf("\n\n");

            switch(escolha2)
            {
                case 1:
                    octalBinario();
                    break;
                case 2:
                    octalDecimal();
                    break;
                case 3:
                    octalHexa();
                    break;    
            }

            break;
        
        case 3:
            printf("Decimal para:\n");
            printf("1|Binário\n");
            printf("2|Octal\n");
            printf("3|Hexadecimal\n\n");

            printf("Insira sua escolha: ");
            scanf("%d", &escolha2);
            while(escolha2 < 1 || escolha2 > 3)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                scanf("%d", &escolha2);
            }

            printf("\n\n");

            switch(escolha2)
            {
                case 1:
                    decimalBinario();
                    break;
                case 2:
                    decimalOctal();
                    break;
                case 3:
                    decimalHexa();
                    break;    
            }

            break;
        
        case 4:
            printf("Hexadecimal para:\n");
            printf("1|Binário\n");
            printf("2|Octal\n");
            printf("3|Decimal\n\n");

            printf("Insira sua escolha: ");
            scanf("%d", &escolha2);
            while(escolha2 < 1 || escolha2 > 3)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                scanf("%d", &escolha2);
            }
            
            printf("\n\n");
            
            switch(escolha2)
            {
                case 1:
                    hexaBinario();
                    break;
                case 2:
                    hexaOctal();
                    break;
                case 3:
                    hexaDecimal();
                    break;    
            }

            break;
        
        case 5:
            return 0;
            break;
    }

    printf("\nGostaria de rodar o programa novamente?\n\n");
    printf("1|Sim\n");
    printf("2|Não\n\n");

    printf("Insira sua escolha: ");
    scanf("%d", &escolha3);

    while(escolha3 != 1 && escolha3 != 2)
    {
        printf("\nEscolha inválida.\n");
        printf("Insira sua escolha novamente: ");
        scanf("%d", &escolha3);
    }

    if(escolha3 == 1)
    {
        system("clear");
        main();
    }
    else
    {
        return 0;
    }
}

