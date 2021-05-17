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
    public class DetailsModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public DetailsModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public GroupModule GroupModule { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            GroupModule = await _context.GroupModules
                .Include(g => g.Group)
                .Include(g => g.Module).FirstOrDefaultAsync(m => m.ID == id);

            if (GroupModule == null)
            {
                return NotFound();
            }
            return Page();
        }
    }
}
