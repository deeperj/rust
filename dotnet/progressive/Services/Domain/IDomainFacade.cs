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
    }
}