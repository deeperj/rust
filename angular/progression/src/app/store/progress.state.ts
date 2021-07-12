import { State, Action, StateContext, Selector } from '@ngxs/store';
import { Progress } from '../models/ui/Progress';
import { AddProgress, UpdateProgress } from './progress.actions';
import { produce } from 'immer'
import { RPAGType } from '../models/enums';
// import { AddTutorial, RemoveTutorial } from './../actions/tutorial.actions'

// Section 2
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
      patchState({
          progress: produce(state.progress,draft=>{
            let sprog = draft[payload.gmid].studentProgress.find(c=>c.studentID==payload.studIdx);
            if(sprog){
              switch(payload.rpagType){
                case RPAGType.Attendance:
                  sprog.attendance=payload.progressions
                  // payload.rootsvc.updateAttendance(sprog);
                  break;
                case RPAGType.Summative:
                  sprog.summatives=payload.progressions;
                  // payload.rootsvc.updateSummatives(sprog);
                  break;
                case RPAGType.Formative:
                  sprog.formatives=payload.progressions;
                  // payload.rootsvc.updateFormatives(sprog);
                  break;
                default:
                  break;
              } 
            }
          })
      })
  }

  // // Section 5
  // @Action(UpdateSummative)
  // add({getState, patchState }: StateContext<ProgressionStateModel>, { payload }:UpdateSummative) {
  //     const state = getState();
  //     patchState({
  //         progress: [...state.progress, payload]
  //     })
  // }

  // @Action(RemoveTutorial)
  // remove({getState, patchState }: StateContext<TutorialStateModel>, { payload }:RemoveTutorial) {
  //     patchState({
  //         tutorials: getState().tutorials.filter(a => a.name != payload)
  //     })
  // }

}