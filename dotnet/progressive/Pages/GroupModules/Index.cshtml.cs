using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_GroupModules
{
    public class IndexModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public IndexModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public IList<GroupModule> GroupModule { get;set; }

        public async Task OnGetAsync()
        {
            GroupModule = await _context.GroupModules
                .Include(g => g.Group)
                .Include(g => g.Module).ToListAsync();
        }
    }
}
