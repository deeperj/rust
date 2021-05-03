using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
// using Microsoft.AspNetCore.Http;
// using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Services.Domain.Common
{
    public class GroupModuleService : GroupModuleCrud
    {
        public GroupModuleService(ProgressiveContext context):base(context)
        {
        }

        public async Task<IEnumerable<GroupModule>> GetAllEagerAsync()
        {
            return await _context.GroupModules
                            .Include(s => s.Module)
                            .Include(s => s.Group)
                            .Include(s => s.Group.Students)
                            .ToListAsync();
        }

       
    }
}
