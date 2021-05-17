using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_ModuleTasks
{
    public class DetailsModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public DetailsModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public ModuleTask ModuleTask { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            ModuleTask = await _context.Tasks
                .Include(m => m.Module).FirstOrDefaultAsync(m => m.ModuleTaskID == id);

            if (ModuleTask == null)
            {
                return NotFound();
            }
            return Page();
        }
    }
}
