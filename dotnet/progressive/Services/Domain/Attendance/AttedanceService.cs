using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
// using Microsoft.AspNetCore.Http;
// using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Services.Domain.Attendance
{
    public class AttendanceService
    {
      protected readonly ProgressiveContext _context;
      public AttendanceService(ProgressiveContext context)
      {
        _context=context;
      }
       
      public async Task<int> SaveAttendance(Progression[] progressions)
      {
          _context.Progressions.AddRange(progressions);
          await _context.SaveChangesAsync();

          return progressions.Count();
      }
       
      public async Task<int> UploadStudents(Student[] students)
      {
          _context.Students.AddRange(students);
          await _context.SaveChangesAsync();

          return students.Count();
      }
       
      public async Task<Progression> StudAttendanceByDate(int id, DateTime param)
      {
          var progression = await _context.Progressions.Where(c=>(c.DueDate==param && c.StudentID==id) ).SingleAsync();
          return progression;
      }
       
      public async Task<float> StudAttendanceScoreByModule(int id, int modid)
      {
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.TaskType==TaskType.Attendance);
         var result =  await _context.Progressions
                        .Where(c=> c.StudentID==id)
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .ToListAsync();
          return  result.Aggregate(0, (acc, x) => acc + x.TaskAssessment);
      }

      public async Task<IEnumerable<DateTime>> GetAsyncUniqueProgressDatesForModuleGroup(int modid, int grpid)
      {
        var gstud=_context.Students.Where(c=>c.GroupID==grpid);
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.TaskType==TaskType.Attendance);
        return await _context.Progressions
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .Where(c=> gstud.Select(c=>c.ID).ToList().Contains(c.StudentID))
                        .Select(c=>c.DueDate).Distinct().ToListAsync();
      }

    }
}
