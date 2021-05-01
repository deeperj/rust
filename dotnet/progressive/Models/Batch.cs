using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System;

namespace progressive.Models
{
    public class Batch
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int BatchID { get; set; }
        public string BatchCode { get; set; }
        public DateTime Term1StartDate { get; set; }
        public DateTime Term2StartDate { get; set; }
        public DateTime MidTerm1Date { get; set; }
        public DateTime EndTerm1Date { get; set; }
        public DateTime MidTerm2Date { get; set; }
        public DateTime EndTerm2Date { get; set; }
        public bool IsActive {get; set; }

        public ICollection<Group> Groups { get; set; }
    }
}

