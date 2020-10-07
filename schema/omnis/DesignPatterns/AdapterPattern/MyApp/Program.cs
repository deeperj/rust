
using System;
using System.Configuration;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;

namespace MyApp
{
    class Program
    {
        static void Main()
        {
            DbDataAdapter adapter = GetDataAdapter();

            var ds = new DataSet();
            adapter.Fill(ds);

            Console.WriteLine("*** CUSTOMERS ***\n");

            using (DbDataReader reader = new DataTableReader(ds.Tables[0]))
            {
                while (reader.Read())
                {
                    var name = reader["Name"];
                    var surname = reader["Surname"];
                    var age = reader["Age"];

                    Console.WriteLine("{0} {1} is {2} years old.", name, surname, age);
                }                
            }

            Console.ReadKey();
        }

        static DbDataAdapter GetDataAdapter()
        {
            return new FileDbDataAdapter("Customers.txt");

            //var conn = new SqlConnection(
            //    ConfigurationManager.ConnectionStrings["MyDb"].ConnectionString);
            //return new SqlDataAdapter("SELECT * FROM Customer", conn);
        }
    }

    
}
