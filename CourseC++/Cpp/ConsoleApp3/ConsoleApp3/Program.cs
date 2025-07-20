using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal class Program
	{
		static void Main(string[] args)
		{
			for (int i = 0; i < 10; i++)
			{
				Guid guid = Guid.NewGuid();
				Console.WriteLine(guid);
			}
			
		
		}
	}
}
