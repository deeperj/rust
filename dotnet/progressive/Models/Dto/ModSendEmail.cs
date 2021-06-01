using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System;
using progressive.Models;

namespace progressive.Models.Dto
{
    public class ModSendEmail
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public ICollection<ModuleTask> NotDone { get; set; }
        public float Total {get; set; }
        public  Student Student { get; set; }

        public void Deconstruct(out IEnumerable<ModuleTask> notdone, out float total,
                                    out Student stud){
          notdone=NotDone;
          total=Total;
          stud=Student;
        }
      }


}

