using System;
using System.Data;
using System.Data.SqlClient;
using System.Net;
using System.Security.Policy;

public class program
{
	const string ConnectionString = "server=.;database=ContactsDB;user id=sa;password=123456";
	static	bool FoundRecordByID(int ContactID, ref stInfo ContactInfo)
	{
		bool IsFound = false;
		SqlConnection conn = new SqlConnection(ConnectionString);
		string query1 = "select * from contacts where ContactID=@ContactID";
		SqlCommand cmd =new SqlCommand(query1, conn);
		cmd.Parameters.AddWithValue("@ContactID", ContactID);
		try
		{
			conn.Open();
			SqlDataReader reader = cmd.ExecuteReader();
			if (reader.Read())
			{
				IsFound=true;
				ContactInfo.ContactID=(int)(reader["ContactID"]);
				ContactInfo.FirstName=(string)reader["FirstName"];
				ContactInfo.LastName=(string)reader["LastName"];
				ContactInfo.Email=(string)reader["Email"];
				ContactInfo.Phone=(string)reader["Phone"];
				ContactInfo.Address=(string)reader["Address"];
				ContactInfo.CountryID=(int)reader["CountryID"];
			}
			else
			{
				IsFound=false;
			}
			reader.Close();
			conn.Close();
		}
		catch (Exception ex)
		{
			Console.WriteLine("Errore : "+ex.Message);
		}
		return IsFound;
	}
	static void AddNewContact(stInfo NewContact)
	{

		SqlConnection conn1 = new SqlConnection(ConnectionString);

		string Query1 = @"INSERT INTO Contacts (FirstName,LastName,Email,Phone,Address,CountryID)" +
			" VALUES  (@FirstName,@LastName,@Email,@Phone,@Address ,@CountryID);select scope_identity();";
		SqlCommand Command1 = new SqlCommand(Query1, conn1);
		Command1.Parameters.AddWithValue("@FirstName", NewContact.FirstName);
		Command1.Parameters.AddWithValue("@LastName", NewContact.LastName);
		Command1.Parameters.AddWithValue("@Email", NewContact.Email);
		Command1.Parameters.AddWithValue("@Phone", NewContact.Phone);
		Command1.Parameters.AddWithValue("@Address", NewContact.Address);
		Command1.Parameters.AddWithValue("@CountryID", NewContact.CountryID);
		try
		{
			conn1.Open();
			object Res1 = Command1.ExecuteScalar();
			if (Res1!=null && int.TryParse(Res1.ToString(),out int NewAffected))
			{
				Console.WriteLine("Contact successfuly added  with ID: "+NewAffected);
			}
			else
			{
				Console.WriteLine(" faild add ");
			}
			conn1.Close();
		}
		catch (Exception ex)
		{

			Console.WriteLine("Errore : "+ex.Message);
		}
	}
	public struct stInfo
	{
		public int ContactID { get; set; }
		public string FirstName { get; set; }
		public string LastName { get; set; }
		public string Email { get; set; }
		public string Phone { get; set; }
		public string Address { get; set; }
		public int CountryID { get; set; }
	}
	public static void Main()
	{
		stInfo NewContact = new stInfo();

		NewContact.FirstName="Abdoo";
		NewContact.LastName="Isdaoune";
		NewContact.Email="sisd@gmail.com";
		NewContact.Phone="067605197";
		NewContact.Address="casa  khoribga maroc";
		NewContact.CountryID=1;

		AddNewContact(NewContact);






	}

}