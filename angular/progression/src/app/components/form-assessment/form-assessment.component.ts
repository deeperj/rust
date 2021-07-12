import { Component, Input, OnInit } from '@angular/core';
import { RPAGType } from 'src/app/models/enums';
import { ModuleTask } from 'src/app/models/ModuleTask';
import { Progression } from 'src/app/models/Progression';
import { Progress, ProgressRecord } from 'src/app/models/ui/Progress';
import { DomainService } from 'src/app/services/domain.service';

@Component({
  selector: 'app-form-assessment',
  templateUrl: './form-assessment.component.html',
  styleUrls: ['./form-assessment.component.css']
})
export class FormAssessmentComponent implements OnInit {

  @Input() attRep!: number;
  displayPivot: any[] =[];
  formatives: Progression[] = [];
  extraHeaders: string[]=[];
  sumTasks: ModuleTask[]=[];
  displayedColumns: string[] = ['SN','StudentUniID','LastName','OtherNames','Formative',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  assessment!: Progress;
  constructor(
    public rootsvc : DomainService
  ) { }

  ngOnInit(): void {
    this.rootsvc.progress.subscribe(d=>this.assessment=d[this.attRep]);
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

  updateScore(sprog:(Progression & ProgressRecord),value:string, hdr:string) {
    const val:string|null=prompt("Enter score:");
    let score:number =Number.parseFloat(val?val:'0');
    const v1:ModuleTask|undefined=this.sumTasks.find(x=>x.taskName.startsWith(hdr));
    let prog:Progression|null=null;
    if(value==="--" && v1 && val){
      this.rootsvc.dbg.info("Saving new score...");
      prog={
        moduleTaskID: v1.moduleTaskID,
        studentID: sprog.studentID,
        taskAssessment: score,
        completed: true,
        dueDate: v1.dueDate?v1.dueDate:'',
        comments: '',
      }
      this.rootsvc.addAssessment(prog).subscribe(data=>
      {
        this.rootsvc.dbg.info("Score "+(data?"has been added!":"was not added!"));
        this.formatives.push(data);
        data.task=v1;
        sprog.formatives.push(data);
        this.updatePivot();
      });
      return;
    }else this.rootsvc.dbg.info("Nothing done");
    const nscore:number=Number.parseFloat(val?val:'-1');
    if(val && nscore!==-1){
      //update
      const v2:Progression|undefined=sprog.formatives.find(x=>{
        return x.task?.taskName.startsWith(hdr)});
      const v3:Progression|undefined=JSON.parse(JSON.stringify(v2));
      if(v2 && v3 && v3.progressionID){
        v3.taskAssessment=nscore;
        v2.taskAssessment=nscore;
        delete v3.task;
        this.rootsvc.editAssessment(v3.progressionID,v3).subscribe(data=>{
          this.rootsvc.dbg.info("Score update "+(data?"complete!":"was not done!"));
          // console.log(v3);
          // console.log(sprog.formatives);
          // console.log(v2);
          this.updatePivot();
          return;
        })
      }
    }else this.rootsvc.dbg.info("Nothing done");
  }

  initializeData()   {
    const modid=this.assessment.groupModule.module.moduleID;
    const grpid=this.assessment.groupModule.group.groupID;
    this.rootsvc.getSumTasksByModule(modid, RPAGType.Formative)
    .subscribe( data => {
      this.sumTasks=data;
    //console.log(modid,grpid,this.attRep);
      this.extraHeaders=data.map(c=>c.taskName.split(' ')[0]);
      this.rootsvc.getSummativesByGroup(modid,grpid, RPAGType.Formative)
      .subscribe( data => {
        this.formatives = data;
        // this.extraHeaders =this.formatives.map(c=>c.task?c.task.taskName.split(' ')[0]:'NotFound')
        //                                   .filter((value, index, self) => self.indexOf(value) === index);
        this.displayedColumns=['SN','StudentUniID','LastName','OtherNames','Formative',...this.extraHeaders];
        this.assessment.studentProgress.forEach((sprog,ridx)=>{
          sprog.formatives=this.formatives.filter(prog=>prog.studentID===sprog.studentID)
        });
        this.updatePivot();
        this.columnsToDisplay = this.displayedColumns.slice();
      } );
    } );
  }

  //Object.keys(a).forEach(key => console.log(key));
  updatePivot(){
    this.displayPivot=this.getData();
  }
  getData(){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el:{[k:string]:string} = {};
    this.extraHeaders.forEach(v=>{el={...el,...{[v]:'** '}}})
    return this.assessment.studentProgress.map((c,i)=>{
      const formative:number = c.formatives.reduce((acc,curr)=>acc+curr.taskAssessment,0)/this.extraHeaders.length
      let v1= ({
        SN: i+1,
        StudentUniID:c.student?'U'+c.student.uniCode:'',
        Student: c,
        LastName: c.student?c.student.lastName:'',
        OtherNames: c.student?c.student.otherNames:'',
        Formative: formative.toFixed(2)
      });
      this.extraHeaders.forEach((hdr,j)=>{
        //console.log(theDate);
        const v2:Progression|undefined=c.formatives.find(x=>{
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
