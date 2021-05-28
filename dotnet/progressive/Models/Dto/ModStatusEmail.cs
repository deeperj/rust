using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System;
using progressive.Models;

namespace progressive.Models.Dto
{
    public class ModEmailStatus
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public string Password { get; set; }
        public bool SendToday {get; set; }
        public  int GMID { get; set; }
    }
}

