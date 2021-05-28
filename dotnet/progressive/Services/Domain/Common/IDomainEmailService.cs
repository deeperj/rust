using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using progressive.Data;
using progressive.Models;
using EmailService;

namespace progressive.Services.Domain.Common
{
    public interface IDomainEmailService
    {
      string Password
      {
          set;
      }
      Task<EmailStatus>  StudentStatusEmail (IEnumerable<ModuleTask> tasks, Student stud);      
      Task<EmailStatus>  LocalSendStatus (IEnumerable<ModuleTask> tasks, Student stud);      

    }
}
