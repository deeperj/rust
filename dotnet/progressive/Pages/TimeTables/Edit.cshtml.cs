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

namespace progressive.Pages_TimeTables
{
    public class EditModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public EditModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        [BindProperty]
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
           ViewData["GroupModuleID"] = new SelectList(_context.GroupModules, "ID", "ID");
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

            _context.Attach(TimeTable).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!TimeTableExists(TimeTable.ID))
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

        private bool TimeTableExists(int id)
        {
            return _context.GroupModuleTimes.Any(e => e.ID == id);
        }
    }
}
