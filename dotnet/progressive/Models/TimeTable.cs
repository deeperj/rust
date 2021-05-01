using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace progressive.Models
{
    public enum WeekDay
    {
        Sunday, 
        Monday, 
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    }
    public enum EnumTime
    {
        _0000, 
        _0100, 
        _0200,
        _0300,
        _0400,
        _0500,
        _0600,
        _0700,
        _0800,
        _0900,
        _1000, 
        _1100, 
        _1200,
        _1300,
        _1400,
        _1500,
        _1600,
        _1700, 
        _1800, 
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
        public int GroupID { get; set; }
        public WeekDay WeekDay { get; set; }
        public EnumTime StartTime { get; set; }
        public EnumTime EndTime { get; set; }
        
        public Group Group { get; set; }

        public ICollection<Student> Students { get; set; }
    }
}

