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
    // [Route("api/[controller]")]
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

    }
}