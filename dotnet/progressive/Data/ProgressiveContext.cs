using Microsoft.EntityFrameworkCore;
using progressive.Models;

namespace progressive.Data
{
    public class ProgressiveContext : DbContext
    {
        public ProgressiveContext (DbContextOptions<ProgressiveContext> options)
            : base(options)
        {
        }

        public DbSet<Student> Students { get; set; }
        public DbSet<Batch> Batches { get; set; }
        public DbSet<ModuleTask> Tasks { get; set; }
        public DbSet<Module> Modules { get; set; }
        public DbSet<Group> Groups { get; set; }
        public DbSet<GroupModule> GroupModules { get; set; }
        public DbSet<Progression> Progressions { get; set; }
        public DbSet<TimeTable> GroupModuleTimes { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Batch>().ToTable("Batch");
            modelBuilder.Entity<ModuleTask>().ToTable("Task");
            modelBuilder.Entity<Student>().ToTable("Student");
            modelBuilder.Entity<Module>().ToTable("Module");
            modelBuilder.Entity<Group>().ToTable("Group");
            modelBuilder.Entity<GroupModule>().ToTable("GroupModule");
            modelBuilder.Entity<Progression>().ToTable("Progression");
            modelBuilder.Entity<TimeTable>().ToTable("TimeTable");
        }
    }
}