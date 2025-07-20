using System;
using System.Data;
using System.Net;
using System.Data.SqlClient;

public class Program
{
	static string connectionString = "Server=.;Database=ContactsDB;User Id=sa;Password=123456;"; // Replace with your actual connection string
	static void PrintAllContacts()
	{
		SqlConnection connection = new SqlConnection(connectionString);

		string query = "insert into Contacts values ('a', 'a', 'a', 'a', 'a', 1);";
		SqlCommand command = new SqlCommand(query, connection);

		try
		{
			connection.Open();

			int rowsEffected = command.ExecuteNonQuery();
			if (rowsEffected > 0)
			{
				Console.WriteLine("good");
			}
			else
			{
				Console.WriteLine("bad");
			}

			connection.Close();
		}
		catch (Exception ex)
		{
			Console.WriteLine("Error: " + ex.Message);
		}
	}

	public static void Main()
	{
		PrintAllContacts();
		Console.ReadKey();
	}
}
