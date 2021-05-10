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

namespace progressive.Services.Domain
{
    public class Facade : IDomainFacade
    {
        protected readonly ProgressiveContext _context;
        private GroupModuleService _GroupModuleService;
        private AttendanceService _AttendanceService;

        public Facade(ProgressiveContext context)
        {
            _context = context;
            _GroupModuleService = new GroupModuleService(context);
            _AttendanceService = new AttendanceService(context);
        }

        public async Task<IEnumerable<GroupModule>> GetGroupModules()
        {
            return await _GroupModuleService.GetAllEagerAsync();
        }

        public async Task<IEnumerable<DateTime>> GetUniqueAttendanceDates(int modid, int grpid)
        {
            return await _AttendanceService.GetAsyncUniqueProgressDatesForModuleGroup(modid, grpid);
        }

        public async Task<int> SaveAttendance(Progression[] progressions)
        {
            return await _AttendanceService.SaveAttendance(progressions);
        }

        public async Task<int> UploadStudents(Student[] students)
        {
            return await _AttendanceService.UploadStudents(students);
        }


    }
}
