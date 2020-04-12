#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>// atoi
#include<cctype>// isdigit
#include<string.h>
#include<conio.h>// getch

using namespace std;

/*-----------------------------------------------------------------------------
	=== variables globales ===
-----------------------------------------------------------------------------*/

int n=-1;
int aux=0;

/*-----------------------------------------------------------------------------
	=== estructuras ===
-----------------------------------------------------------------------------*/

struct empleado
{
	string nombre[100];
	string apellido[100];
	string cred[100];
	string edad[100];
	string dir[100];
	string tel[100];
	int ventas[100];
}emp;


/*-----------------------------------------------------------------------------
	=== validacion ===
-----------------------------------------------------------------------------*/
bool esNumerico(string linea) 
{
   bool b = true;
   int longitud = linea.size();
 
   if (longitud == 0) {
      b = false;
   } else if (longitud == 1 && !isdigit(linea[0])) {
      b = false;
   } else {
      int i;
      if (linea[0] == '+' || linea[0] == '-')
         i = 1;
      else
         i = 0;
 
      while (i < longitud) {
         if (!isdigit(linea[i])) {
            b = false;
            break;
         }
         i++;
      }
   }
 
   return b;
}


/*-----------------------------------------------------------------------------
	=== inicio de sesion ===
-----------------------------------------------------------------------------*/
void login()
{
contra:
system("cls");

char user[20], pass[20],o;
cout<<endl<<"==================== GOOD CAR =====================\n"<<endl;
printf("             Ingrese Usuario:  ");
scanf("%s",user);
printf("             Ingrese contrase%ca: ",164);

for(int i=0; i<10; i++)
{
o=getch();
if(o!=char(13)){ pass[i]=o;printf("*");}
else break;
}

printf("\n\r %s",pass);

if (strcmp(user,"admin")==0 &&  strcmp(pass,"12345")==0)

  {
  system("cls");
    cout<<"==================================================="<<endl;
	cout<<"                   BIENVENIDO!!                    "<<endl;
	cout<<"==================================================="<<endl<<endl;
			system("pause");
   }
else
  {
   goto contra;
    }
}
/*-----------------------------------------------------------------------------
	=== ingreso de empleado ===
-----------------------------------------------------------------------------*/

void ingreso() {
	int opcion=1;
	n++;
	login();
	while(opcion!=0) {
		aux++;
        bool repite = true;

		system("cls");
		cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
		cout<<"\t << INGRESO DEL EMPLEADO "<<n+1<<" >>"<<endl;

		cout<<endl<<"\tNombre del empleado: ";
		cin>>emp.nombre[n];

		cout<<endl<<"\tApellido del empleado: ";
		cin>>emp.apellido[n];

		do {
    		cout<<endl<<"\tNumero de credencial del empleado: ";
		    cin>>emp.cred[n];
          if (esNumerico(emp.cred[n])) {
         repite = false;
      } else {
         cout << "Numero de credencial invalido. Intente nuevamente" << endl;
         system("pause");
      }
   } while (repite);
		

		do {
    		cout<<endl<<"\tEdad del empleado: ";
		cin>>emp.edad[n];
          if (esNumerico(emp.edad[n])) {
         repite = false;
      } else {
         cout << "Edad invalida. Intente nuevamente" << endl;
         system("pause");
      }
   } while (repite);


   		cout<<endl<<"\tDireccion del empleado: ";
		cin>>emp.dir[n];
		

		do {
    		cout<<endl<<"\tTelefono del empleado: ";
			cin>>emp.tel[n];

          if (esNumerico(emp.tel[n])) {
         repite = false;
      } else {
         cout << "numero de telefono invalido. Intente nuevamente" << endl;
         system("pause");
      }
   } while (repite);


        cout<<endl;
        cout<<"==================================================="<<endl;
		cout<<"    Desea ingresar otro empleado?|(SI=1 | NO=0)|   ";cin>>opcion;cout<<endl;
		
		if(opcion!=0)
		{
			n++;
		}
	}
}

/*-----------------------------------------------------------------------------
	=== busqueda del empleado ===
-----------------------------------------------------------------------------*/

void buscar()
{
	system("cls");
	cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
	string cod;
	cout<<"\t-> ingrese el codigo de la credencial del empleado: ";
	cin>>cod;
	for(int i=0; i<aux; i++)
	{
		system("cls");
		if(emp.cred[i]==cod)
		{
			cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
			cout<<"\t-> Nombre: "<<emp.nombre[i]<<" "<<emp.apellido[i]<<endl;
			cout<<"\t-> Credencial: "<<emp.cred[i]<<endl;
			cout<<"\t-> Edad: "<<emp.edad[i]<<endl;
			cout<<"\t-> Direccion: "<<emp.dir[i]<<endl;
			cout<<"\t-> Telefono: "<<emp.tel[i]<<endl;
			cout<<"\t-> Ventas realizadas: "<<emp.ventas[i]<<endl;
			cout<<"====================================================="<<endl<<endl;
			system("pause");
		}
	}
}

/*-----------------------------------------------------------------------------
	=== regisro de venta ===
-----------------------------------------------------------------------------*/

void registro()
{
	system("cls");
	int op=1, a, b=0, cont=0;
	string cod;
	cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
	cout<<"\t-> ingrese su codigo de credencial: ";
	cin>>cod;
	for(int i=0; i<aux; i++)
	{
		if(emp.cred[i]==cod)
		{
			a=i;
		}
	}
	while(op!=0)//cuando op no es igual a cero.
	{
        bool repite = true;
		system("cls");
		cont++;
		cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
		cout<<"1. Mazda 3               Negro        23616  \n";
		cout<<"2. Ferrari Portofino     Rojo        250691  \n";
		cout<<"3. Kia Optima            Blanco       25120  \n";
		cout<<"4. Porshe Panamera       Gris        115719  \n";
		cout<<"5. Toyota Prius          Azul         34190  \n";
cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
		rep:
		cout<<endl<<"\tELIJA UNA OPCION:";
		string opc;
		
		do {
    cin>>opc;

          if (esNumerico(opc)) {
         repite = false;
      } else {
         cout << "Opcion incorrecta" << endl;
         system("pause");
         goto rep;
      }
   } while (repite);

   int op2 = atoi(opc.c_str());
		
		cout<<endl<<"============ REGISTRO DE VENTA ==========="<<endl;
		switch(op2){

			case 1:
                cout<<"Marca del auto: Mazda."<<endl;
                cout<<"Modelo del auto: Mazda 3."<<endl;
                cout<<"Color del auto: Negro."<<endl;
                cout<<"Precio del auto: $23616."<<endl;system("pause");
			break;
			
			case 2:
                cout<<"Marca del auto: Ferrari."<<endl;
                cout<<"Modelo del auto: Portofino."<<endl;
                cout<<"Color del auto: Rojo."<<endl;
                cout<<"Precio del auto: $250691."<<endl;system("pause");
			break;
			
			case 3:
                cout<<"Marca del auto: Kia."<<endl;
                cout<<"Modelo del auto: Optima."<<endl;
                cout<<"Color del auto: Blanco."<<endl;
                cout<<"Precio del auto: $25120."<<endl;system("pause");
			break;
			
			case 4:
                cout<<"Marca del auto: Porshe."<<endl;
                cout<<"Modelo del auto: Panamera."<<endl;
                cout<<"Color del auto: Gris."<<endl;
                cout<<"Precio del auto: $115719."<<endl;system("pause");
			break;
			
			case 5:
                cout<<"Marca del auto: Toyota."<<endl;
                cout<<"Modelo del auto: Prius."<<endl;
                cout<<"Color del auto: Azul."<<endl;
                cout<<"Precio del auto: $34190."<<endl;system("pause");
			break;

}
		cout<<endl<<"================================================="<<endl;
		cout<<"\t-> Desea registrar otra venta? (SI=1 | NO=0): ";
		cin>>op;
	}

	emp.ventas[a]=emp.ventas[a]+cont;
	cout<<endl<<endl;
	system("pause");
}

/*-----------------------------------------------------------------------------
	=== empleado del mes ===
-----------------------------------------------------------------------------*/

void candidato()
{
	system("cls");
	int max=0, j;
	for(int i=0; i<aux; i++)
	{
		if(emp.ventas[i]>max)
		{
			max=emp.ventas[i];
			j=i;

		}
	}

	cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
	cout<<"-> EL CANDIDATO A EMPLEADO DEL MES ES : "<<emp.nombre[j]<<" "<<emp.apellido[j];
	cout<<endl<<"-> AUTOS VENDIDOS: "<<max<<endl<<endl;
	cout<<"==================================================="<<endl;
	cout<<"                   FELICIDADES!                    "<<endl;
	cout<<"==================================================="<<endl<<endl;
	system("pause");
}


int main()
{
	menu:
    string opc;
    bool repite = true;

	system("cls");
	cout<<endl<<"==================== GOOD CAR ====================="<<endl<<endl;
	cout<<"\t1) INGRESAR UN EMPLEADO A LA BASE DE DATOS."<<endl;
	cout<<"\t2) REGISTRAR VENTA DE AUTOS."<<endl;
	cout<<"\t3) BUSCAR DATOS DE UN EMPLEADO."<<endl;
	cout<<"\t4) MOSTRAR CANDIDATO A EMPLEADO DEL MES."<<endl;
	cout<<"\t5) SALIR DEL PROGRAMA."<<endl<<endl;
	cout<<"==================================================="<<endl;
	cout<<"   -> DIGITE UNA OPCION: ";
    do {
    cin>>opc;

          if (esNumerico(opc)) {
         repite = false;
      } else {
         cout << "No ha ingresado un entero. Intente nuevamente" << endl;
         system("pause");
         goto menu;
      }
   } while (repite);

   int op = atoi(opc.c_str());

	switch(op)
	{
		case 1:
			ingreso();
		goto menu;

		case 2:
			registro();
		goto menu;

		case 3:
			buscar();
		goto menu;

		case 4:
			candidato();
		goto menu;

		case 5:
			system("pause");
			return 0;
	}
}
