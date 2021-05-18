import { Component, OnInit, Input, EventEmitter, Output } from '@angular/core';
import * as moment from 'moment';
import { Attendance } from 'src/app/models/ui/Attendance';
import { AttendanceService } from 'src/app/services/attendance.service';
import { DebugService } from 'src/app/services/debug.service';

@Component({
  selector: 'app-attendance-report',
  templateUrl: './attendance-report.component.html',
  styleUrls: ['./attendance-report.component.css']
})
export class AttendanceReportComponent implements OnInit {
  @Input() attRep!: number;
  attendancePivot: any[] =[];
  theDates2: string[] = [];
  theDates: string[] = [];
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','Attendance',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  attendance!: Attendance;
  constructor(
    private dbg: DebugService, 
    public rootsvc : AttendanceService
  ) { }

  ngOnInit(): void {
    this.attendance=this.rootsvc.attendance[this.attRep];
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
      this.theDates=this.theDates.map(c=>moment(c).format('MMM_DD_HHmmss'))
      this.displayedColumns=['SN','StudentUniID','LastName','OtherNames','Attendance',...this.theDates];
      this.getStudentAttendance(modid);
      // this.rootsvc.pivotReady.subscribe(()=>{
      //   this.rootsvc.attendancePivot=this.getData();
      // });
      setTimeout(() => {
        this.attendancePivot=this.getData();
        // console.log(this.attendancePivot);
      }, 4000);
        this.columnsToDisplay = this.displayedColumns.slice();
    } );
  }  

  getStudentAttendance(modid:number){
    this.attendance.students.forEach((attRec,ridx)=>{
      this.rootsvc.getStudAttendanceScoreByModule(attRec.studentId,modid).subscribe(data=>{
        attRec.attendanceScore=(data/this.theDates.length).toFixed(2);
        attRec.rpag=this.rootsvc.getRpag(Number.parseFloat(attRec.attendanceScore))
      });
    });
  }
  //     
  //Object.keys(a).forEach(key => console.log(key));

  getData(){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el:{[k:string]:string} = {};
    this.theDates.forEach(v=>{el={...el,...{[v]:'*  '}}})
    return this.attendance.students.map((c,i)=>{
      let v1= ({
        SN: i+1,
        StudentUniID:c.student?'U'+c.student.uniCode:'',
        LastName: c.student?c.student.lastName:'',
        OtherNames: c.student?c.student.otherNames:'',
        Attendance: c.attendanceScore
      });
      // console.log(c.rpag);
      this.theDates.forEach((theDate,i)=>{
        const v:number=c.attendance[i].taskAssessment;
        const attendance:string=v==100?"Y":v==0?"N":"NN";
        el[theDate]=attendance;
      })
      return {...v1,...el};
    });
  }
}
