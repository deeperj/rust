using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_Progressions
{
    public class CreateModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public CreateModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public IActionResult OnGet()
        {
        ViewData["StudentID"] = new SelectList(_context.Students, "ID", "ID");
        ViewData["ModuleTaskID"] = new SelectList(_context.Tasks, "ModuleTaskID", "ModuleTaskID");
            return Page();
        }

        [BindProperty]
        public Progression Progression { get; set; }

        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Progressions.Add(Progression);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}
