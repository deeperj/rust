import { Component, OnInit, ViewChild, ElementRef, AfterViewInit } from '@angular/core';
import { MatMenuTrigger } from '@angular/material/menu';
import * as moment from 'moment';
import { Progression } from 'src/app/models/Progression';
import { Student } from 'src/app/models/Student';
//import { Console } from 'node:console';
import { MisAttendance, Rpag } from '../../models/enums';
import { AttendanceService } from '../../services/attendance.service';
import { DebugService } from '../../services/debug.service';
import { NewStudent } from 'src/app/models/ui/NewStudent';

@Component({
  selector: 'app-progression',
  templateUrl: './progression.component.html',
  styleUrls: ['./progression.component.css']
})
export class ProgressionComponent implements OnInit {
  @ViewChild("menu") menu!: MatMenuTrigger;
  matmp=[
    MisAttendance.Left,
    MisAttendance.Late,
    MisAttendance.LateNLeft,
    MisAttendance.Clear,
    MisAttendance.Comment
  ];
  MALEFT!:MisAttendance;
  MALATE!:MisAttendance;
  MALL!:MisAttendance;
  MACA!:MisAttendance;
  MACO!:MisAttendance;

  RpagG=Rpag.G;

  constructor( 
    private dbg: DebugService, 
    public rootsvc : AttendanceService) 
    { 
      [this.MALEFT,this.MALATE,this.MALL,this.MACA,this.MACO] =this.matmp;
      this.getAttendance();
    }

  ngOnInit(): void {
  }
  
  getAttendance() {
    //throw new Error('Method not implemented.');
    this.rootsvc.getAttendanceStudents()
    .subscribe( data => {
      data.map((gmod, i) => {
        this.rootsvc.attendance.push(
          ({
            groupModule: gmod,
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
              student: stud,
              attendance: [],
              attendanceScore: null,
              rpag: null
            }
            )},
            )
          })
        );
        // this.initializeAttendance(gmod);
      });
    });
    this.dbg.info(" items loaded!");
  }
  rpag(rpag:Rpag|null){
    //console.log(rpag);
    switch(rpag){
      case Rpag.R:
        return "red";
      case Rpag.P:
        return "purple";
      case Rpag.A:
        return "yellow";
      case Rpag.G:
        return "green";
      default:
        return "black";
    }
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
    let stud=this.rootsvc.attendance[midx].students[idx];
    stud.completed=true;
    switch(type){
      case MisAttendance.Late:
        stud.comments=" Attended late at "+moment().format("HH:mm:ss");
        stud.taskAssessment=50;
        break;
      case MisAttendance.Left:
        stud.comments="  Left late at "+moment().format("HH:mm:ss");
        stud.taskAssessment=50;
        break;
      case MisAttendance.LateNLeft:
        stud.comments+="\n Left early at "+moment().format("HH:mm:ss");
        stud.taskAssessment=25;
        break;
      case MisAttendance.Comment:
          let co = prompt("Enter Comment");
          stud.comments+=co;
          stud.completed=!stud.completed;
          console.log(stud.comments);
          break;
        default:
        stud.comments="";
      }
      this.dbg.info("update complete!");
  }

  onAdmin(){
    window.location.href='http://localhost:5000/Students';
    // window.location('https://localhost:5001')window.location.href = "mailto:address@dmail.com";
  }
//window.location.href = 'mailto:address@dmail.com?subject=Hello there&body=This is the body';

  email(students:Progression[]){
    //let today: number = Date.now();
    if(students.filter(c=>c.completed).length==0){
      this.dbg.info("nothing to do");
      return;
    }
    let mailto="mailto:";
    students.forEach((student,i)=>{
      if(student.completed){
        mailto=mailto.concat('u'+student.student?.uniCode+"@unimail.hud.ac.uk");
        if(i<students.length-1)mailto=mailto.concat(',');
      }
    });
    mailto=mailto.concat("?subject=Attendance");
    console.log("mail to ref:"+mailto);
    window.location.href = mailto;
  }

  onAttendanceDone($event:any, modAttendance:Progression[]){
    //let today: number = Date.now();
    const today = moment().format('YYYY-MM-DD HH:mm:ss');
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

