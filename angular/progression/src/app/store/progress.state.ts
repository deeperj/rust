import { State, Action, StateContext, Selector } from '@ngxs/store';
import { Progress, ProgressRecord } from '../models/ui/Progress';
import { AddProgress, UpdateProgress } from './progress.actions';
import { Rpag, RPAGType } from '../models/enums';
import { Progression } from '../models/Progression';
import { ProgressUpdate } from '../models/ui/NewStudent';

export class ProgressionStateModel {
    progress!: Progress[];
}

// Section 3
@State<ProgressionStateModel>({
    name: 'progress',
    defaults: {
      progress: []
    }
})


export class ProgressionState {

  @Selector()
  static getProgress(state: ProgressionStateModel) {
      return state.progress
  }

  @Action(AddProgress)
  add({getState, patchState }: StateContext<ProgressionStateModel>, { payload }:AddProgress) {
      const state = getState();
      patchState({
          progress: [...state.progress, payload]
      })
  }

  @Action(UpdateProgress)
  update({getState, patchState }: StateContext<ProgressionStateModel>, { payload }:UpdateProgress  ) {
      const state = getState();
      const patch = this.patch(state.progress,payload);
      patchState({
          progress: patch
      })
  }
  
  getRpag(score:number):Rpag{

    if(score>=70)
      return Rpag.G;
    else if(score <70 && score >=50)
      return Rpag.A;
    else if(score <50 && score >=40)
      return Rpag.P;
    else 
      return Rpag.R;
  }

  getAttRpag(score:number,student:(Progression & ProgressRecord)):Rpag{
    const aLag:number =this.attendanceLag(student);

    if(aLag>2 && aLag<10)
      return Rpag.P;
    else if(aLag>9)
      return Rpag.R;
    return this.getRpag(score);
  }

  attendanceLag(student:(Progression & ProgressRecord)):number{
    //console.log(JSON.stringify(student.attendance));
    let aLag:Progression[]=student.attendance.reverse();
    let lag:number=0;
    for(let i:number=0;i<aLag.length;i++){
      if(!aLag[i].completed)
        lag++;
      else
        return lag;
    }
    return lag;
  }

  getScore(scores:Progression[],depth:number=2){
    const arr=scores.map(c=>c.taskAssessment).sort((a,b)=>b-a).filter((v,i)=>i<depth);
    const val= arr.length>0?arr.reduce((a,b)=>a+b)/(arr.length>2?arr.length:2):0;
    console.log('getScore',(depth===2?'formative':'summative'),'=',val);
    return val;
  }

  updateFormatives(sprog:(Progression & ProgressRecord)){
    sprog.formativeScore=this.getScore(sprog.formatives).toFixed(2);
    // sprog.summaryScore=this.getSummaryScore(sprog).toFixed(2);
    // sprog.summaryRpag=this.getSRpag(sprog.summaryScore!);
    // console.log(sprog.formativeScore);
  }

  updateAttendance(c:(Progression & ProgressRecord)){
    c.attendanceCount=c.attendance.length;
    c.attendanceScore=c.attendance.length>0?c.attendance.map(x=>x.taskAssessment).reduce((accumulator, currentValue) => accumulator + currentValue).toFixed(2):'0'
    const score=Number.parseFloat(c.attendanceScore?c.attendanceScore:'0')/c.attendanceCount;
    c.attendanceScore=score.toFixed(2);
    c.attendance.sort((a,b)=>Date.parse(a.dueDate.toString())-Date.parse(b.dueDate.toString()));
    c.attendanceRpag=this.getAttRpag(Number.parseFloat(c.attendanceScore), c)
  }
  
  updateSummatives(sprog:(Progression & ProgressRecord)){
    sprog.summativeScore=this.getScore(sprog.summatives,4).toFixed(2);
    sprog.summativeRpag=this.getSRpag(sprog.summativeScore!);
    sprog.summaryScore =this.getSummaryScore(sprog).toFixed(2);
    sprog.summaryRpag =this.getSRpag(sprog.summaryScore!);

  }

  getAttendanceScore(scores:Progression[]){
    const arr=scores.map(c=>c.taskAssessment).sort((a,b)=>b-a).filter((v,i)=>i<4);
    return arr.length>0?arr.reduce((a,b)=>a+b)/arr.length:0;
  }

  getSummaryScore(sprog:(Progression & ProgressRecord)){
    const sum=Number.parseFloat(sprog.summativeScore?sprog.summativeScore:'0');
    const form=Number.parseFloat(sprog.formativeScore?sprog.formativeScore:'0');
    const att=Number.parseFloat(sprog.attendanceScore?sprog.attendanceScore:'0');
    const val =(sum+form+att)/3;
    console.log('summaryScore=',val,sum,form,att);
    return val;
  }

  getSRpag(sprog:string){
    const sum=Number.parseFloat(sprog?sprog:'0');
    return this.getRpag(sum);
  }

  ctr: number = 0
  
  patch(state: Progress[], payload:ProgressUpdate){
    let clone = state.slice();
    let sprog = clone[payload.gmid].studentProgress.find(c=>c.studentID==payload.studIdx);
    if(sprog){
      switch(payload.rpagType){
        case RPAGType.Attendance:
          console.log('attendance ..',this.ctr++);
          sprog.attendance=payload.progressions
          // this.updateAttendance(sprog);
          break;
        case RPAGType.Summative:
          console.log('summative ..',this.ctr++);
          sprog.summatives=payload.progressions;
          // this.updateSummatives(sprog);
          break;
        case RPAGType.Formative:
          console.log('formative ..',this.ctr++);
          sprog.formatives=payload.progressions;
          // this.updateFormatives(sprog);
          break;
        case RPAGType.Refresh:
          console.log('refresh ..',this.ctr++);
          this.updateAttendance(sprog);
          this.updateFormatives(sprog);
          this.updateSummatives(sprog);
          break;
        default:
          console.log('Attendance =',RPAGType.Attendance); 
          console.log('Formative =', RPAGType.Attendance);
          console.log('Summative =',RPAGType.Summative);
          console.log('Enrollment =',RPAGType.Enrollment);
          console.log('Inactive =',RPAGType.Inactive);
          console.log('Refresh =',RPAGType.Refresh);
          console.log('None =',RPAGType.None);
          console.log('RPag type =',payload.rpagType,'not implemented');
          break;
      } 
      // if(sprog.formativeScore && sprog.formativeScore.length>0)
      // console.log("formative score is ",clone[1].studentProgress.find(c=>c.studentID==8)!.formativeScore);
    }
    return clone;
  }



}