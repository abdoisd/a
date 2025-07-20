using System;
using System.Data;
using System.Net;
using System.Data.SqlClient;
using System.Security.Cryptography.X509Certificates;

namespace GetAllContactsFromDataBase
{

	internal class Program
	{
		const string connectionString = "server=.;database=ContactsDB;user id=sa;password=123456";
		static void SearshcContactCountain(string Countain)
		{
			SqlConnection connection = new SqlConnection(connectionString);
			string query = "SELECT * FROM Contacts where FirstName like '%'+@Countain+'%'";
			SqlCommand command = new SqlCommand(query, connection);
			command.Parameters.AddWithValue("@Countain", Countain);
			
			try
			{
				connection.Open();

				SqlDataReader reader = command.ExecuteReader();

				while (reader.Read())
				{
					int contactID = (int)reader["ContactID"];
					string firstName = (string)reader["FirstName"];
					string lastName = (string)reader["LastName"];
					string email = (string)reader["Email"];
					string phone = (string)reader["Phone"];
					string address = (string)reader["Address"];
					int countryID = (int)reader["CountryID"];

					Console.WriteLine($"Contact ID: {contactID}");
					Console.WriteLine($"Name: {firstName} {lastName}");
					Console.WriteLine($"Email: {email}");
					Console.WriteLine($"Phone: {phone}");
					Console.WriteLine($"Address: {address}");
					Console.WriteLine($"Country ID: {countryID}");
					Console.WriteLine();
				}
				reader.Close();
				connection.Close();
			}
			catch (Exception ex)
			{
				Console.WriteLine("Erreor "+ex.Message);
			}
		}
		static string GetFirstName(int ContactID)
		{
			string LastName = "";
			SqlConnection connection2 =new SqlConnection(connectionString);
			string query2 = "select LastName from contacts where ContactID=@ContactID";
			SqlCommand command2 = new SqlCommand( query2, connection2);
			command2.Parameters.AddWithValue("@ContactID", ContactID);
			try
			{
				connection2.Open();
				object Result2 = command2.ExecuteScalar();
				if (Result2 != null)
				{
					LastName= (string)Result2;
				}
				else
				{
					LastName="NotFound";
				}
				connection2.Close();
			}
			catch (Exception ex)
			{

				Console.WriteLine("Errore : "+ex.Message);
			}
			return LastName;
		}
		static bool FindContactByID(int ContactID)
		{ 
			bool IsFound=false;

			return IsFound;
		}
		static void Main(string[] args)
		{
			//GetAllRecords();
			//GetRecordsWithFirstName("jane");
			//GetRecordsWithFirstName_CountryID("jane",1);
			//SearshcContactStartWith("j");
			//SearshcContactEndWith("l");
			//SearshcContactCountain("av");
			//Console.WriteLine(GetFirstName(100));

		}
	}
}
	
