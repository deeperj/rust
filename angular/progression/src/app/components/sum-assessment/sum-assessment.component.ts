import { Component, OnInit, Input } from '@angular/core';
import { ModuleTask } from 'src/app/models/ModuleTask';
import { Progression } from 'src/app/models/Progression';
import { Progress } from 'src/app/models/ui/Progress';
import { DomainService } from 'src/app/services/domain.service';

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
  sumTasks: ModuleTask[]=[];
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','Summative',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  assessment!: Progress;
  constructor(
    public rootsvc : DomainService
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
    this.rootsvc.getSumTasksByModule(modid)
    .subscribe( data => {
      this.sumTasks=data;
      this.extraHeaders=data.map(c=>c.taskName.split(' ')[0]);
      this.rootsvc.getSummativesByGroup(modid,grpid)
      .subscribe( data => {
        this.summatives = data;
        // this.extraHeaders =this.summatives.map(c=>c.task?c.task.taskName.split(' ')[0]:'NotFound')
        //                                   .filter((value, index, self) => self.indexOf(value) === index);
        this.displayedColumns=['SN','StudentUniID','LastName','OtherNames','Summative',...this.extraHeaders];
        this.assessment.studentProgress.forEach((sprog,ridx)=>{
          sprog.summatives=this.summatives.filter(prog=>prog.studentId===sprog.studentId)
        });
        this.displayPivot=this.getData();
        this.columnsToDisplay = this.displayedColumns.slice();
      } );
    } );
  }

  //Object.keys(a).forEach(key => console.log(key));

  getData(){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el:{[k:string]:string} = {};
    this.extraHeaders.forEach(v=>{el={...el,...{[v]:'** '}}})
    return this.assessment.studentProgress.map((c,i)=>{
      let v1= ({
        SN: i+1,
        StudentUniID:c.student?'U'+c.student.uniCode:'',
        LastName: c.student?c.student.lastName:'',
        OtherNames: c.student?c.student.otherNames:'',
        Summative: c.summatives.reduce((acc,curr)=>acc+curr.taskAssessment,0)/this.extraHeaders.length
      });
      this.extraHeaders.forEach((hdr,j)=>{
        //console.log(theDate);
        const v2:Progression|undefined=c.summatives.find(x=>{
          // console.log(x.dueDate,theDate);
          return x.task?.taskName.startsWith(hdr)});
        let v:number = v2?v2.taskAssessment:-1;
        const assessment:string=v==-1?"--":v.toFixed(2);
        el[hdr]=assessment;
      })
      return {...v1,...el};
    });
  }

}
