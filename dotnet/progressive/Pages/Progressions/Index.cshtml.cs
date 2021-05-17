using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_Progressions
{
    public class IndexModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public IndexModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public IList<Progression> Progression { get;set; }

        public async Task OnGetAsync()
        {
            Progression = await _context.Progressions
                .Include(p => p.Student)
                .Include(p => p.Task).ToListAsync();
        }
    }
}
