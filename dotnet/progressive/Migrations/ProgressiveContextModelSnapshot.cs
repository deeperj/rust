﻿// <auto-generated />
using System;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;
using progressive.Data;

namespace progressive.Migrations
{
    [DbContext(typeof(ProgressiveContext))]
    partial class ProgressiveContextModelSnapshot : ModelSnapshot
    {
        protected override void BuildModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "5.0.5");

            modelBuilder.Entity("progressive.Models.Batch", b =>
                {
                    b.Property<int>("BatchID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<string>("BatchCode")
                        .HasColumnType("TEXT");

                    b.Property<DateTime>("EndTerm1Date")
                        .HasColumnType("TEXT");

                    b.Property<DateTime>("EndTerm2Date")
                        .HasColumnType("TEXT");

                    b.Property<bool>("IsActive")
                        .HasColumnType("INTEGER");

                    b.Property<DateTime>("MidTerm1Date")
                        .HasColumnType("TEXT");

                    b.Property<DateTime>("MidTerm2Date")
                        .HasColumnType("TEXT");

                    b.Property<DateTime>("Term1StartDate")
                        .HasColumnType("TEXT");

                    b.Property<DateTime>("Term2StartDate")
                        .HasColumnType("TEXT");

                    b.HasKey("BatchID");

                    b.ToTable("Batch");
                });

            modelBuilder.Entity("progressive.Models.Group", b =>
                {
                    b.Property<int>("GroupID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<int>("BatchID")
                        .HasColumnType("INTEGER");

                    b.Property<int>("Department")
                        .HasColumnType("INTEGER");

                    b.Property<string>("GroupCode")
                        .HasColumnType("TEXT");

                    b.Property<int>("GroupNumber")
                        .HasColumnType("INTEGER");

                    b.Property<int>("Pathway")
                        .HasColumnType("INTEGER");

                    b.HasKey("GroupID");

                    b.HasIndex("BatchID");

                    b.ToTable("Group");
                });

            modelBuilder.Entity("progressive.Models.GroupModule", b =>
                {
                    b.Property<int>("ID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<int>("GroupID")
                        .HasColumnType("INTEGER");

                    b.Property<int>("ModuleID")
                        .HasColumnType("INTEGER");

                    b.HasKey("ID");

                    b.HasIndex("GroupID");

                    b.HasIndex("ModuleID");

                    b.ToTable("GroupModule");
                });

            modelBuilder.Entity("progressive.Models.Module", b =>
                {
                    b.Property<int>("ModuleID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<string>("ModuleName")
                        .HasColumnType("TEXT");

                    b.HasKey("ModuleID");

                    b.ToTable("Module");
                });

            modelBuilder.Entity("progressive.Models.ModuleTask", b =>
                {
                    b.Property<int>("ModuleTaskID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<DateTime?>("DueDate")
                        .HasColumnType("TEXT");

                    b.Property<int>("DueLesson")
                        .HasColumnType("INTEGER");

                    b.Property<int>("DueWeek")
                        .HasColumnType("INTEGER");

                    b.Property<bool>("InSumRPAG")
                        .HasColumnType("INTEGER");

                    b.Property<int>("ModuleID")
                        .HasColumnType("INTEGER");

                    b.Property<int>("RPAGType")
                        .HasColumnType("INTEGER");

                    b.Property<string>("TaskName")
                        .HasColumnType("TEXT");

                    b.Property<int>("TaskType")
                        .HasColumnType("INTEGER");

                    b.Property<int>("Term")
                        .HasColumnType("INTEGER");

                    b.Property<string>("Url")
                        .HasColumnType("TEXT");

                    b.HasKey("ModuleTaskID");

                    b.HasIndex("ModuleID");

                    b.ToTable("Task");
                });

            modelBuilder.Entity("progressive.Models.Progression", b =>
                {
                    b.Property<int>("ProgressionID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<string>("Comments")
                        .HasColumnType("TEXT");

                    b.Property<bool?>("Completed")
                        .HasColumnType("INTEGER");

                    b.Property<DateTime>("DueDate")
                        .HasColumnType("TEXT");

                    b.Property<int>("ModuleTaskID")
                        .HasColumnType("INTEGER");

                    b.Property<int>("StudentID")
                        .HasColumnType("INTEGER");

                    b.Property<int>("TaskAssessment")
                        .HasColumnType("INTEGER");

                    b.HasKey("ProgressionID");

                    b.HasIndex("ModuleTaskID");

                    b.HasIndex("StudentID");

                    b.ToTable("Progression");
                });

            modelBuilder.Entity("progressive.Models.Student", b =>
                {
                    b.Property<int>("ID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<int>("GroupID")
                        .HasColumnType("INTEGER");

                    b.Property<string>("LastName")
                        .HasColumnType("TEXT");

                    b.Property<string>("OtherNames")
                        .HasColumnType("TEXT");

                    b.Property<string>("SGCode")
                        .HasColumnType("TEXT");

                    b.Property<string>("UniCode")
                        .HasColumnType("TEXT");

                    b.HasKey("ID");

                    b.HasIndex("GroupID");

                    b.ToTable("Student");
                });

            modelBuilder.Entity("progressive.Models.TimeTable", b =>
                {
                    b.Property<int>("ID")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<int>("EndTime")
                        .HasColumnType("INTEGER");

                    b.Property<int>("GroupModuleID")
                        .HasColumnType("INTEGER");

                    b.Property<int>("StartTime")
                        .HasColumnType("INTEGER");

                    b.Property<int>("Term")
                        .HasColumnType("INTEGER");

                    b.Property<int>("Weekday")
                        .HasColumnType("INTEGER");

                    b.HasKey("ID");

                    b.HasIndex("GroupModuleID");

                    b.ToTable("TimeTable");
                });

            modelBuilder.Entity("progressive.Models.Group", b =>
                {
                    b.HasOne("progressive.Models.Batch", "Batch")
                        .WithMany("Groups")
                        .HasForeignKey("BatchID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Batch");
                });

            modelBuilder.Entity("progressive.Models.GroupModule", b =>
                {
                    b.HasOne("progressive.Models.Group", "Group")
                        .WithMany("GroupModules")
                        .HasForeignKey("GroupID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.HasOne("progressive.Models.Module", "Module")
                        .WithMany("GroupModules")
                        .HasForeignKey("ModuleID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Group");

                    b.Navigation("Module");
                });

            modelBuilder.Entity("progressive.Models.ModuleTask", b =>
                {
                    b.HasOne("progressive.Models.Module", "Module")
                        .WithMany("Tasks")
                        .HasForeignKey("ModuleID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Module");
                });

            modelBuilder.Entity("progressive.Models.Progression", b =>
                {
                    b.HasOne("progressive.Models.ModuleTask", "Task")
                        .WithMany("Progressions")
                        .HasForeignKey("ModuleTaskID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.HasOne("progressive.Models.Student", "Student")
                        .WithMany("Progressions")
                        .HasForeignKey("StudentID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Student");

                    b.Navigation("Task");
                });

            modelBuilder.Entity("progressive.Models.Student", b =>
                {
                    b.HasOne("progressive.Models.Group", "Group")
                        .WithMany("Students")
                        .HasForeignKey("GroupID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Group");
                });

            modelBuilder.Entity("progressive.Models.TimeTable", b =>
                {
                    b.HasOne("progressive.Models.GroupModule", "GroupModule")
                        .WithMany()
                        .HasForeignKey("GroupModuleID")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("GroupModule");
                });

            modelBuilder.Entity("progressive.Models.Batch", b =>
                {
                    b.Navigation("Groups");
                });

            modelBuilder.Entity("progressive.Models.Group", b =>
                {
                    b.Navigation("GroupModules");

                    b.Navigation("Students");
                });

            modelBuilder.Entity("progressive.Models.Module", b =>
                {
                    b.Navigation("GroupModules");

                    b.Navigation("Tasks");
                });

            modelBuilder.Entity("progressive.Models.ModuleTask", b =>
                {
                    b.Navigation("Progressions");
                });

            modelBuilder.Entity("progressive.Models.Student", b =>
                {
                    b.Navigation("Progressions");
                });
#pragma warning restore 612, 618
        }
    }
}
