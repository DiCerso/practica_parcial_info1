#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int desplazar_letras(char *, char *);
void desencriptar_texto(char *, char *, int);
void Encriptar_Numeros(char *, char *);
void Desencriptar_numero(char *, char *);
int es_encriptable(char *);

int main(void)
{

    char str[255] = "HOLA MUNDO 123 D 23 A";
    char dato[255] = "";
    char desc[255] = "";
    char encri[255] = "";
    char vali[255] = "";

    int cant = desplazar_letras(str, dato);
    desencriptar_texto(dato, desc, cant);

    printf("\nel original es : %s", str);

    Encriptar_Numeros(str, encri);

    printf("\nel copy es : %s", encri);

    Desencriptar_numero(encri, vali);

    printf("\nel vali es : %s", vali);
    int num = es_encriptable(str);
    printf("%d", num);

    return 0;
}

int desplazar_letras(char *stri, char *copy)
{
    srand(getpid());
    int random = (rand() % 25) + 1;
    random = 25;
    if (random == 25)
    {
        while (*stri)
        {
            *copy = *stri;
            copy++;
            stri++;
        }
    }
    else
    {
        while (*stri)
        {

            if (*stri >= 'A' && *stri <= 'Z')
            {
                *copy = *stri + random;
                if (*copy > 'Z')
                {
                    *copy = *copy - 25;
                }
            }
            else
            {
                *copy = *stri;
            }
            stri++;
            copy++;
        }
    }

    return random;
}

void desencriptar_texto(char *stri, char *copy, int num)
{
    if (num == 25)
    {
        while (*stri)
        {
            *copy = *stri;
            copy++;
            stri++;
        }
    }
    else
    {
        while (*stri)
        {
            if (*stri >= 'A' && *stri <= 'Z')
            {

                *copy = *stri - num;
                if (*copy < 'A')
                {
                    *copy = *copy + 25;
                }
            }
            else
            {
                *copy = *stri;
            }
            stri++;
            copy++;
        }
    }
    return;
}

void Encriptar_Numeros(char *stri, char *copy)
{
    int flag = 0;

    while (*stri)
    {
        switch (*stri)
        {
        case '0':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '$';
            break;
        case '1':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '%';
            break;
        case '2':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '&';
            break;
        case '3':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '*';
            break;
        case '4':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '@';
            break;
        case '5':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '!';
            break;
        case '6':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '+';
            break;
        case '7':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '=';
            break;
        case '8':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = ')';
            copy++;
            break;
        case '9':
            if (flag == 0)
            {
                *copy = '#';
                copy++;
                flag = 1;
            }
            *copy = '(';
            copy++;
            break;
        default:
            if (flag == 1)
            {
                *copy = '#';
                copy++;
                flag = 0;
            }
            *copy = *stri;
            break;
        }
        copy++;
        stri++;
    }
    if (flag == 1)
    {
        *copy = '#';
        copy++;
        flag = 0;
    }
    return;
}

void Desencriptar_numero(char *stri, char *copy)
{
    while (*stri)
    {
        switch (*stri)
        {
        case '$':
            *copy = '0';
            break;
        case '%':
            *copy = '1';
            break;
        case '&':
            *copy = '2';
            break;
        case '*':
            *copy = '3';
            break;
        case '@':
            *copy = '4';
            break;
        case '!':
            *copy = '5';
            break;
        case '+':
            *copy = '6';
            break;
        case '=':
            *copy = '7';
            break;
        case ')':
            *copy = '8';
            break;
        case '(':
            *copy = '9';
            break;
        default:
            if (*stri != '#')
            {
                *copy = *stri;
            }
            break;
        }
        if (*stri != '#')
        {
            copy++;
            stri++;
        }else{
            stri++;
        }
    }

    return;
}


int es_encriptable(char * stri){
    int err = 0;
    while(*stri){
        if((*stri >= '0' && *stri <='9') || (*stri >= 'A' && *stri <='Z') || *stri == ' '){
            *stri++;
        }else{
            return -1;
        }
    }
    return 0;
}