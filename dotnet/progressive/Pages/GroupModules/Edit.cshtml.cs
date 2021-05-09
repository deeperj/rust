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

namespace progressive.Pages_GroupModules
{
    public class EditModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public EditModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        [BindProperty]
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
           ViewData["GroupID"] = new SelectList(_context.Groups, "GroupID", "GroupID");
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

            _context.Attach(GroupModule).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!GroupModuleExists(GroupModule.ID))
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

        private bool GroupModuleExists(int id)
        {
            return _context.GroupModules.Any(e => e.ID == id);
        }
    }
}
