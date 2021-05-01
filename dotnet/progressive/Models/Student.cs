using System;
using System.Collections.Generic;

namespace progressive.Models
{
    public class Student
    {
        public int ID { get; set; }
        public int ModuleID { get; set; }
        public int GroupID { get; set; }
        public int BatchID { get; set; }
        public string UniCode { get; set; }
        public string StudyCode { get; set; }
        public string LastName { get; set; }
        public string OtherNames { get; set; }

        public ICollection<Progression> Progressions { get; set; }
    }
}