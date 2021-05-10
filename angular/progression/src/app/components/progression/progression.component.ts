import { Component, OnInit, ViewChild, ElementRef, AfterViewInit } from '@angular/core';
import { MatMenuTrigger } from '@angular/material/menu';
import * as moment from 'moment';
import { Progression } from 'src/app/models/Progression';
import { Student } from 'src/app/models/Student';
//import { Console } from 'node:console';
import { Attendance } from '../../models/ui/Attendance';
import { MisAttendance } from '../../models/enums';
import { AttendanceService } from '../../services/attendance.service';
import { DebugService } from '../../services/debug.service';
import { NullTemplateVisitor } from '@angular/compiler';
import { NewStudent } from 'src/app/models/ui/NewStudent';

@Component({
  selector: 'app-progression',
  templateUrl: './progression.component.html',
  styleUrls: ['./progression.component.css']
})
export class ProgressionComponent implements OnInit {
  @ViewChild("menu") menu!: MatMenuTrigger;
  attendance: Attendance[]=[];
  matmp=[MisAttendance.Left,MisAttendance.Late,MisAttendance.LateNLeft,MisAttendance.Clear];
  MALEFT!:MisAttendance;
  MALATE!:MisAttendance;
  MALL!:MisAttendance;
  MACA!:MisAttendance;

  constructor( 
    private dbg: DebugService, 
    public rootsvc : AttendanceService) 
    { 
      [this.MALEFT,this.MALATE,this.MALL,this.MACA] =this.matmp;
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

  comment(midx:number, idx:number, type:MisAttendance){
    //console.log(this.attendance[idx]);
    //this.dbg.info(type.toString());
    let stud=this.attendance[midx].students[idx];
    stud.completed=true;
    switch(type){
      case MisAttendance.Late:
        stud.comments=" Attended late at "+moment().format("hh:mm:ss");
        stud.taskAssessment=50;
        break;
      case MisAttendance.Left:
        stud.comments="  Left late at "+moment().format("hh:mm:ss");
        stud.taskAssessment=50;
        break;
      case MisAttendance.LateNLeft:
        stud.comments+="\n Left early at "+moment().format("hh:mm:ss");
        stud.taskAssessment=25;
        break;
      default:
        stud.comments="";
      }
      this.dbg.info("update complete!");
  }

  onAdmin(){
    window.location.href='http://localhost:5000/Students';
    // window.location('https://localhost:5001')
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
      // window.location.reload(); 
    })
  }

  public onFileChange(files:File[]){
    if(files && files.length > 0) {
      let file : File|null = files[0]; 
      let reader: FileReader = new FileReader();
      if(file){
        reader.readAsText(file);
        reader.onload = (e) => {
            let csv: string = reader.result as string;
            this.uploadStudents(this.rootsvc.CSVToArray(csv));
        }
      }
    }

  }
  public uploadStudents(students:string[][]){
    let newStuds:NewStudent[]=[];
    students.forEach(c=>{
      newStuds.push(({
        groupId :Number.parseInt(c[0]),
        sgCode: null,
        uniCode: c[3],
        lastName: c[1],
        otherNames: c[2]
      }))
    });
//    console.log(JSON.stringify(newStuds));
    this.rootsvc.uploadStudents(newStuds).subscribe(data=>{
      this.dbg.info(data.count + " Students Added!");
      console.log(data.count+ " students added")
    });
  }
  public changeListener_NOT_USED_BY_NATIVE_FILE($event:any){
    const files=$event.target.files;
    console.log(files);
    if(files && files.length > 0) {
      let file : File|null = files.item(0); 
      // console.log(file?.name);
      // console.log(file?.size);
      // console.log(file?.type);
      let reader: FileReader = new FileReader();
      if(file){
        reader.readAsText(file);
        reader.onload = (e) => {
            let csv: string = reader.result as string;
            console.log(csv);
        }
      }
    }
  }

}

