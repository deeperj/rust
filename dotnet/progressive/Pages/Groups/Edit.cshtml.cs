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

namespace progressive.Pages_Groups
{
    public class EditModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public EditModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        [BindProperty]
        public Group Group { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            Group = await _context.Groups
                .Include(x => x.Batch).FirstOrDefaultAsync(m => m.GroupID == id);

            if (Group == null)
            {
                return NotFound();
            }
            ViewData["BatchID"] = new SelectList(_context.Batches, "BatchID", "BatchID");
            ViewData["Departments"] = Global.GetEnumLookupKey<Department>();
            ViewData["Pathway"] = Global.GetEnumLookupKey<Pathway>();
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

            _context.Attach(Group).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!GroupExists(Group.GroupID))
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

        private bool GroupExists(int id)
        {
            return _context.Groups.Any(e => e.GroupID == id);
        }
    }
}
