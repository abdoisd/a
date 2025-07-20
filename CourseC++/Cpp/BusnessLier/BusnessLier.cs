using DataLier;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusnessLier
{
	public class ClsContact	
	{
		public enum enMode { AddNew = 0, Update = 1 };
		public enMode Mode = enMode.AddNew;

		public int ID { set; get; }
		public string FirstName { set; get; }
		public string LastName { set; get; }
		public string Email { set; get; }
		public string Phone { set; get; }
		public string Address { set; get; }
		public DateTime DateOfBirth { set; get; }

		public string ImagePath { set; get; }

		public int CountryID { set; get; }

		public ClsContact()
		{	
			this.ID = -1;
			this.FirstName = "";
			this.LastName = "";
			this.Email = "";
			this.Phone = "";
			this.Address = "";
			this.DateOfBirth = DateTime.Now;
			this.CountryID = -1;
			this.ImagePath = "";
			Mode = enMode.AddNew;

		}

		private ClsContact(int ID, string FirstName, string LastName,
			string Email, string Phone, string Address, DateTime DateOfBirth, int CountryID, string ImagePath)

		{
			this.ID = ID;
			this.FirstName = FirstName;
			this.LastName = LastName;
			this.Email = Email;
			this.Phone = Phone;
			this.Address = Address;
			this.DateOfBirth = DateOfBirth;
			this.CountryID = CountryID;
			this.ImagePath = ImagePath;

			Mode = enMode.Update;

		}
		public static ClsContact Find(int ID)
		{

			string FirstName = "", LastName = "", Email = "", Phone = "", Address = "", ImagePath = "";
			DateTime DateOfBirth = DateTime.Now;
			int CountryID = -1;

			if (ClsDataLier.GetContactInfoByID(ID, ref FirstName, ref LastName,
						  ref Email, ref Phone, ref Address, ref DateOfBirth, ref CountryID, ref ImagePath))

				return new ClsContact(ID, FirstName, LastName,
						   Email, Phone, Address, DateOfBirth, CountryID, ImagePath);
			else
				return null;

		}
	}
}
