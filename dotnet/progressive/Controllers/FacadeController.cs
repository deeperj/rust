using Newtonsoft.Json;
using System.Collections.Generic;
using System.Linq;
using System;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;
using progressive.Models.Dto;
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

        // POST: api/Facade/SendWeeklyStatus
        [HttpPost]
        [Route("api/[controller]/SendWeeklyStatus")]
        public async Task<ActionResult<EmailStatus>> SendWeeklyStatus(ModEmailStatus sws)
        {
            if(!sws.SendToday)
                return Ok(EmailStatus.NotSent);
            var status = await _domain.ModuleEmailStatus(sws.GMID, sws.Password);

            return Ok(status);
        }

        // POST: api/Facade/UploadStudents
        [HttpPost]
        [Route("api/[controller]/UploadStudents")]
        public async Task<ActionResult<int>> UploadStudents(Student[] students)
        {
            int count = await _domain.UploadStudents(students);

            return CreatedAtAction("UploadStudents", new { count = count });
        }

        // POST: api/Facade/UpdateAttendance  
        [HttpPost]
        [Route("api/[controller]/UpdateAttendance")]
        public async Task<ActionResult<int>> UpdateAttendance(Progression[] progressions)
        {
            int count = await _domain.UpdateAttendance(progressions);

            return CreatedAtAction("UpdateAttendance", new { count = count });
        }

        // GET: api/Facade/StudAttendanceByDate/:id/:dateparam
        [Route("api/[controller]/StudAttendanceByDate/{id}/{param}")]
        // [HttpGet("{id}")]
        public async Task<ActionResult<Progression>> StudAttendanceByDate(int id, DateTime param)
        {
            var progression = await _domain.StudAttendanceByDate(id,param);

            if (progression == null)
            {
                return NotFound();
            }
            return progression;
        }

        // GET: api/Facade/StudAttendanceByDate/:id/:modid
        [Route("api/[controller]/StudAttendanceByModule/{id}/{modid}")]
        // [HttpGet("{id}")]
        public async Task<ActionResult<IEnumerable<Progression>>> StudAttendanceByModule(int id, int modid)
        {
            var progressions = await _domain.StudAttendanceByModule(id,modid);

            if (progressions == null)
            {
                return BadRequest();
            }
            return Ok(progressions);
        }

        // GET: api/Facade/Summatives/id/modid
        [Route("api/[controller]/Summatives/{id}/{modid}")]
        // [HttpGet("{id}")]
        public async Task<ActionResult<IEnumerable<Progression>>> SummativesNOT_USED(int id, int modid)
        {
            var progressions = await _domain.SummativesNOT_USED(id,modid);

            if (progressions == null)
            {
                return BadRequest();
            }
            return Ok(progressions);
        }

        // GET: api/Facade/SummativesByGroupModule/id/modid/rtype
        [Route("api/[controller]/SummativesByGroupModule/{id}/{modid}/{rtype}")]
        // [HttpGet("{id}")]
        public async Task<ActionResult<IEnumerable<Progression>>> SummativesByGroupModule(int id, int modid,RPAGType rtype)
        {
            var progressions = await _domain.SummativesByModuleGroup(id,modid,rtype);

            if (progressions == null)
            {
                return BadRequest();
            }
            return Ok(progressions);
        }
        // GET: api/Facade/SumTasksByModule/id/rtype
        [Route("api/[controller]/SumTasksByModule/{id}/{rtype}")]
        // [HttpGet("{id}")]
        public async Task<ActionResult<IEnumerable<ModuleTask>>> SummativesByGroupModule(int id, RPAGType rtype)
        {
            var tasks = await _domain.SumTasksByModule(id, rtype);

            if (tasks == null)
            {
                return BadRequest();
            }
            return Ok(tasks);
        }

    }
}
