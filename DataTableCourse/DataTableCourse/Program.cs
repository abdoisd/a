using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataTableCourse
{
    internal class Program
    {
        static void Main(string[] args)
        {

            DataTable DTEmployees = new DataTable("Employees");
            DTEmployees.Columns.Add("ID", typeof(int));
            DTEmployees.Columns.Add("Name", typeof(string));
            DTEmployees.Columns.Add("Age", typeof(int));
            DTEmployees.Columns.Add("Salary", typeof(decimal));
            DTEmployees.Columns.Add("Department", typeof(string));
            //primariy key id
            DTEmployees.PrimaryKey = new DataColumn[1] { DTEmployees.Columns["ID"] };

            DTEmployees.Rows.Add(1, "Salah", 30, 60000.00m, "HR");
            DTEmployees.Rows.Add(2, "Aziz", 25, 50000.00m, "IT");
            DTEmployees.Rows.Add(3, "Charlie", 35, 70000.00m, "Finance");
            DTEmployees.Rows.Add(4, "Kamal", 28, 55000.00m, "IT");
            DTEmployees.Rows.Add(5, "omar", 40, 80000.00m, "HR");

            Console.WriteLine("Employees DataTable:");
            foreach (DataRow row in DTEmployees.Rows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t Name: {row["Name"]},\t " +
                    $"Age: {row["Age"]},\t Salary: {row["Salary"]},\t" +
                    $" Department: {row["Department"]}");
            }
            int TotEmployees = DTEmployees.Rows.Count;
            Console.WriteLine("\nTotEmployees  ="+TotEmployees);
            double SalarySum = Convert.ToDouble(DTEmployees.Compute("sum(Salary)", string.Empty));
            Console.WriteLine("SalarySUM  =" + SalarySum);
            double SalaryAvg = Convert.ToDouble(DTEmployees.Compute("AVG(Salary)", string.Empty));
            Console.WriteLine("SalaryAvg  =" + SalaryAvg);
            double SalaryMin = Convert.ToDouble(DTEmployees.Compute("MIN(Salary)", string.Empty));
            Console.WriteLine("SalaryMin  =" + SalaryMin);
            double SalaryMax = Convert.ToDouble(DTEmployees.Compute("Max(Salary)", string.Empty));
            Console.WriteLine("SalaryMax  =" + SalaryMax);

            // filtring the DataTable
            DataRow[] filteredRows = DTEmployees.Select("Department = 'IT' or Age <=26");
            int ResultCount=filteredRows.Count();
            Console.WriteLine("\nFiltered Employees (IT Department, Age > 26):");
            foreach (DataRow row in filteredRows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t Name: {row["Name"]},\t " +
                    $"Age: {row["Age"]},\t Salary: {row["Salary"]},\t" +
                    $" Department: {row["Department"]}");
            }
            Console.WriteLine("\nTotEmployees  =" + ResultCount);
            double SalarySum2 = Convert.ToDouble(DTEmployees.Compute("sum(Salary)", "Department = 'IT' or Age <=26"));
            Console.WriteLine("SalarySUM  =" + SalarySum2);

            //Console.BackgroundColor = ConsoleColor.Green;
            Console.WriteLine("Sorting Datatable");

            DTEmployees.DefaultView.Sort = "Name ASC" ;
            
           DTEmployees= DTEmployees.DefaultView.ToTable();
            foreach(DataRow row in DTEmployees.Rows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t Name: {row["Name"]},\t " +
                                   $"Age: {row["Age"]},\t Salary: {row["Salary"]},\t" +
                                   $" Department: {row["Department"]}");
            }

            Console.WriteLine("Deleting  Row id=2");

            DataRow[] rowsToDelete = DTEmployees.Select("ID = 2");  
           foreach(DataRow rows in rowsToDelete)
            {
                rows.Delete();
            }

            foreach (DataRow row in DTEmployees.Rows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t Name: {row["Name"]},\t " +
                                   $"Age: {row["Age"]},\t Salary: {row["Salary"]},\t" +
                                   $" Department: {row["Department"]}");
            }
            Console.WriteLine("updatind contact with id =");
            DataRow[] ResultData  = DTEmployees.Select("ID = 3");
            foreach (DataRow row in ResultData)
            {
                row["Name"] = "mohammed";
                row["Salary"] = 90000.00m;
                row["Age"] = 45;    
            }
            foreach (DataRow row in DTEmployees.Rows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t\t Name: {row["Name"]},\t " +
                                  $"Age: {row["Age"]},\t Salary: {row["Salary"]},\t" +
                                  $" Department: {row["Department"]}");
            }
            DTEmployees.Rows.Clear();
            foreach (DataRow row in DTEmployees.Rows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t\t Name: {row["Name"]},\t " +
                                  $"Age: {row["Age"]},\t Salary: {row["Salary"]},\t" +
                                  $" Department: {row["Department"]}");
            }
            Console.WriteLine("after clear table  : ");
            // declare a new table ID AutoIncrement and autoIncrementSeed,,,
            DataTable DTProducts = new DataTable("Products");
             
            DataColumn dataColumn1 = new DataColumn();
            dataColumn1.DataType = typeof(int);
            dataColumn1.ColumnName = "ID";
            dataColumn1.Unique = true;
            dataColumn1.AllowDBNull = false;
            dataColumn1.Caption = "Product ID";
            dataColumn1.AutoIncrement = true;
            dataColumn1.AutoIncrementSeed = 1;
            dataColumn1.AutoIncrementStep = 1;
            DTProducts.Columns.Add(dataColumn1);

            DataColumn dataColumn2 = new DataColumn();
            dataColumn2.DataType = typeof(string);
            dataColumn2.ColumnName = "Name";
            dataColumn2.Unique = false;
            dataColumn2.AllowDBNull = false;
            dataColumn2.Caption = "Name";
            DTProducts.Columns.Add(dataColumn2);

            DataColumn dataColumn3 = new DataColumn();
            dataColumn3.DataType = typeof(decimal);
            dataColumn3.ColumnName = "Price";
            dataColumn3.Unique = false;
            dataColumn3.AllowDBNull = false;
            dataColumn3.Caption = "Price";
            DTProducts.Columns.Add(dataColumn3);

            DataColumn[] primaryKeyColumns = new DataColumn[1]; 
            primaryKeyColumns[0] = DTProducts.Columns["ID"];
            DTProducts.PrimaryKey = primaryKeyColumns;
            // Adding rows to the DataTable
            DTProducts.Rows.Add(null, "Laptop", 1500.00m);
            DTProducts.Rows.Add(null, "Smartphone", 800.00m);
            DTProducts.Rows.Add(null, "Tablet", 600.00m);
            DTProducts.Rows.Add(4, "watch", 700);
            Console.WriteLine("\nProducts DataTable:");
            foreach (DataRow row in DTProducts.Rows)
            {
                Console.WriteLine($"ID: {row["ID"]},\t Name: {row["Name"]},\t \t" +
                    $"Price: {row["Price"]}");
            }




        }
    }
}
