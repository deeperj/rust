using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{

    public class ModuleTask
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int ModuleTaskID { get; set; }
        public int ModuleID { get; set; }
        public int Term { get; set; }
        public TaskType TaskType { get; set; }
        public RPAGType RPAGType { get; set; }
        public bool InSumRPAG { get; set; }
        public string TaskName { get; set; }
        public string Url { get; set; }
        public int DueWeek { get; set; }
        public int DueLesson { get; set; }
        public DateTime? DueDate { get; set; }

        public Module Module { get; set; }

        public ICollection<Progression> Progressions { get; set; }
    }
}

