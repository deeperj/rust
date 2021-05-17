using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_TimeTables
{
    public class DetailsModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public DetailsModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public TimeTable TimeTable { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            TimeTable = await _context.GroupModuleTimes
                .Include(t => t.GroupModule).FirstOrDefaultAsync(m => m.ID == id);

            if (TimeTable == null)
            {
                return NotFound();
            }
            return Page();
        }
    }
}
