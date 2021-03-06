import { Component, OnDestroy, OnInit, ViewChild } from '@angular/core';
import { MatMenuTrigger } from '@angular/material/menu';
import * as moment from 'moment';
import { Progression } from 'src/app/models/Progression';
import { Student } from 'src/app/models/Student';
import { MisAttendance, Rpag } from '../../models/enums';
import { DomainService } from '../../services/domain.service';
import { DebugService } from '../../services/debug.service';
import { NewStudent } from 'src/app/models/ui/NewStudent';
import { GroupModule } from 'src/app/models/GroupModule';
import { ModEmailStatus } from 'src/app/models/ui/Progress';
import { AddProgress } from 'src/app/store/progress.actions';
import { takeWhile } from 'rxjs/operators';

@Component({
  selector: 'app-progression',
  templateUrl: './progression.component.html',
  styleUrls: ['./progression.component.css']
})
export class ProgressionComponent implements OnInit, OnDestroy {
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

  selectAll:boolean=false;
  dateSet:boolean=false;
  today:string="";
  alive: boolean = true
  ngOnDestroy(): void {
    this.alive = false
  }

  constructor( 
    private dbg: DebugService, 
    public rootsvc : DomainService) 
    { 
      [this.MALEFT,this.MALATE,this.MALL,this.MACA,this.MACO] =this.matmp;
      this.getAttendance();
    }

  ngOnInit(): void {
  }
  
  getAttendance() {
    //throw new Error('Method not implemented.');
    this.rootsvc.getAttendanceStudents()
    .pipe(takeWhile(() => this.alive)).subscribe( data => {
      data.map((gmod, i) => {
        this.rootsvc.store.dispatch(new AddProgress(
          {
            groupModule: gmod,
            groupNumber:gmod.group.groupNumber,
            moduleName:gmod.module.moduleName,
            studentProgress: gmod.group.students.map(stud=>{
              return ({
                progressionID: null,
                moduleTaskID: 1,
                studentID: stud.id,
                taskAssessment: 0,
                completed: false,
                dueDate: "",
                comments: "",
                task: null,
                student: stud,
                attendance: [],
                summatives: [],
                formatives: [],
                attendanceScore: null,
                attendanceCount: 0,
                attendanceRpag: null,
                formativeScore: null,
                summativeScore: null,
                summaryScore: null,
                summativeRpag: null,
                summaryRpag: null,
              }
            )},
            )
          })
        );
        // this.initializeAttendance(gmod);
      });
   });
  }
  studName(stud:Student):string{
    return stud.lastName.concat(' '+stud.otherNames);
  }

  onSelectionChange($event: any, studarr:Progression[]){
    let prog=studarr.find(a=>{return a.studentID===$event.option.value.id});
    if(prog){
      prog.completed=$event.option.selected;
      prog.taskAssessment=prog.completed?100:0
    }
  }

  toggleSelectAll(studarr:Progression[]){
    this.selectAll=!this.selectAll;
    studarr.forEach(a=>{
      a.completed=this.selectAll;
    });
  }

  comment(midx:number, idx:number, type:MisAttendance){
    //console.log(this.attendance[idx]);
    //this.dbg.info(type.toString());
    let stud:any=null;
    this.rootsvc.progress.pipe(takeWhile(() => this.alive)).subscribe(d=>stud=d[midx].studentProgress[idx]);
    stud.completed=true;
    switch(type){
      case MisAttendance.Late:
        stud.comments=" Attended late at "+moment().format("HH:mm:ss");
        stud.taskAssessment=50;
        break;
      case MisAttendance.Left:
        stud.comments="  Left early at "+moment().format("HH:mm:ss");
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
          this.dbg.info("Invalid Comment Type");
          return;
    }this.dbg.info("update complete!");
  }

  onAdmin(){
    window.location.href='http://localhost:5000/Students';
    // window.location('https://localhost:5001')window.location.href = "mailto:address@dmail.com";
  }
//window.location.href = 'mailto:address@dmail.com?subject=Hello there&body=This is the body';

  email(students:Progression[],gm:GroupModule){
    //let today: number = Date.now();
    const selection:Progression[]=students.filter(c=>c.completed);
    if(selection.length==0){
      this.dbg.info("nothing to do");
      return;
    }
    let mailto="mailto:";
    selection.forEach((stud,i)=>{
        mailto=mailto.concat('u'+stud.student?.uniCode+"@unimail.hud.ac.uk,");
        if(i===selection.length-1)mailto=mailto.concat('?bcc=i.alamina2@hud.ac.uk&subject=Attendance&cc=A.Matani@hud.ac.uk,isc@hud.ac.uk,'+gm.group.p2PCoach);
    });
    window.location.href = mailto;
  }

  sendWeekly(gm:GroupModule){
    const pass:string|null=prompt("Enter Password");
    if(pass){
      const sweekly:ModEmailStatus={
        password: pass,
        sendToday: true,
        gMID:gm.id
      }
      this.rootsvc.sendWeeklyReminder(sweekly).pipe(takeWhile(() => this.alive)).subscribe(data=>{
        console.log(data);
        this.rootsvc.dbg.info("Weekly reminder sent");
      })
    }else this.rootsvc.dbg.info("Nothing done!");
  }

  onAttendanceDone(modAttendance:Progression[]){
    //let today: number = Date.now();
    this.today = moment().format('YYYY-MM-DD HH:mm:ss');
    this.dateSet=true
    let attProgressions:Progression[] = JSON.parse(JSON.stringify(modAttendance));
    attProgressions.forEach(att=>{
      att.dueDate=this.today;
      att.student=null;
      delete att.progressionID;
    })
    this.rootsvc.addAttendance(attProgressions).pipe(takeWhile(() => this.alive)).subscribe(data=>{
      this.dbg.info(data.count+" attendance(s) saved!");
      this.selectAll=true;
      this.toggleSelectAll(modAttendance);
    })
  }


  onUpdate(modAttendance:Progression[]){
    const all:Progression[]=modAttendance.filter(c=>c.completed);
    if(all.length==0 || !this.dateSet){
      this.dbg.info("nothing to do");
      return;
    }
    let attProgressions:Progression[] = JSON.parse(JSON.stringify(all));
    attProgressions.forEach(att=>{
      att.dueDate=this.today;
      att.student=null;
      delete att.progressionID;
    })
    this.rootsvc.editAttendance(attProgressions).pipe(takeWhile(() => this.alive)).subscribe(data=>{
      this.dbg.info(data.count+" attendance(s) updated!");
      // window.location.reload(); 
      this.selectAll=true;
      this.toggleSelectAll(modAttendance);
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
    students.forEach(csv=>{
      newStuds.push(({
        groupId :Number.parseInt(csv[0]),
        sgCode: null,
        uniCode: csv[3],
        lastName: csv[1],
        otherNames: csv[2]
      }))
    });
    this.rootsvc.uploadStudents(newStuds).pipe(takeWhile(() => this.alive)).subscribe(data=>{
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

