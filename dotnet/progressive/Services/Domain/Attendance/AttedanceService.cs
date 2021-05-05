using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
// using Microsoft.AspNetCore.Http;
// using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Services.Domain.Attendace
{
    public class AttendaceService
    {
      protected readonly ProgressiveContext _context;
      public AttendaceService(ProgressiveContext context)
      {
        _context=context;
      }
       
      public async Task<int> SaveAttendance(Progression[] progressions)
      {
          _context.Progressions.AddRange(progressions);
          await _context.SaveChangesAsync();

          return progressions.Count();
      }

    }
}
