using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System;

namespace progressive.Models
{
    public class Module
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int ModuleID { get; set; }
        public string ModuleName { get; set; }

        public ICollection<Task> Tasks { get; set; }
        public ICollection<Student> Students { get; set; }
        
    }
}

