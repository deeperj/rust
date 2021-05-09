import { Injectable } from '@angular/core';
import { MatSnackBar } from '@angular/material/snack-bar';
import { GroupModule } from '../models/GroupModule';

@Injectable({
  providedIn: 'root'
})
export class DebugService{
  constructor(
    private _snackBar: MatSnackBar, 
  ){}

info(msg:string, duration:number=1500){
      this._snackBar.open(msg);
      setTimeout(()=>this._snackBar.dismiss(), duration);
    }
}