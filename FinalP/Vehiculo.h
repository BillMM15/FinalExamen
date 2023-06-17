#pragma once
using namespace std;
using namespace System::Data;
using namespace System;
using namespace MySql::Data::MySqlClient;
ref class Vehiculo //nombre de la clase
{
private:
	String^ connectionString;  //objetos 
	MySqlConnection^ Driver;
public:
	Vehiculo();
	DataTable^ getData();	//
	void AbrirConexion();	//metodos
	void CerrarConexion();
	void Crear(String^, String^, String^, String^, String^, String^, String^, String^);
	void Leer(String^, String^, String^, String^, String^, String^, String^, String^, String^);
	void Eliminar(String^);

};

