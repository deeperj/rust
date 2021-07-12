using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;
using progressive.Models.Dto;
using progressive.Services.Domain.Common;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace progressive.Services.Domain.Assessment
{
    public class AssessmentService
    {
      protected readonly ProgressiveContext _context;
      protected readonly IDomainEmailService _email;

      public AssessmentService(ProgressiveContext context, IDomainEmailService email)
      {
        _context=context;
        _email=email;
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
       
      public async Task<IEnumerable<Progression>> GetAsyncProgressByModuleGroup(int modid, int grpid, RPAGType rtype)
      {
        var gstud=_context.Students.Where(c=>c.GroupID==grpid);
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.RPAGType==rtype);
        return await _context.Progressions
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .Where(c=> gstud.Select(c=>c.ID).ToList().Contains(c.StudentID))
                        .Include(s => s.Task)
                        .ToListAsync();
      }
   
      public async Task<IEnumerable<ModuleTask>> SumTasksByModule(int modid, RPAGType rtype)
      {
        return await _context.Tasks
              .Where(c=>c.ModuleID==modid
              && c.RPAGType==rtype)
              .ToListAsync();
      }
   
   //GroupModuleEmailStatus
      public async Task<EmailStatus> DoStatusEmail(int gmid,string pass)
      {
        var gm= await _context.GroupModules.Where(s=>s.ID==gmid)
                .Include(s => s.Module)
                .Include(s => s.Group)
                .Include(s => s.Group.Students) 
                .SingleAsync();
        foreach(var stud in gm.Group.Students){
          await this.GroupModuleEmailStatus(stud.ID,gm.Module.ModuleID,pass);
        }
        return EmailStatus.NotSent;
      }

      public async Task<EmailStatus> GroupModuleEmailStatus(int stid, int modid,string pass)
      {
        var stud = _context.Students.Find(stid);
        var modtasks=_context.Tasks
                        .Where(c=>c.ModuleID==modid)
                        .Where(c=>c.RPAGType==RPAGType.Summative);
        var sprog = await _context.Progressions
                        // .Include(c=>c.Task)
                        .Where(c=> c.StudentID==stid)
                        .Where(c=> modtasks.Select(c=>c.ModuleTaskID).ToList().Contains(c.ModuleTaskID))
                        .Select(c=>c.ModuleTaskID).ToListAsync();
        var not_done=modtasks.Where(p => !sprog.Any(p2 => p2 == p.ModuleTaskID)).ToList();
        _email.Password=pass;
        var dtosend = new ModSendEmail();
        // Console.WriteLine("AssessmentService.GroupModuleEmailStatus: notdone="+not_done.Count());
        // Console.WriteLine("AssessmentService.GroupModuleEmailStatus: tasks="+_context.Tasks.Where(c=>c.ModuleID==modid).Count());
        // Console.WriteLine("AssessmentService.GroupModuleEmailStatus: sprogs count="+_context.Progressions.Where(c=> c.StudentID==stid).Count());
        dtosend.NotDone=not_done;
        dtosend.Student=stud;
        dtosend.Total=modtasks.Count();
        await _email.LocalSendStatus(dtosend);
        return await _email.StudentStatusEmail(dtosend);
      }

    }
}
