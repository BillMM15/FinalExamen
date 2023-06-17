#include "pch.h"
#include "Vehiculo.h"
#include "Inicio.h"
#include "modificar.h"

Vehiculo::Vehiculo() //se iniciliza nuestro metodo constructor
{
	this->connectionString = "datasource=localhost; username=root; password='123'; database = heacker; "; //iniciamos nuestra cadena de conexion a la base de datos
	this->Driver = gcnew MySqlConnection(this->connectionString);
}


void Vehiculo::AbrirConexion()
{
	this->Driver->Open();
}
void Vehiculo::CerrarConexion()
{
	this->Driver->Close();
}

DataTable^ Vehiculo::getData()
{
	String^ sql = "select * from estudiantes";
	MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->Driver);
	MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
	DataTable^ tabla = gcnew DataTable();
	data->Fill(tabla);
	return tabla;
}

void Vehiculo::Crear(String^ n, String^ e, String^ g, String^ c, String^ p, String^ f, String^ d, String^ a ) {
	String^ sql = "Insert into estudiantes (nombre, edad, genero, Calculo, Programacion, Fisica, Derecho, Administracion) values ('" + n + "'," + e + ",'" + g + "','" + c + "','" + p + "','" + f + "','" + d + "','" + a + "')";
	MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->Driver);
	try
	{
		cursor->ExecuteNonQuery();
	}
	catch (Exception^ a)
	{
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show(a->Message);

	}
}

void Vehiculo::Leer(String^ n, String^ e, String^ g, String^ c, String^ p, String^ f, String^ d, String^ a, String^ ref)
{
	String^ sql = "update estudiantes set nombre = '" + n + "', edad = '" + e + "', genero = '" + g + "', Calculo = '" + c + "', Programacion = '" + p + "', Fisica = '" + f + "', Derecho = '" + d + "', Administracion = '" + a + "' where ID = '" + ref + "'";
	MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->Driver);
	try																//este es nuestro metodo modificar 
	{
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		cursor->ExecuteNonQuery();
	}
	catch (Exception^ e)
	{
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show(e->Message);
	}
}

void Vehiculo::Eliminar(String^ id) { //este es mi metodo eliminar 
	String^ sql = "delete from estudiantes where ID = " + id;
	MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->Driver);
	try 
	{
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		cursor->ExecuteNonQuery();
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show("Eliminado correctamente!");
	}
	catch (Exception^ e)
	{
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show(e->Message);
	}
}
