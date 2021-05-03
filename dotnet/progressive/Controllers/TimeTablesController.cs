using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class TimeTablesController : ControllerBase
    {
        private readonly ProgressiveContext _context;

        public TimeTablesController(ProgressiveContext context)
        {
            _context = context;
        }

        // GET: api/TimeTables
        [HttpGet]
        public async Task<ActionResult<IEnumerable<TimeTable>>> GetGroupModuleTimes()
        {
            return await _context.GroupModuleTimes.ToListAsync();
        }

        // GET: api/TimeTables/5
        [HttpGet("{id}")]
        public async Task<ActionResult<TimeTable>> GetTimeTable(int id)
        {
            var timeTable = await _context.GroupModuleTimes.FindAsync(id);

            if (timeTable == null)
            {
                return NotFound();
            }

            return timeTable;
        }

        // PUT: api/TimeTables/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        [HttpPut("{id}")]
        public async Task<IActionResult> PutTimeTable(int id, TimeTable timeTable)
        {
            if (id != timeTable.ID)
            {
                return BadRequest();
            }

            _context.Entry(timeTable).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!TimeTableExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/TimeTables
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        [HttpPost]
        public async Task<ActionResult<TimeTable>> PostTimeTable(TimeTable timeTable)
        {
            _context.GroupModuleTimes.Add(timeTable);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetTimeTable", new { id = timeTable.ID }, timeTable);
        }

        // DELETE: api/TimeTables/5
        [HttpDelete("{id}")]
        public async Task<ActionResult<TimeTable>> DeleteTimeTable(int id)
        {
            var timeTable = await _context.GroupModuleTimes.FindAsync(id);
            if (timeTable == null)
            {
                return NotFound();
            }

            _context.GroupModuleTimes.Remove(timeTable);
            await _context.SaveChangesAsync();

            return timeTable;
        }

        private bool TimeTableExists(int id)
        {
            return _context.GroupModuleTimes.Any(e => e.ID == id);
        }
    }
}
