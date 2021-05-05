using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{
    public class TimeTable
    {
        // [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int ID { get; set; }
        public int GroupModuleID { get; set; }
        public int Term { get; set; }
        public Weekday Weekday { get; set; }
        public EnumTime StartTime { get; set; }
        public EnumTime EndTime { get; set; }

        public GroupModule GroupModule { get; set; }

    }
}

