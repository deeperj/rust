using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{
    public enum RPAGType
    {
        Attendance, 
        Formative, 
        Summative,
        Enrollment
    }

    public enum TaskType
    {
        Attendance, 
        Discussion, 
        BiWeeklyTest,
        CourseWork,
        MidSemesterExam,
        MidSemesterMock,
        EndTermExam,
        EndTermMock,
        Quiz,
        ReflectiveJournal,
        Portfolio,
        Enrollment,
        Diagnostic
    }

    public class Task
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int TaskID { get; set; }
        public int ModuleID { get; set; }
        public TaskType TaskType { get; set; }
        public RPAGType RPAGType { get; set; }
        public string TaskName { get; set; }
        public int DueWeek { get; set; }
        public int DueLesson { get; set; }
        public DateTime? DueDate { get; set }

        public Module Module { get; set; }

        public ICollection<Progression> Progressions { get; set; }
    }
}

