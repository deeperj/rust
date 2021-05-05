using System;
using Newtonsoft.Json;
using Microsoft.Extensions.Configuration;
using Xunit;
using progressive.Services.Domain;
using progressive.Data;
using Microsoft.EntityFrameworkCore;

namespace progressive.Services.Tests.Domain
{
    public class TestDatabase
    {
        [Fact]
        public static void TestGetGroupModules()
        {
            IConfigurationRoot configuration = new ConfigurationBuilder()
            .SetBasePath(AppDomain.CurrentDomain.BaseDirectory)
            .AddJsonFile("appsettings.json")
            .Build();
            var options = SqliteDbContextOptionsBuilderExtensions.UseSqlite(new DbContextOptionsBuilder<ProgressiveContext>(), configuration.GetConnectionString("ProgressiveDB")).Options;
            var domain = new Facade(new ProgressiveContext(options));
            var result = domain.GetGroupModules();
            string r =JsonConvert.SerializeObject(result);
            Console.WriteLine(r);
            //Assert.False(result, "1 should not be prime");
        }
    }
}