import { Component, Input, OnInit } from '@angular/core';
import { Rpag, RPAGType } from 'src/app/models/enums';
import { Progress } from 'src/app/models/ui/Progress';
import { DomainService } from 'src/app/services/domain.service';
import { UpdateProgress } from 'src/app/store/progress.actions';

@Component({
  selector: 'app-all-assessment',
  templateUrl: './all-assessment.component.html',
  styleUrls: ['./all-assessment.component.css']
})
export class AllAssessmentComponent implements OnInit {

  @Input() attRep!: number;
  displayPivot: any[] =[];
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','RPAG','Attendance','Formative','Summative'];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  assessment!: Progress;
  constructor(
    public rootsvc : DomainService
  ) { }

  ngOnInit(): void {
    this.rootsvc.progress.subscribe(d=>this.assessment=d[this.attRep]);
    if(this.displayedColumns){
      this.rootsvc.pivotReady.subscribe(data=>{
        let len:number=0;
        this.rootsvc.progress.subscribe(d=>len=d.length);
        if(data==len-1){
          this.rootsvc.dbg.info("Items loaded");
          this.updatePivot();
        }
      });
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

  //Object.keys(a).forEach(key => console.log(key));
  updatePivot(){
    this.displayPivot=this.getData();
    this.columnsToDisplay = this.displayedColumns.slice();
  }

  getData(){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    return this.assessment.studentProgress.map((c,i)=>{
        this.rootsvc.store.dispatch(new UpdateProgress({
          gmid: this.attRep,
          studIdx:c.studentID,
          rpagType:RPAGType.Refresh,
          progressions:[],
        }));
        let v1= ({
        SN: i+1,
        StudentUniID:c.student?'U'+c.student.uniCode:'',
        Student: c,
        LastName: c.student?c.student.lastName:'',
        OtherNames: c.student?c.student.otherNames:'',
        RPAG: c.summaryScore,
        RPAGs: c.summaryRpag,
        Attendance: c.attendanceScore,
        Formative: c.formativeScore,
        Summative: c.summativeScore,
        SRPAG: c.summativeRpag,
        ARPAG: c.attendanceRpag,
      });
      return v1;
    });
  }

  getRpag(column:string,value:Rpag,arpag:Rpag, srpag:Rpag){

    switch(column){
      case 'RPAG':
        return this.rootsvc.rpag(value);
      case 'Attendance':
        return this.rootsvc.rpag(arpag);
      case 'Summative':
        return this.rootsvc.rpag(srpag);
      default:
        // console.log('here-black')
        return ""
        break;
    }
  }
}
