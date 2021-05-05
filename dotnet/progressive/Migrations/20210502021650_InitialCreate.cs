using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace progressive.Migrations
{
    public partial class InitialCreate : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Batch",
                columns: table => new
                {
                    BatchID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    BatchCode = table.Column<string>(type: "TEXT", nullable: true),
                    Term1StartDate = table.Column<DateTime>(type: "TEXT", nullable: false),
                    Term2StartDate = table.Column<DateTime>(type: "TEXT", nullable: false),
                    MidTerm1Date = table.Column<DateTime>(type: "TEXT", nullable: false),
                    EndTerm1Date = table.Column<DateTime>(type: "TEXT", nullable: false),
                    MidTerm2Date = table.Column<DateTime>(type: "TEXT", nullable: false),
                    EndTerm2Date = table.Column<DateTime>(type: "TEXT", nullable: false),
                    IsActive = table.Column<bool>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Batch", x => x.BatchID);
                });

            migrationBuilder.CreateTable(
                name: "Module",
                columns: table => new
                {
                    ModuleID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    ModuleName = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Module", x => x.ModuleID);
                });

            migrationBuilder.CreateTable(
                name: "Group",
                columns: table => new
                {
                    GroupID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    BatchID = table.Column<int>(type: "INTEGER", nullable: false),
                    GroupNumber = table.Column<int>(type: "INTEGER", nullable: false),
                    GroupCode = table.Column<string>(type: "TEXT", nullable: true),
                    Pathway = table.Column<int>(type: "INTEGER", nullable: false),
                    Department = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Group", x => x.GroupID);
                    table.ForeignKey(
                        name: "FK_Group_Batch_BatchID",
                        column: x => x.BatchID,
                        principalTable: "Batch",
                        principalColumn: "BatchID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Task",
                columns: table => new
                {
                    ModuleTaskID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    ModuleID = table.Column<int>(type: "INTEGER", nullable: false),
                    Term = table.Column<int>(type: "INTEGER", nullable: false),
                    TaskType = table.Column<int>(type: "INTEGER", nullable: false),
                    RPAGType = table.Column<int>(type: "INTEGER", nullable: false),
                    InSumRPAG = table.Column<bool>(type: "INTEGER", nullable: false),
                    TaskName = table.Column<string>(type: "TEXT", nullable: true),
                    Url = table.Column<string>(type: "TEXT", nullable: true),
                    DueWeek = table.Column<int>(type: "INTEGER", nullable: false),
                    DueLesson = table.Column<int>(type: "INTEGER", nullable: false),
                    DueDate = table.Column<DateTime>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Task", x => x.ModuleTaskID);
                    table.ForeignKey(
                        name: "FK_Task_Module_ModuleID",
                        column: x => x.ModuleID,
                        principalTable: "Module",
                        principalColumn: "ModuleID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "GroupModule",
                columns: table => new
                {
                    ID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    GroupID = table.Column<int>(type: "INTEGER", nullable: false),
                    ModuleID = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_GroupModule", x => x.ID);
                    table.ForeignKey(
                        name: "FK_GroupModule_Group_GroupID",
                        column: x => x.GroupID,
                        principalTable: "Group",
                        principalColumn: "GroupID",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_GroupModule_Module_ModuleID",
                        column: x => x.ModuleID,
                        principalTable: "Module",
                        principalColumn: "ModuleID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Student",
                columns: table => new
                {
                    ID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    GroupID = table.Column<int>(type: "INTEGER", nullable: false),
                    UniCode = table.Column<string>(type: "TEXT", nullable: true),
                    SGCode = table.Column<string>(type: "TEXT", nullable: true),
                    LastName = table.Column<string>(type: "TEXT", nullable: true),
                    OtherNames = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Student", x => x.ID);
                    table.ForeignKey(
                        name: "FK_Student_Group_GroupID",
                        column: x => x.GroupID,
                        principalTable: "Group",
                        principalColumn: "GroupID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "TimeTable",
                columns: table => new
                {
                    ID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    GroupModuleID = table.Column<int>(type: "INTEGER", nullable: false),
                    Term = table.Column<int>(type: "INTEGER", nullable: false),
                    Weekday = table.Column<int>(type: "INTEGER", nullable: false),
                    StartTime = table.Column<int>(type: "INTEGER", nullable: false),
                    EndTime = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_TimeTable", x => x.ID);
                    table.ForeignKey(
                        name: "FK_TimeTable_GroupModule_GroupModuleID",
                        column: x => x.GroupModuleID,
                        principalTable: "GroupModule",
                        principalColumn: "ID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Progression",
                columns: table => new
                {
                    ProgressionID = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    ModuleTaskID = table.Column<int>(type: "INTEGER", nullable: false),
                    StudentID = table.Column<int>(type: "INTEGER", nullable: false),
                    TaskAssessment = table.Column<int>(type: "INTEGER", nullable: false),
                    Completed = table.Column<bool>(type: "INTEGER", nullable: true),
                    DueDate = table.Column<DateTime>(type: "TEXT", nullable: false),
                    Comments = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Progression", x => x.ProgressionID);
                    table.ForeignKey(
                        name: "FK_Progression_Student_StudentID",
                        column: x => x.StudentID,
                        principalTable: "Student",
                        principalColumn: "ID",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_Progression_Task_ModuleTaskID",
                        column: x => x.ModuleTaskID,
                        principalTable: "Task",
                        principalColumn: "ModuleTaskID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Group_BatchID",
                table: "Group",
                column: "BatchID");

            migrationBuilder.CreateIndex(
                name: "IX_GroupModule_GroupID",
                table: "GroupModule",
                column: "GroupID");

            migrationBuilder.CreateIndex(
                name: "IX_GroupModule_ModuleID",
                table: "GroupModule",
                column: "ModuleID");

            migrationBuilder.CreateIndex(
                name: "IX_Progression_ModuleTaskID",
                table: "Progression",
                column: "ModuleTaskID");

            migrationBuilder.CreateIndex(
                name: "IX_Progression_StudentID",
                table: "Progression",
                column: "StudentID");

            migrationBuilder.CreateIndex(
                name: "IX_Student_GroupID",
                table: "Student",
                column: "GroupID");

            migrationBuilder.CreateIndex(
                name: "IX_Task_ModuleID",
                table: "Task",
                column: "ModuleID");

            migrationBuilder.CreateIndex(
                name: "IX_TimeTable_GroupModuleID",
                table: "TimeTable",
                column: "GroupModuleID");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Progression");

            migrationBuilder.DropTable(
                name: "TimeTable");

            migrationBuilder.DropTable(
                name: "Student");

            migrationBuilder.DropTable(
                name: "Task");

            migrationBuilder.DropTable(
                name: "GroupModule");

            migrationBuilder.DropTable(
                name: "Group");

            migrationBuilder.DropTable(
                name: "Module");

            migrationBuilder.DropTable(
                name: "Batch");
        }
    }
}
