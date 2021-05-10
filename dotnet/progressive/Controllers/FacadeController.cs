using Newtonsoft.Json;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;
using progressive.Services.Domain;

namespace progressive.Controllers
{
    [ApiController]
    public class FacadeController : ControllerBase
    {
        private readonly IDomainFacade _domain;

        public FacadeController(IDomainFacade domain)
        {
            _domain = domain;
        }

        // GET: api/Facade/GroupModules
        [Route("api/[controller]/GetGroupModules")]
        public async Task<ActionResult<IEnumerable<GroupModule>>> GetGroupModules()
        {
            return Ok(await _domain.GetGroupModules());
        }

        // GET: api/Facade/GetUniqueAttendanceDates/:modid/:grpid
        [Route("api/[controller]/GetUniqueAttendanceDates/{modid}/{grpid}")]
        public async Task<ActionResult<IEnumerable<GroupModule>>> GetUniqueAttendanceDates(int modid, int grpid)
        {
            return Ok(await _domain.GetUniqueAttendanceDates(modid, grpid));
        }

        // POST: api/Facade/SaveAttendance
        [HttpPost]
        [Route("api/[controller]/SaveAttendance")]
        public async Task<ActionResult<int>> SaveAttendance(Progression[] progressions)
        {
            int count = await _domain.SaveAttendance(progressions);

            return CreatedAtAction("SaveAttendance", new { count = count });
        }

        // POST: api/Facade/UploadStudents
        [HttpPost]
        [Route("api/[controller]/UploadStudents")]
        public async Task<ActionResult<int>> UploadStudents(Student[] students)
        {
            int count = await _domain.UploadStudents(students);

            return CreatedAtAction("UploadStudents", new { count = count });
        }

    }
}
