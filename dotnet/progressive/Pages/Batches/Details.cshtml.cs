using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Pages_Batches
{
    public class DetailsModel : PageModel
    {
        private readonly progressive.Data.ProgressiveContext _context;

        public DetailsModel(progressive.Data.ProgressiveContext context)
        {
            _context = context;
        }

        public Batch Batch { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            Batch = await _context.Batches.FirstOrDefaultAsync(m => m.BatchID == id);

            if (Batch == null)
            {
                return NotFound();
            }
            return Page();
        }
    }
}
