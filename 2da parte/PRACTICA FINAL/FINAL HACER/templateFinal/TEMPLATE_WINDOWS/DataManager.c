#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"

#include "Usuario.h"
#include "Tema.h"

int dm_saveAllX(ArrayList* pArrayX)
{
//    int i;
    int retorno=-1;
 /*
    FILE* pArchivoUsuarios=fopen(ARCHIVO_Usuarios,"wb");
    void* pUsuario=NULL;
    if(pArchivoUsuarios!=NULL)
    {
        for(i=0;i<al_len(pArrayUsuarios);i++)
        {
            pUsuario=al_get(pArrayUsuarios,i);
            fwrite(pUsuario,sizeof(Usuario),1,pArchivoUsuarios);
            retorno=0;
        }

    }
    fclose(pArchivoUsuarios);
*/

/*

 int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* pEmployees=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(list);i++)
        {
            pEmployees=al_get(list,i);
            fprintf(pFile, "%d,%s,%s,%d,%d\n", employee_getId(pEmployees),employee_getName(pEmployees), employee_getLastName(pEmployees), employee_getAge(pEmployees), employee_getType(pEmployees));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;


*/


    return retorno;
}

//int dm_readAllUsuarios(ArrayList* pArrayUsuarios)
//{
//    int retorno=-1;
//    Usuario auxUsuario;
//    int maxId=0;
//    Usuario* pUsuario=NULL;
//    FILE* pArchivoUsuarios=fopen(ARCHIVO_USUARIOS,"rb");
//
//    if(pArchivoUsuarios!=NULL)
//    {
//        do{
//            if(fread(&auxUsuario,sizeof(Usuario),1,pArchivoUsuarios)==1)
//            {
//                pUsuario=usuario_new(auxUsuario.id,auxUsuario.nombre,auxUsuario.email,auxUsuario.sexo,auxUsuario.pais, auxUsuario.password, auxUsuario.ipAddress);
//                al_add(pArrayUsuarios,pUsuario);
//                if(auxUsuario.id>maxId)
//                {
//                    maxId=auxUsuario.id;
//                }
//                retorno=maxId;
//            }
//        }while(!feof(pArchivoUsuarios));
//        fclose(pArchivoUsuarios);
//    }
//
//    return retorno;
//}

int dm_readAllUsuarios(ArrayList* nominaUsuarios)
{
    FILE *pFile;
	Usuario* auxUsuario;
	int idMax = 0;
	int retorno=-1;

    char id[50],nombre[50],email[50],sexo[50],pais[50],password[50],ipAddress[50];

    pFile = fopen("usuarios.dat","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,email,sexo,pais,password,ipAddress);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,email,sexo,pais,password,ipAddress) >0)
			{
//				if(val_validarInt(id)!=-1 && val_validarString(nombre)!=-1 && val_validarString(email)!=-1 && val_validarInt(sexo)!=-1 && val_validarInt(pais)!=-1)
//				{
//					auxEmployee=employee_new(atoi(id), nombre, email,atoi(sexo), atoi(pais));
                    auxUsuario = usuario_new(atoi(id), nombre, email, sexo, pais,password,ipAddress);
					al_add(nominaUsuarios, auxUsuario);
					if(atoi(id) >idMax)
                    {
                        idMax = atoi(id);
                    }
                        retorno = idMax;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

	return retorno;
}

int dm_readAllTemas(ArrayList* nominaTemas)
{
    FILE *pFile;
	Tema* auxTema;
	int idMax = 0;
	int retorno=-1;

    char id[50],nombre[50],artista[50];

    pFile = fopen("temas.dat","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,artista);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,artista) >0)
			{
//				if(val_validarInt(id)!=-1 && val_validarString(nombre)!=-1 && val_validarString(email)!=-1 && val_validarInt(sexo)!=-1 && val_validarInt(pais)!=-1)
//				{
//					auxEmployee=employee_new(atoi(id), nombre, email,atoi(sexo), atoi(pais));
                    auxTema = tema_new(atoi(id), nombre, artista);
					al_add(nominaTemas, auxTema);
					if(atoi(id) >idMax)
                    {
                        idMax = atoi(id);
                    }
                        retorno = idMax;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

	return retorno;
}
