namespace progressive.Models
{

    public class Progression
    {
        public int ProgressionID { get; set; }
        public int TaskID { get; set; }
        public int StudentID { get; set; }
        public int TaskAssessment { get; set; }
        public bool? RPAGRated { get; set; }
        public bool? Completed { get; set; }
        public DateTime DueDate { get; set; }

        public Task Task { get; set; }
        public Student Student { get; set; }
    }
}
