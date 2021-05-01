using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{

    public class GroupModule
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int ID { get; set; }
        public int GroupID { get; set; }
        public int ModuleID { get; set; }

        public Module Module { get; set; }
        public Group Group { get; set; }

    }
}

