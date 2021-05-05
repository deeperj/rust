using System;

namespace progressive.Models
{

    public class Progression
    {
        public int ProgressionID { get; set; }
        public int ModuleTaskID { get; set; }
        public int StudentID { get; set; }
        public int TaskAssessment { get; set; }
        public bool? Completed { get; set; }
        public DateTime DueDate { get; set; }
        public string Comments { get; set; }

        public ModuleTask Task { get; set; }
        public Student Student { get; set; }
    }
}
