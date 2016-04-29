#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <conio.c>
#include <stdio.h>
#include<cstdlib>
#include<windows.h>
#include<string.h>
#include<fstream>
#include <ctime>
#include <time.h>
#include<cstring>
#include <locale.h>
#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10


using namespace std;
struct Producto{
	int codigo;
	char principioActivo[20];
	char accionFarmacologica[20];
	char marca[20];
	char vencimiento[10];
	char presentacion[15];
	char laboratorio[20];
	int cantidad;
	float precio;
	float costo;
};

struct Usuario{
	char usuario[20];
	string contrasena;
	int rol;
};

string USUARIO, CONTRASENA, ROL; // captura los datos del usuario que inicia sesion
float TOTAL; // Monto de compra total
int c;  //conteo de las facturas
int contador;

void fecha()
{


 struct tm *tiempo;
 int dia;
 int mes;
 int anio;

 time_t fecha_sistema;
 time(&fecha_sistema);
 tiempo=localtime(&fecha_sistema);
 
 anio=tiempo->tm_year + 1900;
 mes=tiempo->tm_mon + 1;
 dia=tiempo->tm_mday;

 /*printf("Dia: %d",dia);
 printf("Mes: %d",mes);
 printf("Año: %d",anio);*/
 cout << dia << "/" << mes << "/" << anio;
 //return (string)dia <<

}
string Fecha()
{
	time_t t;
  struct tm *tm;
  char fecha[100];

  t=time(NULL);
  tm=localtime(&t);
  strftime(fecha, 100, "%d/%m/%y", tm);
  return  fecha;	
}

string Hora()
{
		time_t t;
  struct tm *tm;
  char hora[100];

  t=time(NULL);
  tm=localtime(&t);
  strftime(hora, 100, "%I:%M:%S", tm);
  //printf ("Hoy es: %s\n", hora);
  return  hora;
}
void titulo()
{
	
	textcolor(RED);
	gotoxy(20, 1);
	cout << "   ------------------------------" << endl;
	gotoxy(22, 2);
	cout << "         FARMACIA VIDAL               " << endl;
	gotoxy(22, 3);
	cout << "         By: Frank Pena               " << endl;
	gotoxy(20, 4);
	cout << "   ------------------------------" << endl;
	//textcolor(WHITE);
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout<<"    ________________________"<<endl;
    cout<<"    |                      |"<<endl;
	cout<<"    |        *   *         |"<< "  ||||||||  ||||   ||||||   ||||     ||||   ||||   ||     ||"<<endl;
	cout<<"    |        *   *         |"<< "  ||       ||  ||  ||    || || ||   || ||  ||  ||   ||   ||"<<endl;
	cout<<"    |    * * *    * * *    |"<< "  ||||||  ||    || ||    || ||  || ||  || ||    ||   || ||"<<endl;
	cout<<"    |                      |"<< "  ||      |||||||| ||||||   ||   ||    || ||||||||    ||"<<endl; 
	cout<<"    |    * * *    * * *    |"<< "  ||      ||    || || ||    ||         || ||    ||   || ||"<<endl;
	cout<<"    |        *    *        |"<< "  ||      ||    || ||  ||   ||         || ||    ||  ||   || "<<endl;
	cout<<"    |        *    *        |"<< "  ||      ||    || ||   ||  ||         || ||    || ||     ||"<<endl;            
    cout<<"    ________________________";*/
    
    /*cout<<"||||||||  ||||   ||||||   ||||     ||||   ||||   ||     ||"<<endl;
	cout<<"||       ||  ||  ||    || || ||   || ||  ||  ||   ||   ||"<<endl;
	cout<<"||||||  ||    || ||    || ||  || ||  || ||    ||   || ||"<<endl;
	cout<<"||      |||||||| ||||||   ||   ||    || ||||||||    ||"<<endl; 
	cout<<"||      ||    || || ||    ||         || ||    ||   || ||"<<endl;
	cout<<"||      ||    || ||  ||   ||         || ||    ||  ||   || "<<endl;
	cout<<"||      ||    || ||   ||  ||         || ||    || ||     ||"<<endl;*/
   /* SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"  Sistema de gestion de medicamentos. creado por: Frank Pena" << endl;*/
//	cout<<"\n \n\n";
}
void mostrarUsuario()
{
	textcolor(GREEN);
	cout << "USUARIO: " << USUARIO << endl;
	cout << "ROL: " << ROL << endl;
}
void visualizarMedicamentos()
{
	Producto producto;
	ifstream lectura;
	lectura.open("inventario.bat", ios::out | ios::in);
	titulo();
	textcolor(BLACK);
	if(lectura.is_open())
	{

		
	cout << "   ---------------------------------------------------------------------------"<<endl;
	cout <<"   "<<setw(10)<< "| Codigo |" << setw(20) <<"      Marca        |" << setw(20) << "    Laboratorio    |" << setw(10)
	<< " Cantidad|" << setw(10) << "  Costo  |" << endl;
	cout << "   ----------------------------------------------------------------------------"<<endl;
	 lectura >> producto.codigo;
	 //recorriendo el archivo
	 while(!lectura.eof())
	 {
	 	lectura >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
		producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
		>> producto.precio >> producto.costo;
		
		//Mostrando en pantalla los productos
			cout <<"   "<<setw(9)<< producto.codigo<<"|" << setw(19) << producto.marca<<"|"
			<< setw(19) << producto.laboratorio<<"|" << setw(9) << producto.cantidad<<"|" << setw(9) 
			<< producto.costo<<"|" << endl;
			
		lectura >> producto.codigo;
	 }
	 cout << "------------------------------------------------------------------------------"<<endl;
	}else{
		cout << "No se pudo abrir el archivo especificado" << endl;
	}
}
void agotando()
{
	Producto producto;
	ifstream lectura;
	lectura.open("inventario.bat", ios::out | ios::in);
	mostrarUsuario();
	titulo();
	textcolor(BLACK);
	if(lectura.is_open())
	{

		
	cout << "   ---------------------------------------------------------------------------"<<endl;
	cout <<"   "<<setw(10)<< "| Codigo |" << setw(20) <<"      Marca        |" << setw(20) << "    Laboratorio    |" << setw(10)
	<< " Cantidad|" << setw(10) << "  Costo  |" << endl;
	cout << "   ----------------------------------------------------------------------------"<<endl;
	 lectura >> producto.codigo;
	 //recorriendo el archivo
	 while(!lectura.eof())
	 {
	 	lectura >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
		producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
		>> producto.precio >> producto.costo;
		
		//Mostrando en pantalla los productos
			if(producto.cantidad <= 30 )
			{
				cout <<"   "<<setw(9)<< producto.codigo<<"|" << setw(19) << producto.marca<<"|"
				<< setw(19) << producto.laboratorio<<"|" << setw(9) << producto.cantidad<<"|" << setw(9) 
				<< producto.costo<<"|" << endl;	
			}
			
			
		lectura >> producto.codigo;
	 }
	 cout << "------------------------------------------------------------------------------"<<endl;
	}else{
		cout << "No se pudo abrir el archivo especificado" << endl;
	}
	system("pause");
}
void eliminar()
{
	mostrarUsuario();
	Producto producto;
	ofstream aux;
    ifstream lectura;
    int i= 0;
    bool encontrado = false;
    int auxCodigo = 0;
    aux.open("auxiliar2.bat",ios::out);
    lectura.open("inventario.bat",ios::in);
    textcolor(BLACK);
    visualizarMedicamentos();
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa el codigo: ";
        cin>>auxCodigo;
        lectura >> producto.codigo;
	 while(!lectura.eof())
	 {
	 	lectura >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
		producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
		>> producto.precio >> producto.costo;
	 	if(auxCodigo == producto.codigo){
                encontrado = true;
                cout << "Registro Eliminado!" << endl;
            }else{
                aux << producto.codigo << " " << producto.marca << " " << producto.principioActivo << " "
			<< producto.accionFarmacologica << " " << producto.vencimiento << " " 
			<< producto.presentacion << " " << producto.laboratorio << " "
			<< producto.cantidad << " " << producto.precio << " "  << producto.costo<< endl;  
            }
		lectura>>producto.codigo;	
	}
    if(encontrado==false){
        cout<<"No se encontro ningun registro con clave "<<auxCodigo<<endl;
    }
    aux.close();
    lectura.close();
    remove("inventario.bat");
    rename("auxiliar2.bat","inventario.bat");
}else{
        cout<<"No se pudo abrir el Archivo o aun no ha sido Creado"<<endl;
	
}
system("pause");
}
//------------------------------Ver Medicamentos-------------------------------
void verMedicamentos()
{
	mostrarUsuario();
	Producto producto;
	ifstream lectura;
	lectura.open("inventario.bat", ios::out | ios::in);
	titulo();
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
	textcolor(LIGHTGREEN);
		//cout << "    ------------------------------------------------------------" << endl;
		cout << "              <<<  Inventario->Ver Medicamentos  >>>          " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
	visualizarMedicamentos();
	system("pause");
}
void buscar()
{
	mostrarUsuario();
	Producto producto;
	ifstream lectura;
	int codigo;
	bool encontrado = false;
	lectura.open("inventario.bat", ios::out | ios::in);
	titulo();
	textcolor(GREEN);
		//cout << "    ------------------------------------------------------------" << endl;
		//cout << "       <<<  Inventario->Buscar medicamento  >>>          " << endl;
	//	cout << "    ------------------------------------------------------------" << endl;
	textcolor(BLACK);
	textcolor(LIGHTBLUE);
		gotoxy(15,8);
		cout <<  "**************************************************" << endl;
		gotoxy(15,19);
		cout <<  "**************************************************" << endl;
		gotoxy(30,9);
		textcolor(RED);
		cout << "BUSCAR MEDICAMENTO";
	if(lectura.is_open())
	{
		gotoxy(17,11);
	cout << "Codigo: ";
	cin >> codigo;
	
	
	/*cout << "-----------------------------------------------------------------------------"<<endl;
	cout <<setw(10)<< "| Codigo |" << setw(20) <<"      Marca        |" << setw(20) << "    Laboratorio    |" << setw(10)
	<< " Cantidad|" << setw(10) << "  Costo  |" << endl;
	cout << "------------------------------------------------------------------------------"<<endl;*/
	 lectura >> producto.codigo;
	 while(!lectura.eof())
	 {
	 	lectura >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
		producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
		>> producto.precio >> producto.costo;
		
		if(codigo == producto.codigo)
		{
			encontrado = true;
			/*cout <<setw(9)<< producto.codigo<<"|" << setw(19) << producto.marca<<"|"
			<< setw(19) << producto.laboratorio<<"|" << setw(9) << producto.cantidad<<"|" << setw(9) 
			<< producto.costo<<"|" << endl;*/
			//cout << "Codigo: " << producto.codigo << endl;
			gotoxy(17,12);
			cout << "Marca: " << producto.marca << endl;
			gotoxy(17,13);
			cout << "Principio Activo: " << producto.principioActivo << endl;
			gotoxy(17,14);
			cout << "Acci\xa2n Farmacol\xa2gica: " << producto.accionFarmacologica << endl;
			gotoxy(17,15);
			cout << "Presentaci\xa2n: " << producto.presentacion << endl;
			gotoxy(17,16);
			cout << "Laboratorio: " << producto.laboratorio << endl;
			gotoxy(17,17);
			cout << "Costo: " << producto.costo << endl;
		}
		lectura >> producto.codigo;
	 }
	  if(!encontrado)
	  {
	  	
	  	cout << "Medicamento no encontrado!" << endl;
	  }
	}else{
		cout << "No se pudo abrir el archivo especificado" << endl;
	}
	system("pause");
}
void agregar()
{
	mostrarUsuario();
	Producto producto; //creando objeto de estructura
	ofstream escribir;
	ifstream consulta;
	bool repetido = false;
	int auxcodigo=0;
	consulta.open("inventario.bat", ios::in);
	escribir.open("inventario.bat", ios::out | ios::app); //Abriendo archivo
	
	textcolor(LIGHTGREEN);
	titulo();
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
		//cout << "    ------------------------------------------------------------" << endl;
		//cout << "       <<<  Inventario->Agregar Medicamento  >>>          " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	
	if (escribir.is_open() && consulta.is_open() )
	{
		//cout << "El archivo abrio con exito" << endl;
		textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,22);
			cout <<  "**************************************************" << endl;
			textcolor(RED);
			gotoxy(30, 9);
			cout << "AGREGAR MEDICAMENTO";
			gotoxy(17,11);
			cout << "Codigo: ";
			cin >> auxcodigo;
		
		
		consulta >> producto.codigo;// lectura adelantada
		
		//verificando que no halla un registro con el codigo ingresado
		while(!consulta.eof())
		{
			consulta >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
			producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
			>> producto.precio >> producto.costo;
			
			if(producto.codigo == auxcodigo)
			{
				textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,15);
			cout <<  "**************************************************" << endl;
			gotoxy(17, 13);
				cout << "Ya existe un medicamento con el codigo " << auxcodigo << endl;
				repetido = true;
				system("pause");
				
			}
			consulta >> producto.codigo;
		}
		if (repetido == false)
		{
			gotoxy(17,12);
			cout << "Marca del producto:  "; cin >> producto.marca;
			gotoxy(17,13);
			cout << "Principio activo: "; cin >> producto.principioActivo;
			gotoxy(17,14);
			cout << "Accion Farmacologica: "; cin >> producto.accionFarmacologica;
			gotoxy(17,15);
			cout << "Fecha de vencimiento: "; cin >> producto.vencimiento;
			gotoxy(17,16);
			cout << "Presentacion: " ; cin >> producto.presentacion;
			gotoxy(17,17);
			cout << "Laboratorio: "; cin >> producto.laboratorio;
			gotoxy(17,18);
			cout << "Cantidad: "; cin >> producto.cantidad;
			gotoxy(17,19);
			cout << "Precio: "; cin >> producto.precio;
			gotoxy(17,20);
			cout << "Costo: "; cin >> producto.costo;
			
			//Entrada de datos
			/*gotoxy(29,10);
			
			gotoxy(27,12);
			
			gotoxy(31,14);
			
			gotoxy(31,16);
			
			gotoxy(23,18);
			
			gotoxy(23,20);
			
			gotoxy(22,22);
			
			gotoxy(17,24);*/
			
			//Fin de entrada de datos
			escribir << auxcodigo << " " << producto.marca << " " << producto.principioActivo << " "
			<< producto.accionFarmacologica << " " << producto.vencimiento << " " 
			<< producto.presentacion << " " << producto.laboratorio << " "
			<< producto.cantidad << " " << producto.precio << " " << producto.costo<< endl;  
			system("cls");
			 string exito = "Medicamento agregado con exito! ";
			 textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,15);
			cout <<  "**************************************************" << endl;
			 int mover = 17;
			 for(int i = 0 ; i <= exito.length(); i++)
			 {
			 	gotoxy(mover, 13 );
			 	cout << exito[i];
			 	Sleep(150);
			 	mover++;
			 }
			 cout << endl;
		}
	}else {
		cout << "Error, el archivo no se pudo abrir" << endl;
	}
	
	
	escribir.close();
	consulta.close();
	system("pause");
}
void inventario()
{
	SetConsoleTitle("Sistema de Gestion de Farmacia");

	//---------Inicializando los punteros--------
	char op;
	do {
		mostrarUsuario();
		titulo();
	
		//system("COLOR 0E");
		textcolor(LIGHTBLUE);
		gotoxy(15,8);
		//cout << "    ------------------------------------------------------------" << endl;
		cout <<  "**************************************************" << endl;
			gotoxy(15,18);
		cout <<  "**************************************************" << endl;
		textcolor(RED);
		gotoxy(30,9);
		cout << "INVENTARIO                        " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
		textcolor(BLACK);
		gotoxy(17,11);
		cout << "      [1] Agregar Medicamento                     " << endl;
		gotoxy(17,12);
		cout << "      [2] Eliminar Medicamento        	           " << endl;
		gotoxy(17,13);
		cout << "      [3] Buscar Medicamento	                   " << endl;
		gotoxy(17,14);
		cout << "      [4] Ver Medicamentos                        " << endl;
	//	cout << "      [4] Consulta                                " << endl;
	    gotoxy(17,15);
	    cout << "      [5] Medicamentos Agotandose" << endl;
		gotoxy(17,16);
		cout << "      [0] Regresar                                   " << endl;
		//cout << "      [5] Modificaciones                          " << endl;

		/*gotoxy(15,15);
		
		gotoxy(15,16);*/
	
	
		gotoxy(15,19);
		cout << "    Opcion: ";
		cin >> op;

		switch(op)
		{
			case '1':
				{
					system("cls");
					agregar();
					system("cls");
					break;
				}
			case '2':
				{
					system("cls");
				    eliminar();
				    system("cls");
					break;
				}
			case '3':
				{
					system("cls");
					buscar();
					system("cls");
					break;
				}
			case '4':
				{
					system("cls");
					verMedicamentos();
					system("cls");
					break;
				}
			case '5':
				{
					system("cls");
					agotando();
					system("cls");
					break;
				}
			case '0':
				{
					system("cls");		
					break;
				}	
				
			default:
				{
					system("cls");	
					cout << "Error, opcion desconocida";
					Sleep(500);
					system("cls");	
					break;
				}	
		}

	system("cls");

	}while(op!= '0');

}
void salir()
{
	textcolor(LIGHTGREEN);
	string mensaje = "PROGRAMA FINALIZADO!";
	cout << endl;
	cout << endl;
	cout << "                ";
	for (int i = 0; i < mensaje.length(); i++)
	{
		cout << mensaje[i];
		Sleep(200);
	}
}

//----------------------------Creacion de usuario-------------------------
void crearusuario()
{
	mostrarUsuario();
	Usuario usuario; //creando objeto de estructura
	ofstream escribir; // salida de datos
	ifstream consulta; // entrada de datos
	bool repetido = false;
	string auxuser;
	consulta.open("registro.bat", ios::in);
	escribir.open("registro.bat", ios::out | ios::app); //Abriendo archivo
	
	
	titulo();
	//gotoxy(26,7);
	//textcolor(LIGHTRED);
		//cout << "    ------------------------------------------------------------" << endl;
		//cout << "       <<<  ADMINISTRAR->CREANDO NUEVO USUARIO  >>>          " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
	
	if (escribir.is_open() && consulta.is_open() )
	{
		
	//	cout << "El archivo abrio con exito" << endl;
	
			textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
            gotoxy(15,15);
			cout <<  "**************************************************" << endl;
			textcolor(RED);
			gotoxy(30, 9);
			cout << "CREAR NUEVO USUARIO";
			gotoxy(15,11);
		cout << "Usuario: ";
		cin >> auxuser;
		
		
		consulta >> usuario.usuario;// lectura adelantada
		
		//verificando que no halla un registro con el codigo ingresado
		while(!consulta.eof())
		{
			consulta >> usuario.contrasena >> usuario.rol;
			
			if(usuario.usuario == auxuser)
			{
				cout << "Ya existe un usuario con el nombre " << auxuser << endl;
				repetido = true;
				system("pause");
				
			}
			consulta >> usuario.usuario;
		}
		if (repetido == false)
		{
			gotoxy(17,12);
			cout << "Contrasena:  "; cin >> usuario.contrasena;
			gotoxy(17,13);
			cout << "ingrese (0)Administrador (1) Cajero: "; cin >> usuario.rol;
			gotoxy(17,14);
			escribir << auxuser << " " << usuario.contrasena << " " << usuario.rol << endl;  
			 string exito = "USUARIO CREADO CON EXITO! ";
			 for(int i = 0 ; i <= exito.length(); i++)
			 {
			 	cout << exito[i];
			 	Sleep(150);
			 }
			 cout << endl;
		}
	}else {
		cout << "Error, el archivo no se pudo abrir" << endl;
	}
	
	
	escribir.close();
	consulta.close();
	Sleep(600);
}
void verusuarios(){
     Usuario usuario;
	ifstream lectura;
	lectura.open("registro.bat", ios::out | ios::in);
	titulo();
	textcolor(BLACK);
	if(lectura.is_open())
	{

		
	cout << "   ---------------------------------------------------------------------------"<<endl;
	cout <<"   "<<setw(30)<< "|           Usuario          |" <<
	 setw(20) <<"   Contrasena      |" << 
	cout << "   ----------------------------------------------------------------------------"<<endl;
	 lectura >> usuario.usuario;
	 //recorriendo el archivo
	 while(!lectura.eof())
	 {
	 	lectura >> usuario.contrasena >> usuario.rol ; 
		
		//Mostrando en pantalla los productos
			cout <<"   "<<setw(29)<< usuario.usuario<<"|" << setw(19) << usuario.contrasena<<"|"
			 << endl;
			
		lectura >> usuario.usuario;
	 }
	 cout << "------------------------------------------------------------------------------"<<endl;
	}else{
		cout << "No se pudo abrir el archivo especificado" << endl;
	}
 
  system("pause");
}

void eliminarUsuario()
{
	mostrarUsuario();
	titulo();
	Usuario user;
	ofstream aux;
    ifstream lectura;
    //int i= 0;
    bool encontrado = false;
    string usuario ="";
    aux.open("auxiliar3.bat",ios::out| ios::app);
    lectura.open("registro.bat",ios::in);
    textcolor(BLACK);
    //visualizarMedicamentos();
    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa el usuario: ";
        cin>>usuario;
        lectura >> user.usuario;
	 while(!lectura.eof())
	 {
	 	lectura >> user.contrasena >> user.rol;
	 	if(usuario == user.usuario){
                encontrado = true;
                cout << "Usuario " << user.usuario <<" Eliminado!" << endl;
                Sleep(500);
            }else{
            	aux << user.usuario << " " << user.contrasena << " " << user.rol << endl;  
            }
		lectura>>user.usuario;
    	
	}
    if(encontrado==false){
        cout<<"No se encontro ningun usuario con id "<<usuario<<endl;
    }
    aux.close();
    lectura.close();
    remove("registro.bat");
    //remove("registro.bat");
    rename("auxiliar3.bat","registro.bat");
}else{
        cout<<"No se pudo abrir el Archivo o aun no ha sido Creado"<<endl;
	
}
system("pause");
}
//Funcion para mostrar el menu de administrador
void administrar()
{
	SetConsoleTitle("ADMINISTRAR");
	char op;
	do {
		
		
		mostrarUsuario();
		titulo();
		//system("COLOR 0E");
		//cout << "    ------------------------------------------------------------" << endl;
		cout << endl;
		textcolor(LIGHTBLUE);
		gotoxy(15,8);
		cout <<  "**************************************************" << endl;
		gotoxy(15,14);
		cout <<  "**************************************************" << endl;
		gotoxy(30,9);
		textcolor(RED);
		
		cout << "ADMINISTRAR USUARIO                   " << endl;
		textcolor(BLACK);
		cout << endl;
		//cout << "    ------------------------------------------------------------" << endl;
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
		gotoxy(17,10);
		cout << "      [1] Crear nuevo usuario                           " << endl;
		gotoxy(17,11);
		cout << "      [2] Eliminar usuario                         	 " << endl;
		gotoxy(17,12);
		cout << "      [3] Ver usuarios                                  " << endl;
		gotoxy(17,13);
		cout << "      [0] Regresar                                        " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
	
		gotoxy(15,16);
		cout << "    Opcion: ";
		cin >> op;

		switch(op)
		{
			case '1':
				{
					system("cls");
					crearusuario();
					system("cls");
					break;
				}
			case '2':
				{
					system("cls");
					eliminarUsuario();
					system("cls");
					break;
				}
			case '3':
				{
					system("cls");
					 verusuarios();
					system("cls");
					break;
				}
			case '0':
				{
					
					system("cls");
					break;
				}
			default:
				{
					system("cls");
					cout << "Error, opcion desconoidca."<< endl;
					Sleep(500);
					 system("cls");
					break;
				}
		}



	}while(op!= '0');

}
void menu()
{
	SetConsoleTitle("ADMINISTRAR");
	//--------color de consola-------
	//system("COLOR 1E");
	

	//---------Inicializando los punteros--------
	char op;
	do {
		mostrarUsuario();
		titulo();
		//system("COLOR 0E");
		
		//cout << "    ------------------------------------------------------------" << endl;
		cout << endl;
		textcolor(LIGHTBLUE);
		gotoxy(15,8);
		cout <<  "**************************************************" << endl;
		gotoxy(15,15);
		cout <<  "**************************************************" << endl;
		
		gotoxy(30,9);
		textcolor(RED);
		cout << "SELECIONE UNA OPCION:                     " << endl;
		cout << endl;
		textcolor(BLACK);
		//cout << "    ------------------------------------------------------------" << endl;
		gotoxy(15,11);
		cout << "      [1] Administrar Usuarios                           " << endl;
		gotoxy(15,12);
		cout << "      [2] Inventario                         	 " << endl;
		gotoxy(15,13);
		cout << "      [3] Productos en agotamiento                " << endl;
		gotoxy(15,14);
		cout << "      [0] Salir                                   " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
		
		gotoxy(15,16);
		cout << "    Opcion: ";
		cin >> op;

		switch(op)
		{
			case '1':
				{
					system("cls");
					administrar();
					system("cls");
					break;
				}
			case '2':
				{
					system("cls");
					inventario();
					system("cls");
					break;
				}
			case '3':
				{
					system("cls");
					agotando();
					system("cls");
					break;
				}
			case 0:
				{
					
					salir();
					break;
				}
			default:
				{
					system("cls");
					cout << "Error, opcion desconocida" << endl;
					Sleep(500);
					system("cls");
					break;
				}
		}



	}while(op!= '0');

}
void agregarFactura()
{
	Producto producto;
	ofstream aux;
	ofstream count;
	ofstream factura;
	ifstream lectura;
	ifstream lectura2;
	string usuario, auxproducto;
	int auxcantidad;
	float precio;
	int cantidadFinal ;
	int cantidad;
	int codigo;
	char resp;
	bool salir = false;
	bool encontrado = false;
	TOTAL = 0;
	aux.open("auxiliar.bat", ios::out);
	lectura.open("inventario.bat", ios::in);
	factura.open("factura.bat", ios::out );
	lectura2.open("factura.bat", ios::in);
	count.open("conteo.bat");
	textcolor(BLACK);
	if(lectura.is_open() && aux.is_open() && factura.is_open())
	{
		do{
			//lectura2 >> c;
			
			system("cls");
			mostrarUsuario(); //funcion para mostrar Nombre de usuario y el ROl
			titulo();
			encontrado = false;
			textcolor(RED);
			cout << "                            FACTURAR  " << endl;
			//visualizarMedicamentos();
			textcolor(GREEN);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
			//cout << "                          FARMAX"<< endl;
			/*cout << "\n VENDEDOR: " << USUARIO << endl;
			cout << setw(4) << "CANT" << setw(5) << "MEDIC" << setw(6) << "COST" << endl;*/
			lectura2 >> auxproducto;
			/*while(!lectura2.eof())
			{
				lectura2 >> auxproducto >> auxcantidad >> precio;
					cout << setw(4) << auxcantidad << setw(5) << auxproducto << setw(6) << precio << endl;
			}*/
			/*lectura2 >>*/  
			/*cout << "-------------------------------------------------------------------------------" << endl;
			cout << "CANT              PRODUCTO                  PRECIO" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "                                                      TOTAL: " << TOTAL << endl;*/
			textcolor(BLACK);
			visualizarMedicamentos();
			cout  << endl;
			cout << "Codigo: ";
			cin >> codigo;
			lectura >> producto.codigo;
			 while(!lectura.eof())
			 {
			 	lectura >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
				producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
				>> producto.precio >> producto.costo;
				
				if(codigo == producto.codigo)
				{	
					encontrado = true;
					cout << "--------------------------------------------------------------"<< endl;
					cout << "                        Detalle: \n " << endl;
					cout << "Codigo: " << producto.codigo << endl;
					cout << "Marca: " << producto.marca << endl;
					cout << "Principio Activo: " << producto.principioActivo << endl;
					cout << "Accion Farmacologica: " << producto.accionFarmacologica << endl;
					cout << "Presentacion: " << producto.presentacion << endl;
					cout << "Laboratorio: " << producto.laboratorio << endl;
					cout << "Costo: " << producto.costo << endl;
					cout << "---------------------------------------------------------------"<<endl;
					
					cout << "Esta seguro que desea comprar este producto? (S/N)";
					cin >> resp;
					//resp = tolower(resp);
					if (resp == 's' || resp == 'S')
					{
						cout << "Cantidad: "; cin >> cantidad;
						if( producto.cantidad > cantidad)
						{
							//cout << "Entro en el if producto.codigo > cantidad" << endl;
								cantidadFinal = producto.cantidad - cantidad;
								aux<<producto.codigo<<" "<<producto.marca<<" "<<producto.principioActivo<<" "<<producto.accionFarmacologica<<" "<<
								producto.vencimiento << " " << producto.presentacion << " " << producto.laboratorio << " " << cantidadFinal << 
								" " << producto.precio << " " << producto.costo <<endl;
               					 cout<<"Registro Modificado"<<endl;
								TOTAL += producto.costo * cantidad;	
						}else{
							cout << "Solo quedan " << producto.cantidad << "en existencia" << endl;
						}
							lectura2 >> producto.codigo;// lectura adelantada
		
							//verificando que no halla un registro con el codigo ingresado
							while(!lectura2.eof())
							{
								lectura >> USUARIO  >> producto.marca >>  cantidad  >>  producto.costo;
							}
						    factura  << contador << cantidad << " " <<producto.marca<< " "  << producto.costo  << " " << producto.costo * cantidad <<endl;
						    
					}else{
						cout << producto.marca ;
						 printf(" no a%cadido a la factura",164);
						 aux<<producto.codigo<<" "<<producto.marca<<" "<<producto.principioActivo<<" "<<producto.accionFarmacologica<<" "<<
								producto.vencimiento << " " << producto.presentacion << " " << producto.laboratorio << " " << producto.cantidad << 
								" " << producto.precio << " " << producto.costo <<endl;
					}
				}else{
					aux<<producto.codigo<<" "<<producto.marca<<" "<<producto.principioActivo<<" "<<producto.accionFarmacologica<<" "<<
								producto.vencimiento << " " << producto.presentacion << " " << producto.laboratorio << " " << producto.cantidad << 
								" " << producto.precio << " " << producto.costo <<endl;
					//cout << "Error, no se pudo abrir el archivo especificado" << endl;
				}
				lectura >> producto.codigo;
			 }
				 if (encontrado == false)
				 {
			 		cout << "Medicamento con el codigo " << codigo << "no encotrado." << endl;
				 }
			    printf("Desea a%cadir otro medicamento? (S/N)",164);
			    cin >> resp;
			    resp = tolower(resp);
				if(resp == 'n')
				{
					salir  = true;
					
				}
					aux.close();
    				lectura.close();
    				remove("inventario.bat");
    				rename("auxiliar.bat","inventario.bat");
    				aux.open("auxiliar.bat", ios::out);
					lectura.open("inventario.bat", ios::in);
				
		}while(!salir);
	
	}else{
		cout << "No se pudo abrir el archivo especificado" << endl;
	}
	aux.close();
    lectura.close();
    //remove("inventario.dat");
    //rename("auxiliar.dat","inventario.dat");
	
	system("pause");
}

void facturarse()
{
	FILE *archivo;
	FILE *archivo2;
	FILE *leer2;
	char caracter[100];
	ofstream imprimir;
	ifstream leer;
	ifstream leertodo;
	ofstream reporte;
	ofstream conteo;
	ifstream leerconteo;
	
	string texto;
	string usuario, auxproducto;
	int auxcantidad;
	float precio;
	int cantidad;
	
	
		
	
	imprimir.open("factura.txt", ios::out);
	leer.open("factura.bat", ios::in);
	leertodo.open("factura.txt", ios::in);
	reporte.open("reporte.bat", ios::out | ios::app);
	conteo.open("conteo.bat", ios::out);
	leerconteo.open("conteo.bat", ios::in);
	archivo = fopen("factura.txt","r");
	archivo2 = fopen("reporte.bat", "r");
	leer2 = fopen("conteo.bat", "r");
	if (imprimir.is_open() && leer.is_open() && leertodo.is_open() && reporte.is_open() && conteo.is_open() && leerconteo.is_open())
	{
		leerconteo >> c;
	/*	cout << c;
		system("pause");*/
		imprimir << "\n                                   Cajero FARMAX" <<endl;
		imprimir << "                      Av. Las americas No.6 Esq. Lincoln Churchil  " <<endl;
		imprimir << "                        RNC.:555-555555  Tel.:(809) 555-5555\n\n" << endl;
		imprimir << "   Recibo: " << c << endl;
		imprimir << "   Fecha: " << "          " <<Fecha()<< "  " << Hora()<<endl;
		//imprimir << "   --------------------------------------------------------------------------" << endl;
		imprimir << "   Cant       Descripcion                   Precio              Valor        " << endl;
		imprimir << "   --------------------------------------------------------------------------" <<endl;
		leer >> texto;
		while(!leer.eof())
		{
			imprimir <<setw(5) /*<<"    "*/ <<  texto ; 
			leer >> texto;
			imprimir  << setw(11)/*<<"         "*/<< texto ;
			leer >> texto;
			imprimir << setw(31)/*<<"                       "*/ << texto ;
			leer >> texto;
			imprimir << setw(20)/*<<"                   " */<< texto << endl;
			leer >> texto;
			
		}
		imprimir << "   --------------------------------------------------------------------------" <<endl;
		imprimir << "\n\n";
		imprimir << "TOTAL.                                                     "<<"$"<< TOTAL << endl;
		imprimir << "Cajero:               "<< USUARIO <<endl;
		imprimir << "\n\n";
		imprimir << "                           GRACIAS POR SU COMPRA!" << endl; 
		
		//Aqui seguimos
		while(!feof(archivo))
		{
			fgets(caracter, 100,  archivo);
			puts(caracter);
			reporte << caracter;
		}
		reporte << endl << endl << endl << endl;
		fclose(archivo);
		
		
		 
	}
	c++;
   conteo << c;
	imprimir.close();
	leer.close();
	leertodo.close();
	reporte.close();
	conteo.close();
	leerconteo.close();
	
	system("pause");
}
void menufactura()
{
	SetConsoleTitle("FACTURACION");
	mostrarUsuario();
	titulo();
	char op;
	do
	{
		textcolor(LIGHTBLUE);
		gotoxy(15,8);
		//cout << "    ------------------------------------------------------------" << endl;
		cout <<  "**************************************************" << endl;
		gotoxy(15,15);
		cout <<  "**************************************************" << endl;
		gotoxy(30,9);
		textcolor(RED);
		cout << "Facturacion" << endl;
		textcolor(BLACK);
		gotoxy(17,11);
		cout << "[1] Agregar a la factura" << endl;
		gotoxy(17,12);
		cout << "[2] Imprimir" << endl;
		//cout << "2. Eliminar de la factura" << endl;
		gotoxy(17,13);
		cout <<"[0] Regresar"<<endl;
		//gotoxy(15,14);
		
		gotoxy(15,16);
		cout << "opcion: "; cin >> op;
		
		switch(op)
		{
			case '1':
				{
					system("cls");
					agregarFactura();
					system("cls");
					break;
				}
			case '2': 
				{
					system("cls");
					facturarse();
					system("cls");
					break;
				}
			case '3':
				{
					
					system("cls");
					//facturarse();
					system("cls");
					break;
				}
			case '0':
				{
					system("cls");
					break;
				}
			default:
				{
					system("cls");
					cout << "Error, opcion desconocida" << endl;
					Sleep(500);
					system("cls");
					break;
				}
		}
	}while(op!='0');
	
}
/*void facturar()
{
	Producto producto;
	ofstream aux;
	ofstream count;
	ofstream factura;
	ifstream lectura;
	ifstream lectura2;
	string usuario, auxproducto;
	int auxcantidad;
	float precio;
	int cantidadFinal ;
	int cantidad;
	int codigo;
	char resp;
	bool salir = false;
	bool encontrado = false;
	TOTAL = 0;
	aux.open("auxiliar.bat", ios::out);
	lectura.open("inventario.bat", ios::in);
	factura.open("factura.bat", ios::out );
	lectura2.open("factura.bat", ios::in);
	count.open("conteo.bat");
	textcolor(BLACK);
	if(lectura.is_open() && aux.is_open() && factura.is_open())
	{
		do{
			lectura2 >> c;
			
			system("cls");
			mostrarUsuario(); //funcion para mostrar Nombre de usuario y el ROl
			encontrado = false;
			textcolor(RED);
			cout << "                       <<<  FACTURAR  >>>" << endl;
			//visualizarMedicamentos();
			textcolor(GREEN);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
			cout << "                          FARMAX"<< endl;
			cout << "\n VENDEDOR: " << USUARIO << endl;
			cout << setw(4) << "CANT" << setw(5) << "MEDIC" << setw(6) << "COST" << endl;
			lectura2 >> auxproducto;
			while(!lectura2.eof())
			{
				lectura2 >> auxproducto >> auxcantidad >> precio;
					cout << setw(4) << auxcantidad << setw(5) << auxproducto << setw(6) << precio << endl;
			}
			lectura2 >>
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "CANT              PRODUCTO                  PRECIO" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "                                                      TOTAL: " << TOTAL << endl;
			textcolor(BLACK);
			cout << "Codigo: ";
			cin >> codigo;
			 lectura >> producto.codigo;
			 while(!lectura.eof())
			 {
			 	lectura >> producto.marca >> producto.principioActivo >> producto.accionFarmacologica >> 
				producto.vencimiento >> producto.presentacion>> producto.laboratorio >> producto.cantidad
				>> producto.precio >> producto.costo;
				
				if(codigo == producto.codigo)
				{	
					encontrado = true;
					cout << "--------------------------------------------------------------"<< endl;
					cout << "                        Detalle: \n " << endl;
					cout << "Codigo: " << producto.codigo << endl;
					cout << "Marca: " << producto.marca << endl;
					cout << "Principio Activo: " << producto.principioActivo << endl;
					cout << "Accion Farmacologica: " << producto.accionFarmacologica << endl;
					cout << "Presentacion" << producto.presentacion << endl;
					cout << "Laboratorio: " << producto.laboratorio << endl;
					cout << "Costo: " << producto.costo << endl;
					cout << "---------------------------------------------------------------"<<endl;
					cout << "Esta seguro que desea comprar este producto? (S/N)";
					cin >> resp;
					resp = tolower(resp);
					if (resp == 's')
					{
						cout << "Cantidad: "; cin >> cantidad;
						if( producto.cantidad > cantidad)
						{
							
								cantidadFinal = producto.cantidad - cantidad;
								aux<<producto.codigo<<" "<<producto.marca<<" "<<producto.principioActivo<<" "<<producto.accionFarmacologica<<" "<<
								producto.vencimiento << " " << producto.presentacion << " " << producto.laboratorio << " " << cantidadFinal << 
								" " << producto.precio << " " << producto.costo <<endl;
               					 cout<<"Registro Modificado"<<endl;
								TOTAL += producto.costo * cantidad;	
						}else{
							cout << "Solo quedan " << producto.cantidad << "en existencia" << endl;
						}
							lectura2 >> producto.codigo; lectura adelantada
		
							verificando que no halla un registro con el codigo ingresado
							while(!lectura2.eof())
							{
								lectura >> USUARIO  >> producto.marca >>  cantidad  >>  producto.costo;
							}
						    factura  << USUARIO << " " <<producto.marca<< " "  << cantidad  << " " << producto.costo <<endl;
						    
					}else{
						cout << producto.marca ;
						 printf(" no a%cadido a la factura",164);
					}
					
					break;
				}else{
					aux<<producto.codigo<<" "<<producto.marca<<" "<<producto.principioActivo<<" "<<producto.accionFarmacologica<<" "<<
								producto.vencimiento << " " << producto.presentacion << " " << producto.laboratorio << " " << producto.cantidad << 
								" " << producto.precio << " " << producto.costo <<endl;
				}
				lectura >> producto.codigo;
			 }
				 if (encontrado == false)
				 {
			 		cout << "Medicamento con el codigo " << codigo << "no encotrado." << endl;
				 }
			    printf("Desea a%cadir otro medicamento? (S/N)",164);
			    cin >> resp;
			    resp = tolower(resp);
				if(resp == 'n')
				{
					salir  = true;
					
				}
					aux.close();
    				lectura.close();
    				remove("inventario.bat");
    				rename("auxiliar.bat","inventario.bat");
    				aux.open("auxiliar.bat", ios::out);
					lectura.open("inventario.bat", ios::in);
				
		}while(!salir);
	
	}else{
		cout << "No se pudo abrir el archivo especificado" << endl;
	}
	aux.close();
    lectura.close();
    remove("inventario.dat");
    rename("auxiliar.dat","inventario.dat");
	
	system("pause");
}*/

void menuFacturacion()
{
	SetConsoleTitle("FACTURACION");

	//---------Inicializando los punteros--------
	char op;
	do {
		mostrarUsuario();
		titulo();
		//system("COLOR 0E");
		
		//cout << "    ------------------------------------------------------------" << endl;
		cout << endl;
		textcolor(LIGHTBLUE);
		gotoxy(15,8);
		cout <<  "**************************************************" << endl;
		gotoxy(15,14);
		cout <<  "**************************************************" << endl;
		gotoxy(15,9);
		textcolor(RED);
		 printf("                  FACTURACI%cN",227);
		 textcolor(BLACK);
	//	cout << "          <<<  FACTURACION  >>>                    " << endl;
		cout << endl;
		//cout << "    ------------------------------------------------------------" << endl;
		gotoxy(15,10);
		cout << "      [1] Facturar                           " << endl;
		gotoxy(15,11);
		cout << "      [2] Productos Agotandose                        	 " << endl;
		gotoxy(15,12);
		cout << "      [0] Salir              " << endl;
		//gotoxy(15,13);
	//	cout << "      [0] Salir                                   " << endl;
		//cout << "    ------------------------------------------------------------" << endl;
		
		gotoxy(15,16);
		cout << "    Opcion: ";
		cin >> op;

		switch(op)
		{
			case '1':
				{
					system("cls");
					menufactura();
					system("cls");
					break;
				}
			case '2':
				{
					system("cls");
					agotando();
					system("cls");
					break;
				}
			case '3':
				{
					system("cls");
					//productosAgotandose();
					system("cls");
					break;
				}
			case '0':
				{
					
					salir();
					break;
				}
			default:
				{
					system("cls");
					cout << "Error, opcion desconocida" << endl;
					 Sleep(500);
					 system("cls");
					break;
				}
		}



	}while(op!= '0');
	
}

void login()
{
	SetConsoleTitle("LOGIN");
	ofstream salida; 
	ifstream lectura;
	
	string usuario;
	string contrasena;
	string auxusuario;
	string auxcontrasena;
	int rol;
	int contador = 0;
	int i = 0;
	char ch;
	bool ingresar = false;
	 textcolor(BLACK);
	 
	 salida.open("registro.bat", ios::out|ios::app); //abriendo registro.dat
	 lectura.open("registro.bat", ios::in);//abriendo registro.dat en lectura
	 if(salida.is_open() & lectura.is_open())//validando si el archivo fue abierto
	 {
	 	do{
			system("cls");
			gotoxy(15, 6);
			textcolor(LIGHTBLUE);
			printf("      COLOCA TU USUARIO Y TU CONTRASEÑA");
			gotoxy(30,9);
			textcolor(LIGHTRED);
			cout << "<<< LOGIN >>>" << endl; 
			textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,15);
			cout <<  "**************************************************" << endl;
			textcolor(BLACK);
			gotoxy(18,11);
			cout << "Usuario: ";
			gotoxy(18,13);
			cout << "Contraseña: ";
			gotoxy(27,11);
			cin >> usuario;
			gotoxy(32,13);
			ch = getch();
			while(ch != 13){
			contrasena.push_back(ch);
			cout << '*';
			ch = getch(); 
			}
			
			cout << endl;
		lectura >> auxusuario;
		while(!lectura.eof())
		{	
			lectura >> auxcontrasena >> rol;
			//cout << auxusuario << " " << auxcontrasena << " " << rol << endl;
			if(usuario == auxusuario && contrasena == auxcontrasena )
			{	
				ingresar = true;
				break;
			}
			lectura >> auxusuario;
			//sleep(6000);
		}
		if(ingresar == false){
			system("cls");
			textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,14);
			cout <<  "**************************************************" << endl;
			textcolor(BLACK);
			gotoxy(18,10);
			cout << "Usuario y/o contraseña incorrecto" << endl;
			Sleep(1000);
			contador ++;
			contrasena.clear();
		}
		if(contador == 3)
		{
			system("cls");
			int x = 25;
			textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,14);
			cout <<  "**************************************************" << endl;
			textcolor(BLACK);
			
			gotoxy(18,10);
			cout << "Ha agotado el numero de intentos" << endl;
			gotoxy(18,11);
			cout << "Espere    segundos para volver a intentar" ; 
			for (i = 20 ; i > 0; i--)
			{
				gotoxy(x ,11);
				cout << i ;
				Sleep(1000);
				if ( i == 10){
					x = 26;
					gotoxy(25,11);
					cout << "0";
				}
			}
			contador = 0;
			
		}
		lectura.clear();
		lectura.seekg(0);
		
		
		}while(ingresar == false);
		
		if (ingresar == true){
			USUARIO = usuario;
			CONTRASENA = contrasena;
			if(rol == 0){
				ROL = "ADMINISTRADOR";
			}else{
				ROL = "CAJERO";
			}
			system("cls");
			textcolor(LIGHTBLUE);
			gotoxy(15,8);
			cout <<  "**************************************************" << endl;
			gotoxy(15,14);
			cout <<  "**************************************************" << endl;
			textcolor(BLACK);
			gotoxy(18,10);
			cout << "Bienvenido " << usuario << endl;
			gotoxy(18,11);
			cout << "Espere unos minutos mientras carga la interfaz..." << endl;
			Sleep(5000);
			system("cls");
			
			lectura >> auxusuario;
			if (rol == 0)
			{
				menu();
			}
			if(rol == 1)
			{
			 menuFacturacion();
			}
			
		}
	 }else{
	 	cout << "Error el archivo no se puedo cargar" << endl;
	 }
}

/* 
Hare un menu para facturar que contara de 3 opciones
1.agregar a la factura
2.eliminar de la factura
3.facturar

 */
int main()
{
	SetConsoleTitle("Sistema de Gestion de Farmacia");
	textbackground(WHITE);
	login();
	return 0;
	system("pause");
}


