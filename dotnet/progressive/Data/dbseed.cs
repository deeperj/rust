using progressive.Data;
using progressive.Models;
using System;
using System.Linq;

namespace progressive.Data
{
    public static class DbInitializer
    {
        public static void Initialize(ProgressiveContext context)
        {
            context.Database.EnsureCreated();

            // Look for any students.
            if (context.Students.Any())
            {
                return;   // DB has been seeded
            }

            var batches = new Batch[]
            {
              new Batch{
                BatchCode = "Sep2020",
                Term1StartDate = DateTime.Parse("2020-09-01"),
                Term2StartDate = DateTime.Parse("2021-02-08"),
                MidTerm2Date = DateTime.Parse("2021-03-31"),
                EndTerm2Date = DateTime.Parse("2021-05-03"),
                IsActive = true
              }
            };
            context.Batches.AddRange(batches);
            context.SaveChanges();

            var groups = new Group[]
            {
              new Group{
                BatchID = 1,
                GroupNumber = "12",
                GroupCode = "J1E-G12",
                TaughtTerm = 2,
                Pathway = Pathway.Computing,
                Department = Department.Computing
              }
            };
            context.Groups.AddRange(groups);
            context.SaveChanges();

            var modules = new Module[]
            {
              new Module{
                ModuleName = "Software Engineering",
              }
            };

            context.Modules.AddRange(modules);
            context.SaveChanges();

            var gmodules = new GroupModule[]
            {
              new GroupModule{
                GroupID =1,
                ModuleID =1,
              }
            };

            context.GroupModules.AddRange(gmodules);
            context.SaveChanges();

            var times = new TimeTable[]
            {
              new TimeTable{
                GroupModuleID = 1,
                Term = 2,
                Weekday = DayOfWeek.Monday,
                StartTime = EnumTime._1100,
                EndTime = EnumTime._1300
              }
            };

            context.GroupModuleTimes.AddRange(times);
            context.SaveChanges();

            var students = new Student[]
            {
              new Student{
                LastName="Carson",
                OtherNames="Alexander",
                GroupID = 1,
                UniCode = "u1273400",
                SGCode = ""
              },
            };
            context.Students.AddRange(students);
            context.SaveChanges();

            var tasks = new ModuleTask[]
            {
              new ModuleTask{
                ModuleID = 1,
                TaskType = TaskType.Attendance,
                RPAGType = RPAGType.Attendance,
                InSumRPAG = true,
                TaskName = "Lesson1",
                DueWeek = 10,
                DueLesson = 1,
                DueDate = null
              }
            };

            context.Tasks.AddRange(tasks);
            context.SaveChanges();

            var progressions = new Progression[]
            {
              new Progression{
                ModuleTaskID = 1,
                StudentID = 1,
                TaskAssessment = 100,
                Completed = true,
              },
            };

            context.Progressions.AddRange(progressions);
            context.SaveChanges();
        }
    }
}