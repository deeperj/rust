using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;
using progressive.Services.Domain.Common;

namespace progressive.Services.Domain
{
    public interface IDomainFacade
    {
        Task<IEnumerable<GroupModule>> GetGroupModules();
        Task<int> SaveAttendance(Progression[] progressions);
        Task<int> UploadStudents(Student[] students);
        Task<IEnumerable<DateTime>> GetUniqueAttendanceDates(int modid, int grpid);
        Task<Progression> StudAttendanceByDate(int id, DateTime param);
        Task<float> StudAttendanceScoreByModule(int id, int module);
    }
}