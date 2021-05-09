using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_Progressions
{
    public class EditModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public EditModel(progressive.Data.ProgressiveContext context)
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
           ViewData["StudentID"] = new SelectList(_context.Students, "ID", "ID");
           ViewData["ModuleTaskID"] = new SelectList(_context.Tasks, "ModuleTaskID", "ModuleTaskID");
            return Page();
        }

        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Attach(Progression).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!ProgressionExists(Progression.ProgressionID))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return RedirectToPage("./Index");
        }

        private bool ProgressionExists(int id)
        {
            return _context.Progressions.Any(e => e.ProgressionID == id);
        }
    }
}
