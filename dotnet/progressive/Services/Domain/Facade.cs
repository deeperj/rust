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

namespace progressive.Services.Domain
{
    public class Facade : IDomainFacade
    {
        protected readonly ProgressiveContext _context;
        private GroupModuleService _GroupModuleService;

        public Facade(ProgressiveContext context)
        {
            _context = context;
            _GroupModuleService = new GroupModuleService(context);
        }

        public async Task<IEnumerable<GroupModule>> GetGroupModules()
        {
            return await _GroupModuleService.GetAllEagerAsync();
        }

    }
}
