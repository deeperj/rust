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
    public class DeleteModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public DeleteModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        [BindProperty]
        public Progression Progression { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            Progression = await _context.Progressions
                .Include(p => p.Student)
                .Include(p => p.Task).FirstOrDefaultAsync(m => m.ProgressionID == id);

            if (Progression == null)
            {
                return NotFound();
            }
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            Progression = await _context.Progressions.FindAsync(id);

            if (Progression != null)
            {
                _context.Progressions.Remove(Progression);
                await _context.SaveChangesAsync();
            }

            return RedirectToPage("./Index");
        }
    }
}
