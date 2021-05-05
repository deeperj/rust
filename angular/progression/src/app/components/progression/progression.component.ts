import { Component, OnInit } from '@angular/core';
import { Progression } from 'src/app/models/Progression';
import { Student } from 'src/app/models/Student';
//import { Console } from 'node:console';
import { GroupModule } from '../../models/GroupModule';
import { Attendance } from '../../models/ui/Attendance';
import { AttendanceService } from '../../services/attendance.service';
import { DebugService } from '../../services/debug.service';

@Component({
  selector: 'app-progression',
  templateUrl: './progression.component.html',
  styleUrls: ['./progression.component.css']
})
export class ProgressionComponent implements OnInit {
  attendance: Attendance[]=[];
  constructor(private debugService: DebugService, private attendanceUI : AttendanceService) { }

  ngOnInit(): void {
    this.getAttendance();
  }
  getAttendance() {
    //throw new Error('Method not implemented.');
    this.attendanceUI.getAttendanceStudents()
    .subscribe( data => {
      data.map((gmod, i) => {
        this.attendance.push(
          ({
            groupModuleId: gmod.id,
            groupNumber:gmod.group.groupNumber,
            moduleName:gmod.module.moduleName,
            students: gmod.group.students.map(stud=>{
              return ({
              progressionId: null,
              moduleTaskId: 1,
              studentId: stud.id,
              taskAssessment: 0,
              completed: false,
              dueDate: "",
              comments: "",
              task: null,
              student: stud
            })})
          })
        )
      });
      //console.log(this.attendance[0].students[0].student);
    });

  }

  studName(stud:Student):string{
    return stud.lastName.concat(' '+stud.otherNames);
  }

  onSelectionChange($event: any, studarr:Progression[]){
    let prog=studarr.find(a=>{return a.studentId===$event.option.value.id});
    if(prog){
      prog.completed=$event.option.selected;
      prog.taskAssessment=prog.completed?100:0
    }
  }
}
