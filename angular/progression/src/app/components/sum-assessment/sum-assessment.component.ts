import { Component, OnInit, Input } from '@angular/core';
import * as moment from 'moment';
import { Progression } from 'src/app/models/Progression';
import { Progress } from 'src/app/models/ui/Progress';
import { AssessmentService } from 'src/app/services/assessment.service';
import { DebugService } from 'src/app/services/debug.service';

@Component({
  selector: 'app-sum-assessment',
  templateUrl: './sum-assessment.component.html',
  styleUrls: ['./sum-assessment.component.css']
})
export class SumAssessmentComponent implements OnInit {

  @Input() attRep!: number;
  displayPivot: any[] =[];
  summatives: Progression[] = [];
  extraHeaders: string[]=[];
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','Summative',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  assessment!: Progress;
  constructor(
    public rootsvc : AssessmentService
  ) { }

  ngOnInit(): void {
    this.assessment=this.rootsvc.progress[this.attRep];
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
    const modid=this.assessment.groupModule.module.moduleID;
    const grpid=this.assessment.groupModule.group.groupID;
    this.rootsvc.getSummativesByModule(modid,grpid)
    .subscribe( data => {
      this.summatives = data;
      this.extraHeaders =this.summatives.map(c=>c.task?c.task.taskName.split(' ')[0]:'NotFound')
                                        .filter((value, index, self) => self.indexOf(value) === index);
      this.displayedColumns=['SN','StudentUniID','LastName','OtherNames','Attendance',...this.extraHeaders];
      this.getStudentAttendance(modid);
      setTimeout(() => {
        this.displayPivot=this.getData();
        // console.log(this.attendancePivot);
      }, 4000);
        this.columnsToDisplay = this.displayedColumns.slice();
    } );
  }

  getStudentAttendance(modid:number){
  }
  //     
  //Object.keys(a).forEach(key => console.log(key));

  getData(){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el:{[k:string]:string} = {};
    this.theDates.forEach(v=>{el={...el,...{[v]:'** '}}})
    return this.assessment.progressRecords.map((c,i)=>{
      let v1= ({
        SN: i+1,
        StudentUniID:c.student?'U'+c.student.uniCode:'',
        LastName: c.student?c.student.lastName:'',
        OtherNames: c.student?c.student.otherNames:'',
        Attendance: c.score
      });
      // console.log(c.attendance.length);
      return {...v1,...el};
    });
  }

}
