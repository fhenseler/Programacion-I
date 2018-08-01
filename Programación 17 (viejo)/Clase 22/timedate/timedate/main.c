#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SYSTEMTIME hoy;
    GetLocalTime(&hoy);
    printf("Hora: %02d:%02d:%02d \nFecha: %d-%d-%d \n", hoy.wHour, hoy.wMinute, hoy.wSecond, hoy.wDay, hoy.wMonth, hoy.wYear);
    system("pause");
    return 0;
}
