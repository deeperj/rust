
using System;
using System.Data;
using System.Data.Common;

namespace AbstractFactory
{
    public class DbProviderFactoryExample
    {
        public static void Run()
        {
            var factory = DbProviderFactories.GetFactory("System.Data.SqlClient");
            
            using (DbConnection connection = factory.CreateConnection())
            {
                connection.ConnectionString = 
                    @"Data Source=.\SQLExpress;Initial Catalog=AdventureWorks;Integrated Security=SSPI;";
                connection.Open();

                DbCommand command = factory.CreateCommand();
                command.Connection = connection;
                command.CommandType = CommandType.Text;
                command.CommandText = "select * from Person.Address";

                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Console.WriteLine("AddressLine1: {0}", reader["AddressLine1"]);
                        Console.WriteLine("City: {0}", reader["City"]);
                        Console.WriteLine();                        
                    }
                }
            }
        }
    }
}
