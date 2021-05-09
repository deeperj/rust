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

namespace progressive.Pages_ModuleTasks
{
    public class EditModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public EditModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        [BindProperty]
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
           ViewData["ModuleID"] = new SelectList(_context.Modules, "ModuleID", "ModuleID");
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

            _context.Attach(ModuleTask).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!ModuleTaskExists(ModuleTask.ModuleTaskID))
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

        private bool ModuleTaskExists(int id)
        {
            return _context.Tasks.Any(e => e.ModuleTaskID == id);
        }
    }
}
