using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
// using Microsoft.AspNetCore.Http;
// using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;

namespace progressive.Services.Domain.Common
{
    public class GroupModuleCrud
    {
        protected readonly ProgressiveContext _context;

        public GroupModuleCrud(ProgressiveContext context)
        {
            _context = context;
        }

        // GET: api/GroupModules
        public async Task<IEnumerable<GroupModule>> GetGroupModules()
        {
            return await _context.GroupModules.ToListAsync();
        }

        // GET: api/GroupModules/5
        public async Task<GroupModule> GetGroupModule(int id)
        {
            var groupModule = await _context.GroupModules.FindAsync(id);

            if (groupModule == null)
            {
                return groupModule;
            }

            return groupModule;
        }

        // PUT: api/GroupModules/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        public async Task<DBStatus> PutGroupModule(int id, GroupModule groupModule)
        {

            _context.Entry(groupModule).State = EntityState.Modified;
            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!GroupModuleExists(id))
                {
                    return DBStatus.NotFound;
                }
                else
                {
                    throw;
                }
            }

            return DBStatus.NoError;
        }

        // POST: api/GroupModules
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        public async Task<GroupModule> PostGroupModule(GroupModule groupModule)
        {
            _context.GroupModules.Add(groupModule);
            await _context.SaveChangesAsync();

            return groupModule;
        }

        // DELETE: api/GroupModules/5
        public async Task<GroupModule> DeleteGroupModule(int id)
        {
            var groupModule = await _context.GroupModules.FindAsync(id);
            if (groupModule == null)
            {
                return groupModule;
            }

            _context.GroupModules.Remove(groupModule);
            await _context.SaveChangesAsync();

            return groupModule;
        }

        private bool GroupModuleExists(int id)
        {
            return _context.GroupModules.Any(e => e.ID == id);
        }
    }
}
