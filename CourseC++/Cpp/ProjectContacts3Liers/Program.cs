using BusnessLier.BLL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PresentationLier.UI
{ 
	internal class Program
	{
		static void testFindContact(int ID)

		{
			ClsContact Contact1 = ClsContact.Find(ID);

			if (Contact1 != null)
			{
				Console.WriteLine(Contact1.FirstName+ " " + Contact1.LastName);
				Console.WriteLine(Contact1.Email);
				Console.WriteLine(Contact1.Phone);
				Console.WriteLine(Contact1.Address);
				Console.WriteLine(Contact1.DateOfBirth);
				Console.WriteLine(Contact1.CountryID);
				Console.WriteLine(Contact1.ImagePath);
			}
			else
			{
				Console.WriteLine("Contact [" + ID + "] Not found!");
			}
		}
		static void Main(string[] args)
		{
			testFindContact(1);
		}
	}
}
