using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_Students
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
        ViewData["GroupID"] = new SelectList(_context.Groups, "GroupID", "GroupID");
            return Page();
        }

        [BindProperty]
        public Student Student { get; set; }

        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Students.Add(Student);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}
