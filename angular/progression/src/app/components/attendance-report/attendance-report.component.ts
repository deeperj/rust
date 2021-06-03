import { Component, OnInit, Input, EventEmitter, Output } from '@angular/core';
import * as moment from 'moment';
import { Progression } from 'src/app/models/Progression';
import { Progress } from 'src/app/models/ui/Progress';
import { DomainService } from 'src/app/services/domain.service';

@Component({
  selector: 'app-attendance-report',
  templateUrl: './attendance-report.component.html',
  styleUrls: ['./attendance-report.component.css']
})
export class AttendanceReportComponent implements OnInit {
  @Input() attRep!: number;
  errorloading:boolean=true;
  attendancePivot: any[] =[];
  theDates2: string[] = [];
  theDates: string[] = [];
  aFmt: string='ddDDMMM';
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','Attendance',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  attendance!: Progress;
  constructor(
    public rootsvc : DomainService
  ) { }

  ngOnInit(): void {
    this.attendance=this.rootsvc.progress[this.attRep];
    if(this.displayedColumns){
      this.initializeData();
    }
  }


  toggleColumn(col:string) {                             
    this.toggle=!this.toggle
    if (this.toggle) {
      this.columnsToDisplay=[col];
    }else{
      this.columnsToDisplay=this.displayedColumns.slice();
    }
  }
  initializeData()   {
    const modid=this.attendance.groupModule.module.moduleID;
    const grpid=this.attendance.groupModule.group.groupID;
    this.rootsvc.getAttendanceDates(modid,grpid)
    .subscribe( data => {
      this.theDates2 = data;
      this.theDates = data;
      this.theDates=this.theDates.map((c,i)=>(i+1)+'#'+moment(c).format(this.aFmt));
      this.displayedColumns=['SN','StudentUniID','LastName','OtherNames','Attendance',...this.theDates];
      this.getStudentAttendance(modid);
      // this.rootsvc.pivotReady.subscribe(()=>{
      //   this.attendancePivot=this.getData();
      // });
      setTimeout(() => {
        this.attendancePivot=this.getData();
        this.errorloading=false;
      }, 2500);
      setTimeout(() => {
        if(this.errorloading)
          this.rootsvc.dbg.info(" error loading items!");
        else
          this.rootsvc.dbg.info(" items loaded!");
      }, 3000);
        this.columnsToDisplay = this.displayedColumns.slice();
        //console.log(JSON.stringify(this.rootsvc.progress));
    } );
  }  

  getStudentAttendance(modid:number){
    let counter:number=0;
    this.attendance.studentProgress.forEach((attRec,ridx)=>{
      this.rootsvc.getStudAttendanceScoreByModule(attRec.studentID,modid).subscribe(data=>{
        //console.log(data);
        attRec.attendanceScore=data.toFixed(2);
      });
      this.theDates2.forEach((theDate,i)=>{
        // console.log(attRec.studentId+'_'+theDate);
        if (attRec.student?.startDate && attRec.student?.startDate <=theDate){
          this.rootsvc.getStudAttendanceByDate(attRec.studentID,theDate).subscribe(data=>{
            attRec.attendance?.push(data);
            attRec.attendanceCount++;
          });
        }
      });
      counter++;
      //console.log(counter,'ridx=',ridx,this.attendance.students.length,'attendance.length=',attRec.attendance.length,'attRep=',this.attRep);
      //if(counter==this.attendance.students.length)this.rootsvc.pivotReady.next();
});
  }
  //     
  //Object.keys(a).forEach(key => console.log(key));

  getData(){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el:{[k:string]:string} = {};
    this.theDates.forEach(v=>{el={...el,...{[v]:'** '}}})
    return this.attendance.studentProgress.map((c,i)=>{
      const score=Number.parseFloat(c.attendanceScore?c.attendanceScore:'0')/c.attendanceCount;
      c.attendanceScore=score.toFixed(2);
      c.attendance.sort((a,b)=>Date.parse(a.dueDate.toString())-Date.parse(b.dueDate.toString()));
      c.attendanceRpag=this.rootsvc.getRpag(Number.parseFloat(c.attendanceScore), c)
      let v1= ({
        SN: i+1,
        StudentUniID:c.student?'U'+c.student.uniCode:'',
        LastName: c.student?c.student.lastName:'',
        OtherNames: c.student?c.student.otherNames:'',
        Attendance: c.attendanceScore
      });
      // console.log(c.attendance.length);
      this.theDates2.forEach((theDate,j)=>{
        //console.log(theDate);
        const v2:Progression|undefined=c.attendance.find(x=>{
          // console.log(x.dueDate,theDate);
          return x.dueDate===theDate});
        let v:number = v2?v2.taskAssessment:-1;
        const attendance:string=v==-1?"--":(v==100?"Y":v==0?"N":"L");
        const label:string=(j+1)+'#'+moment(theDate).format(this.aFmt);
        el[label]=attendance;
      })
      return {...v1,...el};
    });
  }
} 
