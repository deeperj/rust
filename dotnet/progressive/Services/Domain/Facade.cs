using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
// using Microsoft.AspNetCore.Http;
// using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;
using progressive.Services.Domain.Common;
using progressive.Services.Domain.Attendance;
using progressive.Services.Domain.Assessment;

namespace progressive.Services.Domain
{
    public class Facade : IDomainFacade
    {
        protected readonly ProgressiveContext _context;
        private GroupModuleService _GroupModuleService;
        private AttendanceService _AttendanceService;
        private AssessmentService _AssessmentService;

        public Facade(ProgressiveContext context, IDomainEmailService email)
        {
            _context = context;
            _GroupModuleService = new GroupModuleService(context);
            _AttendanceService = new AttendanceService(context);
            _AssessmentService = new AssessmentService(context, email);
        }

        public async Task<IEnumerable<GroupModule>> GetGroupModules()
        {
            return await _GroupModuleService.GetAllEagerAsync();
        }

        public async Task<IEnumerable<DateTime>> GetUniqueAttendanceDates(int modid, int grpid)
        {
            return await _AttendanceService.GetAsyncUniqueProgressDatesForModuleGroup(modid, grpid);
        }
        public async Task<IEnumerable<Progression>> SummativesByModuleGroup(int modid, int grpid)
        {
            return await _AssessmentService.GetAsyncProgressByModuleGroup(modid, grpid);
        }
        public async Task<EmailStatus> ModuleEmailStatus(int gmid, string pass )
        {
            return await _AssessmentService.DoStatusEmail (gmid, pass);
        }
        public async Task<IEnumerable<ModuleTask>> SumTasksByModule(int modid)
        {
            return await _AssessmentService.SumTasksByModule(modid);
        }

        public async Task<Progression> StudAttendanceByDate(int id, DateTime param)
        {
            return await _AttendanceService.StudAttendanceByDate(id, param);
        }

        public async Task<IEnumerable<Progression>> SummativesNOT_USED(int id, int modid)
        {
            return await _AssessmentService.SumProgressByModuleNOT_USED(id, modid);
        }

        public async Task<float> StudAttendanceScoreByModule(int id, int modid)
        {
            return await _AttendanceService.StudAttendanceScoreByModule(id, modid);
        }
 
        public async Task<int> SaveAttendance(Progression[] progressions)
        {
            return await _AttendanceService.SaveAttendance(progressions);
        }

        public async Task<int> UpdateAttendance(Progression[] progressions)
        {
            return await _AttendanceService.UpdateAttendance(progressions);
        }

        public async Task<int> UploadStudents(Student[] students)
        {
            return await _AttendanceService.UploadStudents(students);
        }


    }
}
