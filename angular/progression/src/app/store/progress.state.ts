import { State, Action, StateContext, Selector } from '@ngxs/store';
import { Progress } from '../models/ui/Progress';
import { AddProgress, UpdateFormative, UpdateSummative } from './progress.actions';
// import { produce } from 'immer'
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

  // Section 4
  @Selector()
  static getProgress(state: ProgressionStateModel) {
      return state.progress
  }

  // Section 5
  @Action(AddProgress)
  add({getState, patchState }: StateContext<ProgressionStateModel>, { payload }:AddProgress) {
      const state = getState();
      patchState({
          progress: [...state.progress, payload]
      })
  }

  // @Action(UpdateFormative)
  // add({getState, patchState }: StateContext<ProgressionStateModel>, { payload }:UpdateFormative  ) {
  //     const state = getState();
  //     patchState({
  //         progress: [...state.progress, payload]
  //     })
  // }

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