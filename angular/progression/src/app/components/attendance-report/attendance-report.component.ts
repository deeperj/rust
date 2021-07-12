import { Component, OnInit, Input, EventEmitter, Output, OnDestroy } from '@angular/core';
import * as moment from 'moment';
import { takeWhile } from 'rxjs/operators';
import { RPAGType } from 'src/app/models/enums';
import { Progression } from 'src/app/models/Progression';
import { Progress } from 'src/app/models/ui/Progress';
import { DomainService } from 'src/app/services/domain.service';
import { UpdateProgress } from 'src/app/store/progress.actions';

@Component({
  selector: 'app-attendance-report',
  templateUrl: './attendance-report.component.html',
  styleUrls: ['./attendance-report.component.css']
})
export class AttendanceReportComponent implements OnInit, OnDestroy {
  @Input() attRep!: number;
  progress: Progression[] = [];
  attendancePivot: any[] =[];
  theDates2: string[] = [];
  theDates: string[] = [];
  aFmt: string='ddDDMMM';
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','Attendance',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  attendance!: Progress;
  alive: boolean = true
  ngOnDestroy(): void {
    this.alive = false
  }
  constructor(
    public rootsvc : DomainService
  ) { }

  ngOnInit(): void {
    this.rootsvc.progress.pipe(takeWhile(() => this.alive)).subscribe(d=>this.attendance=d[this.attRep]);
    if(this.displayedColumns){
      this.initializeData();
    }
  }

  getTitle(col:string){
    if(col.startsWith('#')){
      const i:number=Number.parseInt(col.split('#')[1]);
      return moment(this.theDates2[i-1]).format(this.aFmt)
    }
    return 'hi';
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
    .pipe(takeWhile(() => this.alive)).subscribe( data => {
      this.theDates2 = data;
      this.theDates=this.theDates2.map((c,i)=>'#'+(i+1));
      this.displayedColumns=['SN','StudentUniID','LastName','OtherNames','Attendance',...this.theDates];
      this.getStudentAttendance(modid);
      this.columnsToDisplay = this.displayedColumns.slice();
    });
  }  

  getStudentAttendance(modid:number){
    let counter:number=0;
    this.attendance.studentProgress.forEach((attRec,ridx)=>{
      // console.log('counter=',counter,'ridx=',ridx);
      this.rootsvc.getStudAttendanceByModule(attRec.studentID,modid).pipe(takeWhile(() => this.alive)).subscribe(data=>{
        this.rootsvc.store.dispatch(new UpdateProgress({
          gmid: this.attRep,
          studIdx:attRec.studentID,
          rpagType:RPAGType.Attendance,
          progressions:data,
          // rootsvc:this.rootsvc,
          doRpag: true
        }))
        counter++;
        if(counter==this.attendance.studentProgress.length){
          // console.log('counter=',counter,'ridx=',ridx,this.attRep);
          this.attendancePivot=this.getData();
          this.rootsvc.pivotReady.next(this.attRep);  
        }
      });
    });
  }
  //     
  //Object.keys(a).forEach(key => console.log(key));

  getData(){
    let el:{[k:string]:string} = {};
    this.theDates.forEach(v=>{el={...el,...{[v]:'** '}}})
    return this.attendance.studentProgress.map((c,i)=>{
      // c.attendanceScore=c.attendance.length>0?c.attendance.map(x=>x.taskAssessment).reduce((accumulator, currentValue) => accumulator + currentValue).toFixed(2):'0'
      // const score=Number.parseFloat(c.attendanceScore?c.attendanceScore:'0')/c.attendanceCount;
      // c.attendanceScore=score.toFixed(2);
      // c.attendance.sort((a,b)=>Date.parse(a.dueDate.toString())-Date.parse(b.dueDate.toString()));
      // c.attendanceRpag=this.rootsvc.getAttRpag(Number.parseFloat(c.attendanceScore), c)
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
        const label:string='#'+(j+1);//moment(theDate).format(this.aFmt);
        el[label]=attendance;
      })
      return {...v1,...el};
    });
  }
} 
