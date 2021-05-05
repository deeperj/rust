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
    public class ModuleTasksController : ControllerBase
    {
        private readonly ProgressiveContext _context;

        public ModuleTasksController(ProgressiveContext context)
        {
            _context = context;
        }

        // GET: api/ModuleTasks
        [HttpGet]
        public async Task<ActionResult<IEnumerable<ModuleTask>>> GetTasks()
        {
            return await _context.Tasks.ToListAsync();
        }

        // GET: api/ModuleTasks/5
        [HttpGet("{id}")]
        public async Task<ActionResult<ModuleTask>> GetModuleTask(int id)
        {
            var moduleTask = await _context.Tasks.FindAsync(id);

            if (moduleTask == null)
            {
                return NotFound();
            }

            return moduleTask;
        }

        // PUT: api/ModuleTasks/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        [HttpPut("{id}")]
        public async Task<IActionResult> PutModuleTask(int id, ModuleTask moduleTask)
        {
            if (id != moduleTask.ModuleTaskID)
            {
                return BadRequest();
            }

            _context.Entry(moduleTask).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!ModuleTaskExists(id))
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

        // POST: api/ModuleTasks
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        [HttpPost]
        public async Task<ActionResult<ModuleTask>> PostModuleTask(ModuleTask moduleTask)
        {
            _context.Tasks.Add(moduleTask);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetModuleTask", new { id = moduleTask.ModuleTaskID }, moduleTask);
        }

        // DELETE: api/ModuleTasks/5
        [HttpDelete("{id}")]
        public async Task<ActionResult<ModuleTask>> DeleteModuleTask(int id)
        {
            var moduleTask = await _context.Tasks.FindAsync(id);
            if (moduleTask == null)
            {
                return NotFound();
            }

            _context.Tasks.Remove(moduleTask);
            await _context.SaveChangesAsync();

            return moduleTask;
        }

        private bool ModuleTaskExists(int id)
        {
            return _context.Tasks.Any(e => e.ModuleTaskID == id);
        }
    }
}
