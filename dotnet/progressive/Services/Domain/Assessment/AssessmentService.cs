using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
// using Microsoft.AspNetCore.Http;
// using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Services.Domain.Assessment
{
    public class AssessmentService
    {
      protected readonly ProgressiveContext _context;
      public AssessmentService(ProgressiveContext context)
      {
        _context=context;
      }
       
      public async Task<int> SaveAssessmentNOT_USED(Progression[] progressions)
      {
          _context.Progressions.AddRange(progressions);
          await _context.SaveChangesAsync();

          return progressions.Count();
      }
       
      public async Task<int> UpdateAssessmentNOT_USED(Progression[] progressions)
      {
          var a2c =await  _context.Progressions.Where(f=>f.DueDate==progressions[0].DueDate 
                                          && progressions.Select(p=>p.StudentID).ToList()
                                          .Contains(f.StudentID)).ToListAsync();
          var found = a2c.Count();
          _context.Progressions.RemoveRange(a2c);
          _context.AddRange(progressions);
          await _context.SaveChangesAsync();
          return found;
      }
       
      public async Task<int> UploadAssessmentsNOT_USED(Student[] students)
      {
          _context.Students.AddRange(students);
          await _context.SaveChangesAsync();

          return students.Count();
      }
       
      public async Task<IEnumerable<Progression>> SumProgressByModuleNOT_USED(int id, int modid)
      {
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.RPAGType==RPAGType.Summative);
         return await _context.Progressions
                        .Where(c=> c.StudentID==id)
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .ToListAsync();
      }
       
      public async Task<IEnumerable<Progression>> GetAsyncProgressByModuleGroup(int modid, int grpid)
      {
        var gstud=_context.Students.Where(c=>c.GroupID==grpid);
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.RPAGType==RPAGType.Summative);
        return await _context.Progressions
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .Where(c=> gstud.Select(c=>c.ID).ToList().Contains(c.StudentID))
                        .Include(s => s.Task)
                        .ToListAsync();
      }
   
      public async Task<IEnumerable<ModuleTask>> SumTasksByModule(int modid)
      {
        return await _context.Tasks
                        .Where(c=>c.ModuleID==modid
                        && c.RPAGType==RPAGType.Summative)
                        .ToListAsync();
      }
   
      public async Task<EmailStatus> EmailSumStatus(int stid, int modid)
      {
        var stud = _context.Students.Find(stid);
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.RPAGType==RPAGType.Summative);
        var sprog = await _context.Progressions
                        .Where(c=> c.StudentID==stid)
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .ToListAsync();
        
        return EmailStatus.Sent;
      }

    }
}
