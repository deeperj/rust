using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{
    public class Batch
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int BatchID { get; set; }
        public string BatchName { get; set; }
        public DateTime StartDate { get; set; }
        public DateTime MidSemDate { get; set; }
        public DateTime EndSemDate { get; set; }

        public ICollection<Student> Students { get; set; }
    }
}

