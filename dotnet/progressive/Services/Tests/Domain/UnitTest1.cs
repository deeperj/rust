using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Newtonsoft.Json;
using Microsoft.Extensions.Configuration;
using Xunit;
using progressive.Services.Domain;
using progressive.Services.Domain.Common;
using progressive.Data;
using Microsoft.EntityFrameworkCore;
using EmailService;
using System.Diagnostics;
using System.Security;

namespace progressive.Services.Tests.Domain
{
    public class TestDatabase
    {
        private static IDomainFacade _domain;
        private static ProgressiveContext _ctx;

        [Fact]
        public static void Setup(){
            IConfigurationRoot configuration = new ConfigurationBuilder()
            .SetBasePath(AppDomain.CurrentDomain.BaseDirectory)
            .AddJsonFile("appsettings.json")
            .Build();
            var options = SqliteDbContextOptionsBuilderExtensions.UseSqlite(new DbContextOptionsBuilder<ProgressiveContext>(), configuration.GetConnectionString("ProgressiveDB")).Options;
            _ctx = new ProgressiveContext(options);
            var econf=configuration.GetSection("EmailConfiguration")
                .Get<EmailConfiguration>();
            var email = new DomainEmailService(new FluentSender(econf));
            _domain = new Facade(_ctx,email);
        }

        [Fact]
        public static void TestGetGroupModules()
        {
            Setup();
            var result = _domain.GetGroupModules();
            string r =JsonConvert.SerializeObject(result);
            Console.WriteLine(r);
            //Assert.False(result, "1 should not be prime");
        }
        [Fact]
        public static void TestGetUniqueProgressDatesForModuleGroup()
        {
            Setup();
            var result = _domain.GetUniqueAttendanceDates(1,1);
            string r =JsonConvert.SerializeObject(result);
            Console.WriteLine(r);
            //Assert.False(result, "1 should not be prime");
        }
        [Fact]
        public static void TestStudAttendanceByDate()
        {
            Setup();
            //var result = domain.StudAttendanceByDate(1, DateTime.Parse("2021-05-06T08:06:44"));
            var result = _ctx.Progressions.Where(c=>(c.DueDate==DateTime.Parse("2021-05-06T08:06:44") && c.StudentID==1) ).ToList();
            string r =JsonConvert.SerializeObject(result);
            Console.WriteLine(r);
            //Assert.False(result, "1 should not be prime");
        }
        [Fact]
        public static void TestEmailSender()
        {
            Setup();
            var result = _domain.ModuleEmailStatus(2, "");
            string r =JsonConvert.SerializeObject(result);
            Console.WriteLine(r);
            //Assert.False(result, "1 should not be prime");
        }
        [Fact]
        public static void TestSumByGroup()
        {
            Setup();
            var result = _domain.SummativesByModuleGroup(1, 2);
            string r =JsonConvert.SerializeObject(result);
            Console.WriteLine(r);
            //Assert.False(result, "1 should not be prime");
        }
    }
}