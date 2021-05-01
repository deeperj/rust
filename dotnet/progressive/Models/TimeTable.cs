using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{
    public enum Weekday
    {
        Sunday, 
        Monday, 
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
    }
    public enum EnumTime
    {
        _0000, 
        _0030, 
        _0100, 
        _0130, 
        _0200,
        _0230,
        _0300,
        _0330,
        _0400,
        _0430,
        _0500,
        _0530,
        _0600,
        _0630,
        _0700,
        _0800,
        _0900,
        _0930,
        _1000, 
        _1030, 
        _1100, 
        _1130, 
        _1200,
        _1230,
        _1300,
        _1330,
        _1400,
        _1430,
        _1500,
        _1530,
        _1600,
        _1630,
        _1700, 
        _1730, 
        _1830, 
        _1900,
        _2000,
        _2100,
        _2200,
        _2300,
    }
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

