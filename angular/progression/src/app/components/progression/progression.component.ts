import { Component, OnInit } from '@angular/core';
import * as moment from 'moment';
import { Progression } from 'src/app/models/Progression';
import { Student } from 'src/app/models/Student';
//import { Console } from 'node:console';
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
  constructor( 
    private dbg: DebugService, 
    public rootsvc : AttendanceService) 
    { 
      this.getAttendance();
    }

  ngOnInit(): void {
  }
  
  registerContext_NOT_USED():void{
      const card = document.querySelector('mat-list-option');

      card?.addEventListener('dblclick', e=> {
        console.log('i just got double clicked');
        this.dbg.info("i just got clicked too!");
      });      

  }
  getAttendance() {
    //throw new Error('Method not implemented.');
    this.rootsvc.getAttendanceStudents()
    .subscribe( data => {
      this.rootsvc.groupMods=data;
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
            }
            )},
            )
          })
        )
      });
    });
    this.dbg.info(" items loaded!");
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

  onRightClick(){
    this.dbg.info("can i help?");
    console.log('right-clicked');
  }

  onAttendanceDone($event:any, modAttendance:Progression[]){
    //let today: number = Date.now();
    const today = moment().format('YYYY-MM-DD hh:mm:ss');
    let attProgressions:Progression[] = JSON.parse(JSON.stringify(modAttendance));
    attProgressions.forEach(att=>{
      att.dueDate=today;
      att.student=null;
      delete att.progressionId;
    })
    this.rootsvc.addAttendance(attProgressions).subscribe(data=>{
      console.log(data);
      this.dbg.info(data.count+" attendances saved!");
    })
  }
}

